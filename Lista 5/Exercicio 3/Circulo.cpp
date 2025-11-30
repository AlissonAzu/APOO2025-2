#include "Circulo.h"

using namespace std;

Circulo::Circulo(string n, float r) 
    : FormaGeometrica(n), raio(r) {}

float Circulo::calcularArea() const {
    return PI * raio * raio;
}

float Circulo::calcularPerimetro() const {
    return 2 * PI * raio;
}