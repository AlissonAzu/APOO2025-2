#pragma once
#include <string>

using namespace std;

class CorpoCeleste {
public:
    enum TipoCorpo { Estrela, Planeta, Lua, Asteroide, Cometa, Outro };

private:
    string nome;
    TipoCorpo tipo;
    double massaKg;
    double raioKm;

public:
    CorpoCeleste();
    CorpoCeleste(string nome, TipoCorpo tipo, double massa, double raio);

    void setNome(string nome);
    string getNome();
    void setTipo(TipoCorpo tipo);
    TipoCorpo getTipo();
    void setMassaKg(double massa);
    double getMassaKg();
    void setRaioKm(double raio);
    double getRaioKm();
    
    double calcularDensidade();
    double gravidadeSuperficial();
    void descricao();
};