#ifndef RETANGULO_H
#define RETANGULO_H

#include "FormaGeometrica.h"

using namespace std;

class Retangulo : public FormaGeometrica {
private:
    float base;
    float altura;

public:
    Retangulo(string n, float b, float a);
    float calcularArea() const override;
    float calcularPerimetro() const override;
};

#endif