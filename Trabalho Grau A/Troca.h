#pragma once

#include <string>

using namespace std;

class Troca {
public:
    string nomeProponente;
    string nomeReceptor;
    int figurinhaRequerida;
    int figurinhaDisponivel;
    int status;
    
    Troca(const string& proponente, const string& receptor, int req, int disp, int status = 0);
    void exibir() const;
};