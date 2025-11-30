#include "Pokedex.h"
#include "PokemonFogo.h" 
#include "PokemonAgua.h" 
#include "Squirtle.h"
#include "PokemonEletrico.h"
#include "PokemonPedra.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Pokedex::~Pokedex() {
    for (Pokemon* p : catalogo) {
        delete p;
    }
}

void Pokedex::adicionarPokemon(Pokemon* novo) {
    catalogo.push_back(novo);
    cout << novo->getNome() << " adicionado a Pokedex." << endl;
}

void Pokedex::listarTodos() const {
    cout << "\n=== Catalogo da Pokedex ===" << endl;
    for (const Pokemon* p : catalogo) {
        p->exibirStatus();
    }
}

void Pokedex::salvarParaArquivo(const string& nomeArquivo) const {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const Pokemon* p : catalogo) {
            arquivo << p->getNome() << "," << p->getTipoPrincipal() << "," << p->getNivel() << endl;
        }
        cout << "Pokedex salva em " << nomeArquivo << endl;
        arquivo.close();
    } else {
        cerr << "ERRO: Nao foi possivel abrir o arquivo para salvar." << endl;
    }
}

void Pokedex::carregarDeArquivo(const string& nomeArquivo) {
    for (Pokemon* p : catalogo) {
        delete p;
    }
    catalogo.clear(); 
    
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "AVISO: Arquivo de dados nao encontrado. Comecando com Pokedex vazia." << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string campo;
        vector<string> campos;

        while (getline(ss, campo, ',')) {
            campos.push_back(campo);
        }

        if (campos.size() == 3) {
            string nome = campos[0];
            string tipo = campos[1];
            int nivel = stoi(campos[2]);
            
            Pokemon* novo = nullptr;

            if (tipo == "Fogo") {
                novo = new PokemonFogo(nome, nivel, 750); 
            } else if (tipo == "Agua") {
                if (nome == "Squirtle" && nivel <= 16) { 
                    novo = new Squirtle(nivel);
                } else {
                    novo = new PokemonAgua(nome, nivel);
                }
            } else if (tipo == "Eletrico") {
                novo = new PokemonEletrico(nome, nivel, 220); 
            } else if (tipo == "Pedra") {
                novo = new PokemonPedra(nome, nivel, 80); 
            }
            
            if (novo) {
                catalogo.push_back(novo);
            }
        }
    }
    cout << "Pokedex carregada de " << nomeArquivo << ". Total de " << catalogo.size() << " Pokemon." << endl;
    arquivo.close();
}