#ifndef POKEMONFOGO_H
#define POKEMONFOGO_H

#include "Pokemon.h"

class PokemonFogo : public Pokemon {
private:
    int temperaturaMaxima;

public:
    PokemonFogo(std::string n, int nv, int temp);
    PokemonFogo(std::string n);

    void atacar() const override; 
    void exibirStatus() const override; 
};

#endif