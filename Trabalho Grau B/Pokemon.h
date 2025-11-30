#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector> 

class Pokemon {
protected:
    std::string nome;
    int nivel;
    std::string tipoPrincipal;

public:
    Pokemon(std::string n, int nv, std::string tp);
    virtual ~Pokemon() {} 

    virtual void atacar() const = 0;
    virtual void exibirStatus() const = 0; 
    
    virtual void receberDano(int dano);
    
    std::string getNome() const { return nome; }
    std::string getTipoPrincipal() const { return tipoPrincipal; }
    int getNivel() const { return nivel; }
};

#endif