#ifndef GATO_H
#define GATO_H

#include "Animal.h"

using namespace std;

class Gato : public Animal {
public:
    Gato(string n, string s);
    void fazerSom() const override;
};

#endif