#ifndef POKEDEX_H
#define POKEDEX_H

#include <vector>
#include <fstream>
#include <sstream>
#include "Pokemon.h"

class Pokedex {
private:
    std::vector<Pokemon*> catalogo;

public:
    Pokedex() {}
    ~Pokedex(); 

    void adicionarPokemon(Pokemon* novo);
    void listarTodos() const;
    
    void salvarParaArquivo(const std::string& nomeArquivo) const;
    void carregarDeArquivo(const std::string& nomeArquivo);

    const std::vector<Pokemon*>& getCatalogo() const { return catalogo; }
};

#endif