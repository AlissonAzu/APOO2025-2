#include "PokemonAgua.h"

using namespace std;

PokemonAgua::PokemonAgua(string n, int nv) 
    : Pokemon(n, nv, "Agua") {}

void PokemonAgua::atacar() const {
    cout << nome << " lanca um **Jato d'Agua** forte!" << endl;
}

void PokemonAgua::exibirStatus() const {
    cout << "--- " << nome << " (Tipo: " << tipoPrincipal << ") ---" << endl;
    cout << "Nivel: " << nivel << endl;
}