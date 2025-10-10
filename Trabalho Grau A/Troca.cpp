#include "Troca.h"
#include <iostream>

using namespace std;

Troca::Troca(const string& proponente, const string& receptor, int req, int disp, int status)
    : nomeProponente(proponente), nomeReceptor(receptor), figurinhaRequerida(req), figurinhaDisponivel(disp), status(status) {}

void Troca::exibir() const {
    cout << "Proposta de: " << nomeProponente << endl;
    cout << "  - Voce entrega a figurinha: " << figurinhaRequerida << endl;
    cout << "  - Voce recebe a figurinha: " << figurinhaDisponivel << endl;
}