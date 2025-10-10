#include "FrequenciaCardiaca.h"
#include <iostream>

FrequenciaCardiaca::FrequenciaCardiaca() {
    primeiroNome = "N/D";
    sobrenome = "N/D";
    diaNasc = 1;
    mesNasc = 1;
    anoNasc = 2000;
}

FrequenciaCardiaca::FrequenciaCardiaca(string pNome, string sNome, int dia, int mes, int ano) {
    setPrimeiroNome(pNome);
    setSobrenome(sNome);
    setDiaNasc(dia);
    setMesNasc(mes);
    setAnoNasc(ano);
}

void FrequenciaCardiaca::setPrimeiroNome(string pNome) { primeiroNome = pNome; }
void FrequenciaCardiaca::setSobrenome(string sNome) { sobrenome = sNome; }

void FrequenciaCardiaca::setDiaNasc(int dia) {
    if (dia >= 1 && dia <= 31) {
        diaNasc = dia;
    } else {
        diaNasc = 1;
    }
}

void FrequenciaCardiaca::setMesNasc(int mes) {
    if (mes >= 1 && mes <= 12) {
        mesNasc = mes;
    } else {
        mesNasc = 1;
    }
}

void FrequenciaCardiaca::setAnoNasc(int ano) {
    if (ano > 1900) {
        anoNasc = ano;
    } else {
        anoNasc = 1901;
    }
}

string FrequenciaCardiaca::getPrimeiroNome() { return primeiroNome; }
string FrequenciaCardiaca::getSobrenome() { return sobrenome; }
int FrequenciaCardiaca::getDiaNasc() { return diaNasc; }
int FrequenciaCardiaca::getMesNasc() { return mesNasc; }
int FrequenciaCardiaca::getAnoNasc() { return anoNasc; }

int FrequenciaCardiaca::obterIdade(int diaAtual, int mesAtual, int anoAtual) {
    int idade = anoAtual - anoNasc;
    
    if (mesAtual < mesNasc || (mesAtual == mesNasc && diaAtual < diaNasc)) {
        idade--;
    }
    return idade;
}

int FrequenciaCardiaca::obterFrequenciaMaxima(int idade) {
    return 220 - idade;
}

void FrequenciaCardiaca::obterFrequenciaIdeal(int freqMaxima, int& minAlvo, int& maxAlvo) {
    minAlvo = freqMaxima * 0.50;
    maxAlvo = freqMaxima * 0.85;
}