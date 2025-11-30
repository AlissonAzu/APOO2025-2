#include "Animal.h"

using namespace std;

Animal::Animal(string n, string s) 
    : nome(n), somBicho(s) {}

void Animal::info() const {
    cout << nome << " e um animal." << endl;
}