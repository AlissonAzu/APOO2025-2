#include "PokemonFogo.h"

using namespace std;

PokemonFogo::PokemonFogo(string n, int nv, int temp) 
    : Pokemon(n, nv, "Fogo"), temperaturaMaxima(temp) {}

PokemonFogo::PokemonFogo(string n)
    : Pokemon(n, 10, "Fogo"), temperaturaMaxima(800) {}

void PokemonFogo::atacar() const {
    cout << nome << " dispara um ataque de **Lanca-Chamas**!" << endl;
}

void PokemonFogo::exibirStatus() const {
    cout << "--- " << nome << " (Tipo: " << tipoPrincipal << ") ---" << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Temp. Max.: 800 C" << endl;
}