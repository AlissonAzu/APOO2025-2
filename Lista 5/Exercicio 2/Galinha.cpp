#include "Galinha.h"

using namespace std;

Galinha::Galinha(string n, string s) 
    : Animal(n, s) {}

void Galinha::fazerSom() const {
    cout << nome << " faz: " << somBicho << "!" << endl;
}