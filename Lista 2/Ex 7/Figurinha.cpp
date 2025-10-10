#include "Figurinha.h"
#include <iostream>

Figurinha::Figurinha() {
    numero = 0;
    nomeJogador = "N/D";
    time = "N/D";
}

Figurinha::Figurinha(int num, string jogador, string t) {
    setNumero(num);
    setNomeJogador(jogador);
    setTime(t);
}

void Figurinha::setNumero(int num) {
    if (num > 0) {
        numero = num;
    } else {
        numero = 1;
    }
}

void Figurinha::setNomeJogador(string jogador) { nomeJogador = jogador; }

void Figurinha::setTime(string t) { time = t; }

int Figurinha::getNumero() const {
    return numero;
}

string Figurinha::getNomeJogador() const { 
    return nomeJogador;
}

string Figurinha::getTime() const { 
    return time;
}

void Figurinha::resumo() const {
    cout << "  - Numero: " << numero 
         << ", Jogador: " << nomeJogador 
         << ", Time: " << time << endl;
}