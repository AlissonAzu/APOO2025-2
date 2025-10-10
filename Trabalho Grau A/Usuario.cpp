#include "Usuario.h"

using namespace std;

Usuario::Usuario(const string& nome, const string& s)
    : nomeDeUsuario(nome), senha(s) {}

string Usuario::getNomeDeUsuario() const {
    return nomeDeUsuario;
}

bool Usuario::verificarLogin(const string& nome, const string& s) const {
    return (this->nomeDeUsuario == nome && this->senha == s);
}

Album& Usuario::getAlbum() {
    return album;
}

const Album& Usuario::getAlbum() const {
    return album;
}