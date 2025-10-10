#pragma once

#include <vector>
#include "Usuario.h"
#include "Figurinha.h"
#include "Troca.h"
#include "Pagina.h"

using namespace std;

class Sistema {
private:
    vector<Usuario> usuarios;
    vector<Figurinha> figurinhasMestre;
    vector<Troca> trocas;
    vector<Pagina> layoutPaginas;
    Usuario* usuarioLogado;

    void carregarFigurinhasMestre();
    void carregarUsuarios();
    void carregarAlbumDoUsuario(Usuario& usuario);
    void carregarTrocas();

    void salvarAlbumDoUsuario(const Usuario& usuario) const;
    void salvarTrocas() const;

public:
    Sistema();
    ~Sistema();

    Usuario* login(const string& nome, const string& senha);
    void logout();
    bool criarNovoUsuario(const string& nome, const string& senha);
    Usuario* getUsuarioLogado();
    Usuario* getUsuarioPorNome(const string& nome);
    void salvarDados();

    void abrirPacoteDeFigurinhas();
    void proporTroca();
    void revisarSolicitacoesDeTroca();
    void verAlbum();
    void gerenciarColecao();
};