#include "Gato.h"

using namespace std;

Gato::Gato(string n, string s) 
    : Animal(n, s) {}

void Gato::fazerSom() const {
    cout << nome << " faz: " << somBicho << "!" << endl;
}