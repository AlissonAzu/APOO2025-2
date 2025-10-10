#pragma once

#include <vector>
#include "Figurinha.h"

using namespace std;

class Album {
private:
    vector<Figurinha> figurinhas;

public:
    void adicionarFigurinha(const Figurinha& novaFigurinha);
    void removerFigurinha(int numero);
    Figurinha* getFigurinha(int numero);
    bool possuiFigurinha(int numero);

    const vector<Figurinha>& getFigurinhas() const;
    void setFigurinhas(const vector<Figurinha>& novasFigurinhas);
};