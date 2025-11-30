#ifndef FORMAGEOMETRICA_H
#define FORMAGEOMETRICA_H

#include <iostream>
#include <string>

using namespace std;

class FormaGeometrica {
protected:
    string nome;

public:
    FormaGeometrica(string n);
    virtual ~FormaGeometrica() {}

    string getNome() const { return nome; }

    virtual float calcularArea() const = 0;
    virtual float calcularPerimetro() const = 0;
};

#endif