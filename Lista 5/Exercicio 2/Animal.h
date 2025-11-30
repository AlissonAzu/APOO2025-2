#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string nome;
    string somBicho;

public:
    Animal(string n, string s);
    virtual ~Animal() {}

    virtual void fazerSom() const = 0; // Metodo virtual puro

    void info() const;
};

#endif