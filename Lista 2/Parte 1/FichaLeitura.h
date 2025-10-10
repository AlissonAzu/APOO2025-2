#pragma once
#include <string>

using namespace std;

class FichaLeitura {
private:
    string titulo;
    string autor;
    int anoPublicacao;
    int numPaginas;
    int paginaAtual;
    bool lido;
    double nota0a5;

public:
    FichaLeitura();
    FichaLeitura(string titulo, string autor, int ano, int paginas);

    void iniciarLeitura();
    void marcarLido();
    void avancarPaginas(int paginas);
    void avaliar(double nota);

    void setTitulo(string titulo);
    string getTitulo();
    void setAutor(string autor);
    string getAutor();
    
    double exibirPercentualLido();
    void resumo();
};