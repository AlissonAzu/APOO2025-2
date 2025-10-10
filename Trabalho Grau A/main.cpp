#include <iostream>
#include <string>
#include <limits>
#include "Sistema.h"

using namespace std;

void exibirMenuPrincipal() {
    cout << "\n===== Album de Figurinhas Virtual =====" << endl;
    cout << "1. Novo Album (Cadastrar Usuario)" << endl;
    cout << "2. Acessar Album (Login)" << endl;
    cout << "3. Sair do Aplicativo" << endl;
    cout << "Escolha uma opcao: ";
}

void exibirMenuAlbum() {
    cout << "\n--- Menu do Album ---" << endl;
    cout << "1. Ver Album" << endl;
    cout << "2. Gerenciar a colecao" << endl;
    cout << "3. Abrir pacote de Figurinhas" << endl;
    cout << "4. Voltar ao menu Anterior (Logout)" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    Sistema sistema;
    int opcaoPrincipal = 0;

    while (opcaoPrincipal != 3) {
        exibirMenuPrincipal();
        cin >> opcaoPrincipal;

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcaoPrincipal = 0; 
            continue;
        }

        switch (opcaoPrincipal) {
            case 1: {
                string nome, senha;
                cout << "Digite o nome de usuario: ";
                cin >> nome;
                cout << "Digite a senha: ";
                cin >> senha;
                if (sistema.criarNovoUsuario(nome, senha)) {
                    cout << "Usuario cadastrado com sucesso!" << endl;
                } else {
                    cout << "Erro: Nome de usuario ja existe." << endl;
                }
                break;
            }
            case 2: {
                string nome, senha;
                cout << "Usuario: ";
                cin >> nome;
                cout << "Senha: ";
                cin >> senha;
                
                if (sistema.login(nome, senha)) {
                    cout << "\nLogin bem-sucedido! Bem-vindo, " << nome << "!" << endl;
                    int opcaoAlbum = 0;
                    while (opcaoAlbum != 4) {
                        exibirMenuAlbum();
                        cin >> opcaoAlbum;
                        
                        if (cin.fail()){
                           cin.clear();
                           cin.ignore(numeric_limits<streamsize>::max(), '\n');
                           cout << "Entrada invalida. Por favor, digite um numero." << endl;
                           opcaoAlbum = 0;
                           continue;
                        }

                        switch (opcaoAlbum) {
                            case 1: sistema.verAlbum(); break;
                            case 2: sistema.gerenciarColecao(); break;
                            case 3: sistema.abrirPacoteDeFigurinhas(); break;
                            case 4: sistema.logout(); cout << "Saindo do seu album..." << endl; break;
                            default: cout << "Opcao invalida. Tente novamente." << endl; break;
                        }
                    }
                } else {
                    cout << "Usuario ou senha incorretos." << endl;
                }
                break;
            }
            case 3:
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    }
    
    cout << "\nSalvando todos os dados antes de fechar..." << endl;
    sistema.salvarDados();
    cout << "Programa encerrado." << endl;
    return 0;
}