#include "MagoCSV.h"
#include <fstream>
#include <sstream>
#include <vector>

void MagoCSV::serialize(Mago* magos, int nLinhas, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para gravacao: " << nomeArquivo << endl;
        return;
    }

    arquivo << "Nome,Idade,Escola" << endl;

    for (int i = 0; i < nLinhas; i++) {
        arquivo << magos[i].getNome() << ","
                << magos[i].getIdade() << ","
                << magos[i].getEscola() << endl;
    }

    arquivo.close();
}

Mago* MagoCSV::deserialize(const string& nomeArquivo, int nLinhas, int nColunas) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para leitura: " << nomeArquivo << endl;
        return nullptr;
    }

    Mago* arrayDeMagos = new Mago[nLinhas];
    
    string linha;
    int magoIndex = 0;

    getline(arquivo, linha);

    while (getline(arquivo, linha) && magoIndex < nLinhas) {
        stringstream ss(linha);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == nColunas) {
            string nome = tokens[0];
            int idade = stoi(tokens[1]);
            string escola = tokens[2];
            
            arrayDeMagos[magoIndex] = Mago(nome, idade, escola);
            magoIndex++;
        }
    }

    arquivo.close();
    return arrayDeMagos;
}
