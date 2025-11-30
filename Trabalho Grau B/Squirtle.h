#ifndef SQUIRTLE_H
#define SQUIRTLE_H

#include "PokemonAgua.h"

class Squirtle : public PokemonAgua {
public:
    Squirtle(int nv);
    
    void atacar() const override;
};

#endif