#pragma once

#include <string>

using namespace std;

class Figurinha {
private:
    int numero;
    string nome;
    string conteudo;
    int status;
    int nroPagina;

public:
    Figurinha(int numero, const string& nome, const string& conteudo, int nroPagina, int status = 0);

    int getNumero() const;
    string getNome() const;
    string getConteudo() const;
    int getStatus() const;
    string getStatusString() const;

    void setStatus(int novoStatus);
    void exibir() const;
};