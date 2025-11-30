#ifndef CACHORRO_H
#define CACHORRO_H

#include "Animal.h"

using namespace std;

class Cachorro : public Animal {
public:
    Cachorro(string n, string s);
    void fazerSom() const override; 
};

#endif