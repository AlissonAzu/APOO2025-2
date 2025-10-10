#pragma once
#include <string>

using namespace std;

class Figurinha {
private:
    int numero;
    string nomeJogador;
    string time;

public:
    Figurinha();
    Figurinha(int num, string jogador, string time);

    void setNumero(int num);
    int getNumero() const;

    void setNomeJogador(string jogador);
    string getNomeJogador() const; 
    
    void setTime(string t);
    string getTime() const;

    void resumo() const;
};