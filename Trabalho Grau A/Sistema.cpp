#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

Sistema::Sistema() : usuarioLogado(nullptr) {
    srand(time(0));
    cout << "Iniciando o sistema..." << endl;
    carregarFigurinhasMestre();
    carregarUsuarios();
    carregarTrocas();
    cout << "Sistema carregado com sucesso." << endl;

    layoutPaginas.push_back(Pagina(1, "Atacantes e Defensores", 1, 10));
    layoutPaginas.push_back(Pagina(2, "Meio-campistas", 11, 20));
}

Sistema::~Sistema() {
}

void Sistema::carregarFigurinhasMestre() {
    ifstream arquivo("figurinhas.csv");
    string linha;
    if (!arquivo.is_open()) {
        cerr << "Aviso: Nao foi possivel abrir o arquivo figurinhas.csv." << endl;
        return;
    }
    getline(arquivo, linha); 

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string numStr, nome, conteudo;
        getline(ss, numStr, ',');
        getline(ss, nome, ',');
        getline(ss, conteudo, ',');
        if (!numStr.empty()) {
            figurinhasMestre.emplace_back(stoi(numStr), nome, conteudo, 1);
        }
    }
    arquivo.close();
}

void Sistema::carregarUsuarios() {
    ifstream arquivo("usuarios.csv");
    string linha;
    if (!arquivo.is_open()) { return; }
    
    getline(arquivo, linha);
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string nome, senha;
        getline(ss, nome, ',');
        getline(ss, senha, ',');
        if (!nome.empty()){
            usuarios.emplace_back(nome, senha);
        }
    }
    arquivo.close();

    for (Usuario& usuario : usuarios) {
        carregarAlbumDoUsuario(usuario);
    }
}

void Sistema::carregarAlbumDoUsuario(Usuario& usuario) {
    ifstream arquivo(usuario.getNomeDeUsuario() + "_album.csv");
    if (!arquivo.is_open()) { return; }

    string linha;
    getline(arquivo, linha);

    vector<Figurinha> figurinhasDoUsuario;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string numStr, statusStr;
        getline(ss, numStr, ',');
        getline(ss, statusStr, ',');

        int numero = stoi(numStr);
        int status = stoi(statusStr);

        for (const auto& figMestre : figurinhasMestre) {
            if (figMestre.getNumero() == numero) {
                Figurinha figDoAlbum = figMestre;
                figDoAlbum.setStatus(status);
                figurinhasDoUsuario.push_back(figDoAlbum);
                break;
            }
        }
    }
    usuario.getAlbum().setFigurinhas(figurinhasDoUsuario);
    arquivo.close();
}

void Sistema::carregarTrocas() {
    ifstream arquivo("trocas.csv");
    string linha;
    if (!arquivo.is_open()) { return; }
    getline(arquivo, linha);

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string proponente, receptor, reqStr, dispStr, statusStr;
        getline(ss, proponente, ',');
        getline(ss, receptor, ',');
        getline(ss, reqStr, ',');
        getline(ss, dispStr, ',');
        getline(ss, statusStr, ',');

        if(!proponente.empty()){
            trocas.emplace_back(proponente, receptor, stoi(reqStr), stoi(dispStr), stoi(statusStr));
        }
    }
    arquivo.close();
}

void Sistema::salvarDados() {
    for (const auto& usuario : usuarios) {
        salvarAlbumDoUsuario(usuario);
    }
    salvarTrocas();
}

void Sistema::salvarAlbumDoUsuario(const Usuario& usuario) const {
    ofstream arquivo(usuario.getNomeDeUsuario() + "_album.csv");
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar o album de " << usuario.getNomeDeUsuario() << endl;
        return;
    }
    arquivo << "numero,status\n";
    for (const auto& fig : usuario.getAlbum().getFigurinhas()) {
        arquivo << fig.getNumero() << "," << fig.getStatus() << "\n";
    }
    arquivo.close();
}

void Sistema::salvarTrocas() const {
    ofstream arquivo("trocas.csv");
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar as trocas." << endl;
        return;
    }
    arquivo << "proponente,receptor,figRequerida,figDisponivel,status\n";
    for(const auto& troca : trocas) {
        arquivo << troca.nomeProponente << "," << troca.nomeReceptor << ","
                << troca.figurinhaRequerida << "," << troca.figurinhaDisponivel << ","
                << troca.status << "\n";
    }
    arquivo.close();
}

Usuario* Sistema::login(const string& nome, const string& senha) {
    for (auto& user : usuarios) {
        if (user.verificarLogin(nome, senha)) {
            usuarioLogado = &user;
            return usuarioLogado;
        }
    }
    return nullptr;
}

void Sistema::logout() {
    usuarioLogado = nullptr;
}

bool Sistema::criarNovoUsuario(const string& nome, const string& senha) {
    for (const auto& user : usuarios) {
        if (user.getNomeDeUsuario() == nome) {
            return false; 
        }
    }
    usuarios.emplace_back(nome, senha);
    
    ofstream arquivo("usuarios.csv", std::ios::app);
    if(arquivo.is_open()){
        arquivo << nome << "," << senha << "\n";
        arquivo.close();
    }
    return true;
}

Usuario* Sistema::getUsuarioLogado() { return usuarioLogado; }

Usuario* Sistema::getUsuarioPorNome(const string& nome) {
    for(auto& user : usuarios){
        if(user.getNomeDeUsuario() == nome){
            return &user;
        }
    }
    return nullptr;
}

void Sistema::abrirPacoteDeFigurinhas() {
    if (!usuarioLogado || figurinhasMestre.empty()) return;
    cout << "\nVoce abriu um pacote e conseguiu 3 novas figurinhas:" << endl;
    for (int i = 0; i < 3; ++i) {
        int indiceAleatorio = rand() % figurinhasMestre.size();
        Figurinha figPremiada = figurinhasMestre[indiceAleatorio];
        usuarioLogado->getAlbum().adicionarFigurinha(figPremiada);
    }
}

void Sistema::verAlbum() {
    if (!usuarioLogado) return;
    Album& album = usuarioLogado->getAlbum();

    cout << "\n--- Visualizando Album ---" << endl;
    for(const auto& pag : layoutPaginas){
        cout << "\nPagina " << pag.numero << ": " << pag.titulo << endl;
        for(int i = pag.minNro; i <= pag.maxNro; ++i){
            Figurinha* fig = album.getFigurinha(i);
            if(fig){ 
                if(fig->getStatus() == 1){ 
                    cout << "  [" << i << "] " << fig->getNome() << " - COLADA" << endl;
                } else {
                     cout << "  [" << i << "] " << fig->getNome() << " - (Opcao COLAR disponivel)" << endl;
                }
            } else { 
                 cout << "  [ X ] Figurinha " << i << " - Faltando" << endl;
            }
        }
    }
}

void Sistema::gerenciarColecao() {
    if (!usuarioLogado) return;
    Album& album = usuarioLogado->getAlbum();
    
    int opcao = 0;
    while(opcao != 5) {
        cout << "\n--- Gerenciar Colecao ---" << endl;
        cout << "Figurinhas nao coladas:" << endl;
        bool temNaoColada = false;
        for(const auto& fig : album.getFigurinhas()){
            if(fig.getStatus() != 1){
                fig.exibir();
                temNaoColada = true;
            }
        }
        if(!temNaoColada) {
            cout << "Nenhuma figurinha na colecao para gerenciar." << endl;
        }

        cout << "\n1. Colar Figurinha" << endl;
        cout << "2. Disponibilizar para troca" << endl;
        cout << "3. Propor troca de figurinhas" << endl;
        cout << "4. Revisar solicitacoes de troca" << endl;
        cout << "5. Voltar ao Menu Anterior" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int num;
                cout << "Digite o numero da figurinha para colar: ";
                cin >> num;
                Figurinha* fig = album.getFigurinha(num);
                if(fig && fig->getStatus() != 1){
                    fig->setStatus(1);
                    cout << "Figurinha " << num << " colada com sucesso!" << endl;
                } else {
                    cout << "Operacao invalida. Voce nao possui esta figurinha ou ela ja foi colada." << endl;
                }
                break;
            }
            case 2: {
                int num;
                cout << "Digite o numero da figurinha para disponibilizar para troca: ";
                cin >> num;
                Figurinha* fig = album.getFigurinha(num);
                if(fig && fig->getStatus() == 0){ 
                    fig->setStatus(2);
                    cout << "Figurinha " << num << " agora esta disponivel para trocas!" << endl;
                } else {
                    cout << "Operacao invalida. A figurinha precisa estar 'Na colecao'." << endl;
                }
                break;
            }
            case 3:
                proporTroca();
                break;
            case 4:
                revisarSolicitacoesDeTroca();
                break;
            case 5:
                cout << "Voltando..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    }
}

void Sistema::proporTroca() {
     if (!usuarioLogado) return;
     cout << "\n--- Propor Troca ---" << endl;
     
     cout << "Figurinhas disponiveis para troca (de outros usuarios):" << endl;
     bool disponiveis = false;
     for(auto& u : usuarios){
         if(u.getNomeDeUsuario() != usuarioLogado->getNomeDeUsuario()){
             for(const auto& fig : u.getAlbum().getFigurinhas()){
                 if(fig.getStatus() == 2){
                     cout << "  - Usuario: " << u.getNomeDeUsuario() << " oferece a figurinha Nro: " << fig.getNumero() << endl;
                     disponiveis = true;
                 }
             }
         }
     }

     if(!disponiveis){
         cout << "Nenhuma figurinha disponivel para troca no momento." << endl;
         return;
     }

     string parceiro;
     int figDesejada, figOferecida;
     cout << "\nDigite o nome do usuario com quem quer trocar: ";
     cin >> parceiro;
     cout << "Digite o numero da figurinha que voce DESEJA (a que o parceiro tem): ";
     cin >> figDesejada;
     cout << "Digite o numero da SUA figurinha que voce quer OFERECER em troca: ";
     cin >> figOferecida;

    Usuario* parceiroUsuario = getUsuarioPorNome(parceiro);

    if(parceiroUsuario == nullptr){
        cout << "Erro: Usuario parceiro nao encontrado." << endl;
        return;
    }

    if(parceiroUsuario->getNomeDeUsuario() == usuarioLogado->getNomeDeUsuario()){
       cout << "Erro: Voce nao pode propor uma troca com voce mesmo." << endl;
       return;
    }

    Figurinha* suaFigurinha = usuarioLogado->getAlbum().getFigurinha(figOferecida);
    if(suaFigurinha == nullptr){
        cout << "Erro: Voce nao possui a figurinha que esta oferecendo (Nro. " << figOferecida << ")." << endl;
        return;
    }
    
    if (suaFigurinha->getStatus() != 2) {
       cout << "Erro: Sua figurinha (Nro. " << figOferecida << ") nao esta marcada como 'disponivel para troca'." << endl;
       cout << "Va em 'Gerenciar Colecao' para disponibiliza-la primeiro." << endl;
       return;
    }

    if(!parceiroUsuario->getAlbum().possuiFigurinha(figDesejada)){
        cout << "Erro: O usuario " << parceiro << " nao possui a figurinha que voce deseja (Nro. " << figDesejada << ")." << endl;
        return;
    }
    
    trocas.emplace_back(usuarioLogado->getNomeDeUsuario(), parceiro, figDesejada, figOferecida, 0);
    cout << "Proposta de troca enviada com sucesso para " << parceiro << "!" << endl;
}

void Sistema::revisarSolicitacoesDeTroca() {
    if (!usuarioLogado) return;
    cout << "\n--- Revisar Solicitacoes de Troca ---" << endl;
    
    vector<int> indicesPropostas;
    int contador = 1;

    for(int i = 0; i < trocas.size(); ++i){
        if(trocas[i].nomeReceptor == usuarioLogado->getNomeDeUsuario() && trocas[i].status == 0){
            cout << "\nProposta " << contador << ":" << endl;
            trocas[i].exibir();
            indicesPropostas.push_back(i);
            contador++;
        }
    }
    
    if(indicesPropostas.empty()){
        cout << "Nao ha novas solicitacoes de troca para voce." << endl;
        return;
    }

    int escolha;
    cout << "\nDigite o numero da proposta que deseja responder (ou 0 para sair): ";
    cin >> escolha;

    if(escolha > 0 && escolha <= indicesPropostas.size()){
        int indiceReal = indicesPropostas[escolha - 1];
        Troca& troca = trocas[indiceReal];

        char resp;
        cout << "Deseja aceitar (s/n)? ";
        cin >> resp;

        if(resp == 's' || resp == 'S'){
            Usuario* proponente = getUsuarioPorNome(troca.nomeProponente);
            
            Figurinha* figMinha = usuarioLogado->getAlbum().getFigurinha(troca.figurinhaRequerida);
            Figurinha* figDele = proponente ? proponente->getAlbum().getFigurinha(troca.figurinhaDisponivel) : nullptr;

            if(proponente && figMinha && figDele && figMinha->getStatus() != 1 && figDele->getStatus() != 1){
                
                Figurinha figurinhaQueEuVouReceber = *figDele;
                Figurinha figurinhaQueEuVouEnviar = *figMinha;

                figurinhaQueEuVouReceber.setStatus(0);
                figurinhaQueEuVouEnviar.setStatus(0);

                proponente->getAlbum().removerFigurinha(figurinhaQueEuVouReceber.getNumero());
                usuarioLogado->getAlbum().removerFigurinha(figurinhaQueEuVouEnviar.getNumero());

                proponente->getAlbum().adicionarFigurinha(figurinhaQueEuVouEnviar);
                usuarioLogado->getAlbum().adicionarFigurinha(figurinhaQueEuVouReceber);

                troca.status = 1;
                
                cout << "\nTroca realizada com sucesso!" << endl;
                cout << "Voce recebeu a figurinha Nro. " << figurinhaQueEuVouReceber.getNumero() 
                     << " (" << figurinhaQueEuVouReceber.getNome() << ")." << endl;
                cout << "Voce enviou a figurinha Nro. " << figurinhaQueEuVouEnviar.getNumero() 
                     << " (" << figurinhaQueEuVouEnviar.getNome() << ")." << endl;
                
            } else {
                 cout << "\nNao foi possivel realizar a troca." << endl;
                 cout << "Motivo: um dos usuarios ou figurinhas nao esta mais disponivel para a troca." << endl;
                 troca.status = 2;
            }
        } else {
            troca.status = 2;
            cout << "Troca recusada." << endl;
        }
    }
}