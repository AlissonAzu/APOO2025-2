#include "Album.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Album::adicionarFigurinha(const Figurinha& novaFigurinha) {
    if (!possuiFigurinha(novaFigurinha.getNumero())) {
        figurinhas.push_back(novaFigurinha);
    } else {
         cout << "Voce ja possui a figurinha " << novaFigurinha.getNumero() << " (repetida)." << endl;
    }
}

Figurinha* Album::getFigurinha(int numero) {
    for (auto& fig : figurinhas) {
        if (fig.getNumero() == numero) {
            return &fig;
        }
    }
    return nullptr;
}

bool Album::possuiFigurinha(int numero) {
    return getFigurinha(numero) != nullptr;
}

const vector<Figurinha>& Album::getFigurinhas() const {
    return figurinhas;
}

void Album::setFigurinhas(const vector<Figurinha>& novasFigurinhas){
    this->figurinhas = novasFigurinhas;
}

void Album::removerFigurinha(int numero) {
    for (auto it = figurinhas.begin(); it != figurinhas.end(); ++it) {
        if (it->getNumero() == numero) {
            figurinhas.erase(it);
            return;
        }
    }
}