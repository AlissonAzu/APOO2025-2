#ifndef POKEMONELETRICO_H
#define POKEMONELETRICO_H

#include "Pokemon.h"

class PokemonEletrico : public Pokemon {
private:
    int voltagem;

public:
    PokemonEletrico(std::string n, int nv, int volt); 
    
    void atacar() const override; 
    void exibirStatus() const override; 
};

#endif