#pragma once
#include <vector>
#include "Figurinha.h"

class Album {
private:
    vector<Figurinha> figurinhas;

public:
    void adicionar(Figurinha f);
    bool possui(int numero);
    int quantidade();
    void listar();
};