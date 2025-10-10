#pragma once

#include <string>
#include "Album.h"

using namespace std;

class Usuario {
private:
    string nomeDeUsuario;
    string senha;
    Album album;

public:
    Usuario(const string& nome, const string& s);

    string getNomeDeUsuario() const;
    bool verificarLogin(const string& nome, const string& s) const;
    
    Album& getAlbum(); 
    
    const Album& getAlbum() const; 
};