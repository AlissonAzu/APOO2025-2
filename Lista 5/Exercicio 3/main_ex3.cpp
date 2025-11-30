#include "Retangulo.h"
#include "Triangulo.h"
#include "Circulo.h"
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    cout << "--- EXERCICIO 3: POLIMORFISMO (FORMAS GEOMETRICAS) ---" << endl;
    
    Retangulo r("Retangulo", 10.0f, 5.0f);
    Triangulo t("Triangulo", 4.0f, 6.0f, 5.0f, 5.0f, 4.0f); 
    Circulo c("Circulo", 3.0f);

    vector<FormaGeometrica*> formas;
    formas.push_back(&r);
    formas.push_back(&t);
    formas.push_back(&c);
    
    cout << fixed << setprecision(2);

    for (FormaGeometrica* f : formas) {
        cout << "\n--- " << f->getNome() << " ---" << endl; 
        cout << "Area: " << f->calcularArea() << endl;
        cout << "Perimetro: " << f->calcularPerimetro() << endl;
    }

    return 0;
}