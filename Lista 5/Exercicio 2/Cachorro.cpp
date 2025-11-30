#include "Cachorro.h"

using namespace std;

Cachorro::Cachorro(string n, string s) 
    : Animal(n, s) {}

void Cachorro::fazerSom() const {
    cout << nome << " faz: " << somBicho << "!" << endl;
}