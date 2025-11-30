#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaGeometrica.h"
#include <cmath> // Para M_PI

using namespace std;

class Circulo : public FormaGeometrica {
private:
    float raio;
    const float PI = 3.14159f;

public:
    Circulo(string n, float r);
    float calcularArea() const override;
    float calcularPerimetro() const override;
};

#endif