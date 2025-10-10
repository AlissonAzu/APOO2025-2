#include "Figurinha.h"
#include <iostream>

using namespace std;

Figurinha::Figurinha(int numero, const string& nome, const string& conteudo, int nroPagina, int status)
    : numero(numero), nome(nome), conteudo(conteudo), nroPagina(nroPagina), status(status) {}

int Figurinha::getNumero() const { return numero; }
string Figurinha::getNome() const { return nome; }
string Figurinha::getConteudo() const { return conteudo; }
int Figurinha::getStatus() const { return status; }

void Figurinha::setStatus(int novoStatus) {
    if (novoStatus >= 0 && novoStatus <= 2) {
        this->status = novoStatus;
    }
}

string Figurinha::getStatusString() const {
    switch (status) {
        case 0: return "Na colecao";
        case 1: return "Colada";
        case 2: return "Disponivel para troca";
        default: return "Desconhecido";
    }
}

void Figurinha::exibir() const {
    cout << "  - Nro: " << numero << " | Nome: " << nome << " | Status: " << getStatusString() << endl;
}