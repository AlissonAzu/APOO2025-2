#include "Mago.h"


Mago::Mago() : nome(""), idade(0), escola("") {}

Mago::Mago(string nome, int idade, string escola) {
    this->nome = nome;
    this->idade = idade;
    this->escola = escola;
}

void Mago::setNome(const string& nome) {
    this->nome = nome;
}

void Mago::setIdade(int idade) {
    this->idade = idade;
}

void Mago::setEscola(const string& escola) {
    this->escola = escola;
}

string Mago::getNome() const {
    return nome;
}

int Mago::getIdade() const {
    return idade;
}

string Mago::getEscola() const {
    return escola;
}

void Mago::imprimir() const {
    cout << "Mago: " << nome << " (" << idade << " anos), Escola: " << escola << endl;
}

