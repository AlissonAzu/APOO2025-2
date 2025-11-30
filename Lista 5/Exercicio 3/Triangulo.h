#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaGeometrica.h"

using namespace std;

class Triangulo : public FormaGeometrica {
private:
    float base;
    float altura;
    float lado1;
    float lado2;
    float lado3;

public:
    Triangulo(string n, float b, float a, float l1, float l2, float l3);
    float calcularArea() const override;
    float calcularPerimetro() const override;
};

#endif