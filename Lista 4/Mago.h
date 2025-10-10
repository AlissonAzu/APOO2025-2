#pragma once
#include <iostream>
#include <string>

using namespace std;

class Mago {
private:
    string nome;
    int idade;
    string escola;

public:
    Mago();
    Mago(string nome, int idade, string escola);

    void setNome(const string& nome);
    void setIdade(int idade);
    void setEscola(const string& escola);

    string getNome() const;
    int getIdade() const;
    string getEscola() const;

    void imprimir() const;
};