#include "Retangulo.h"

using namespace std;

Retangulo::Retangulo(string n, float b, float a) 
    : FormaGeometrica(n), base(b), altura(a) {}

float Retangulo::calcularArea() const {
    return base * altura;
}

float Retangulo::calcularPerimetro() const {
    return 2 * (base + altura);
}