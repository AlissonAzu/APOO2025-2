#include "Album.h"
#include <iostream>

void Album::adicionar(Figurinha f) {
    figurinhas.push_back(f);
}

bool Album::possui(int numero) {
    for (const auto& fig : figurinhas) {
        if (fig.getNumero() == numero) {
            return true;
        }
    }
    return false;
}

int Album::quantidade() {
    return figurinhas.size();
}

void Album::listar() {
    if (figurinhas.empty()) {
        cout << "O album esta vazio." << endl;
    } else {
        cout << "Figurinhas no Album:" << endl;
        for (auto& fig : figurinhas) {
            fig.resumo();
        }
    }
}