#include "Dado.h"
#include <cstdlib>

Dado::Dado() {
    numeroDeFaces = 6;
}

Dado::Dado(int faces) {
    setFaces(faces);
}

void Dado::setFaces(int faces) {
    if (faces > 0) {
        numeroDeFaces = faces;
    } else {
        numeroDeFaces = 6;
    }
}

int Dado::getFaces() const {
    return numeroDeFaces;
}

int Dado::Rolar() {
    return rand() % numeroDeFaces + 1;
}