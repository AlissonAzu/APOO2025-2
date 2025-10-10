#pragma once
#include <string>

using namespace std;

class SmartHouse {
private:
    bool luzesLigadas;
    double temperaturaDesejada;
    bool alarmeAtivo;
    bool portaTrancada;
    string modo;

public:
    SmartHouse();
    
    void ligarDesligarLuzes();
    void ativarDesativarAlarme();
    void trancarDestrancarPorta();
    
    void setTemperaturaDesejada(double temp);
    double getTemperaturaDesejada();
    void setModo(string modo);
    string getModo();

    void status();
    void aplicarCena(string cena);
};