#include "Triangulo.h"

using namespace std;

Triangulo::Triangulo(string n, float b, float a, float l1, float l2, float l3) 
    : FormaGeometrica(n), base(b), altura(a), lado1(l1), lado2(l2), lado3(l3) {}

float Triangulo::calcularArea() const {
    return (base * altura) / 2;
}

float Triangulo::calcularPerimetro() const {
    return lado1 + lado2 + lado3;
}