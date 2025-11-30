#ifndef GALINHA_H
#define GALINHA_H

#include "Animal.h"

using namespace std;

class Galinha : public Animal {
public:
    Galinha(string n, string s);
    void fazerSom() const override;
};

#endif