#include "PokemonEletrico.h"

using namespace std;

PokemonEletrico::PokemonEletrico(string n, int nv, int volt) 
    : Pokemon(n, nv, "Eletrico"), voltagem(volt) {}

void PokemonEletrico::atacar() const {
    cout << nome << " solta um **Choque do Trovao**!" << endl;
}

void PokemonEletrico::exibirStatus() const {
    cout << "--- " << nome << " (Tipo: " << tipoPrincipal << ") ---" << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Voltagem: " << voltagem << " V" << endl;
}