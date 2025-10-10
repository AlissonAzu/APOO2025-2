#pragma once
#include <string>

using namespace std;

class AssistenteVirtual {
private:
    string nome;
    string idioma;
    string versao;
    int volume;
    bool microfoneAtivo;

public:
    AssistenteVirtual();
    AssistenteVirtual(string nome, string idioma);

    void dizerOla();
    void executarComando(string comando);
    void definirIdioma(string novoIdioma);
    void atualizarVersao(string novaVersao);

    void setVolume(int vol);
    int getVolume();
    void setMicrofoneAtivo(bool ativo);
    bool isMicrofoneAtivo();

    void registrarLembrete();
    void resumoStatus();
};