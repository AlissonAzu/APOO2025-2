#include "PokemonPedra.h"

using namespace std;

PokemonPedra::PokemonPedra(string n, int nv, int def) 
    : Pokemon(n, nv, "Pedra"), defesa(def) {}

void PokemonPedra::atacar() const {
    cout << nome << " lanca uma **Pedra Afiada**!" << endl;
}

void PokemonPedra::exibirStatus() const {
    cout << "--- " << nome << " (Tipo: " << tipoPrincipal << ") ---" << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Defesa Base: " << defesa << endl;
}