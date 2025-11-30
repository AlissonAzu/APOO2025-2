#ifndef POKEMONPEDRA_H
#define POKEMONPEDRA_H

#include "Pokemon.h"

class PokemonPedra : public Pokemon {
private:
    int defesa;

public:
    PokemonPedra(std::string n, int nv, int def); 
    
    void atacar() const override; 
    void exibirStatus() const override; 
};

#endif