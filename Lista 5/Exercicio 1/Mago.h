#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include <string>

using namespace std;

class Mago {
protected:
    string nome;
    int poder;
    int idade;
    string escolaMagia;

public:
    Mago(string n, int p, int i, string e);
    
    void andar() const;
    void falar() const;
    void invocarMagia() const;

    void falarComum() const;
};

#endif