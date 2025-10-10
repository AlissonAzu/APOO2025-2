#include <iostream>
#include <fstream>
#include "Mago.h"
#include "MagoCSV.h"

using namespace std;

int contarLinhas(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return 0;
    
    string linha;
    int contador = 0;
    getline(arquivo, linha);
    while (getline(arquivo, linha)) {
        contador++;
    }
    return contador;
}


int main() {
    const string ARQUIVO_ENTRADA = "magos.csv";
    const string ARQUIVO_SAIDA = "saida.csv";
    const int N_COLUNAS = 3;

    MagoCSV csvHandler;
    
    int nLinhas = contarLinhas(ARQUIVO_ENTRADA);
    cout << "Arquivo '" << ARQUIVO_ENTRADA << "' contem " << nLinhas << " magos." << endl << endl;

    Mago* meusMagos = csvHandler.deserialize(ARQUIVO_ENTRADA, nLinhas, N_COLUNAS);

    cout << "--- Magos Lidos do Arquivo ---" << endl;
    for (int i = 0; i < nLinhas; i++) {
        meusMagos[i].imprimir();
    }
    cout << "--------------------------------" << endl << endl;

    cout << "--- Adicionar um Novo Mago ---" << endl;
    string nome, escola;
    int idade;
    cout << "Digite o nome do novo mago: ";
    getline(cin, nome);
    cout << "Digite a idade: ";
    cin >> idade;
    cin.ignore();
    cout << "Digite a escola de magia: ";
    getline(cin, escola);
    
    Mago novoMago(nome, idade, escola);

    int novoTamanho = nLinhas + 1;
    Mago* tempArray = new Mago[novoTamanho];
    for(int i = 0; i < nLinhas; i++) {
        tempArray[i] = meusMagos[i];
    }
    tempArray[nLinhas] = novoMago;

    delete[] meusMagos;
    meusMagos = tempArray;
    nLinhas = novoTamanho;

    cout << "\nNovo mago adicionado com sucesso!" << endl;
    cout << "Total de magos agora: " << nLinhas << endl << endl;

    cout << "Gravando o array atualizado no arquivo '" << ARQUIVO_SAIDA << "'..." << endl;
    csvHandler.serialize(meusMagos, nLinhas, ARQUIVO_SAIDA);
    cout << "Gravacao concluida!" << endl;

    
    delete[] meusMagos;

    return 0;
}