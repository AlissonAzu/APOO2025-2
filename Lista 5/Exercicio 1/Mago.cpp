#include "Mago.h"

using namespace std;

Mago::Mago(string n, int p, int i, string e) 
    : nome(n), poder(p), idade(i), escolaMagia(e) {}

void Mago::andar() const {
    cout << nome << " esta andando." << endl;
}

void Mago::falar() const {
    cout << nome << ": 'Sou um mago da escola de " << escolaMagia << ".'" << endl;
}

void Mago::invocarMagia() const {
    cout << nome << " invoca uma magia poderosa! (Poder: " << poder << ")" << endl;
}

void Mago::falarComum() const {
    cout << nome << " diz: Ola, sou um mago." << endl;
}