#pragma once
#include <string>

using namespace std;

class FrequenciaCardiaca {
private:
    string primeiroNome;
    string sobrenome;
    int diaNasc;
    int mesNasc;
    int anoNasc;

public:
    FrequenciaCardiaca();
    FrequenciaCardiaca(string pNome, string sNome, int dia, int mes, int ano);

    void setPrimeiroNome(string pNome);
    string getPrimeiroNome();

    void setSobrenome(string sNome);
    string getSobrenome();

    void setDiaNasc(int dia);
    int getDiaNasc();

    void setMesNasc(int mes);
    int getMesNasc();

    void setAnoNasc(int ano);
    int getAnoNasc();

    int obterIdade(int diaAtual, int mesAtual, int anoAtual);
    int obterFrequenciaMaxima(int idade);
    void obterFrequenciaIdeal(int freqMaxima, int& minAlvo, int& maxAlvo);
};