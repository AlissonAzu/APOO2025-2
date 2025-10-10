#pragma once

#include <string>
#include <vector>
#include "Figurinha.h"

using namespace std;

class Pagina {
public:
    int numero;
    string titulo;
    int minNro;
    int maxNro;

    Pagina(int num, const string& tit, int min, int max)
        : numero(num), titulo(tit), minNro(min), maxNro(max) {}
};