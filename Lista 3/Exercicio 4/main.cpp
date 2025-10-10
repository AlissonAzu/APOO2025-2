#include <iostream>
#include <ctime>
#include "Dado.h"

int main() {
    using namespace std;

    srand(time(0));

    cout << "--- Parte A: Alocacao de um unico dado ---" << endl;
    
    Dado* d1 = new Dado(6);
    cout << "Dado de " << d1->getFaces() << " faces criado." << endl;
    

    int resultado = d1->Rolar();
    cout << "Resultado da rolagem: " << resultado << endl;
    
    delete d1;
    d1 = nullptr;

    cout << "\n--- Parte B: Alocacao de um array de dados ---" << endl;

    Dado* arrayDeDados = new Dado[3];
    cout << "Array com 3 dados alocado." << endl;

    arrayDeDados[0].setFaces(6);
    arrayDeDados[1].setFaces(8);
    arrayDeDados[2].setFaces(12);

    for (int i = 0; i < 3; ++i) {
        cout << "\nRolando o dado " << i + 1 << " (d" << arrayDeDados[i].getFaces() << ") 3 vezes:" << endl;
        for (int j = 0; j < 3; ++j) {
            cout << "  -> Jogada " << j + 1 << ": " << arrayDeDados[i].Rolar() << endl;
        }
    }

    delete[] arrayDeDados;
    arrayDeDados = nullptr;

    return 0;
}