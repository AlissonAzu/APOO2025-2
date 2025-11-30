#ifndef MAGOVERDE_H
#define MAGOVERDE_H

#include "Mago.h"

using namespace std;

class MagoVerde : public Mago {
public:
    MagoVerde(string n, int p, int i, string e);
    void falarComAnimais() const;
};

#endif