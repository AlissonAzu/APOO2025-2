#ifndef POKEMONAGUA_H
#define POKEMONAGUA_H

#include "Pokemon.h"

class PokemonAgua : public Pokemon {
public:
    PokemonAgua(std::string n, int nv); 
    
    void atacar() const override; 
    void exibirStatus() const override; 
};

#endif