#include "Squirtle.h"

using namespace std;

Squirtle::Squirtle(int nv) 
    : PokemonAgua("Squirtle", nv) {}

void Squirtle::atacar() const {
    cout << nome << " avanca com um **Ataque Rapido**!" << endl;
}