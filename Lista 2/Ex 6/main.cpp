#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "FrequenciaCardiaca.h"

int main() {
    string nome, sobrenome;
    int dia, mes, ano;

    cout << "--- Calculadora de Frequencia Cardiaca ---" << endl;
    cout << "Digite seu primeiro nome: ";
    getline(cin, nome);
    cout << "Digite seu sobrenome: ";
    getline(cin, sobrenome);
    cout << "Digite sua data de nascimento (DD MM AAAA): ";
    cin >> dia >> mes >> ano;

    FrequenciaCardiaca pessoa(nome, sobrenome, dia, mes, ano);

    const auto agora = chrono::system_clock::now();
    const time_t data_atual_t = chrono::system_clock::to_time_t(agora);
    struct tm *data_local = localtime(&data_atual_t);

    int diaAtual = data_local->tm_mday;
    int mesAtual = data_local->tm_mon + 1;
    int anoAtual = data_local->tm_year + 1900;

    int idade = pessoa.obterIdade(diaAtual, mesAtual, anoAtual);
    int freqMax = pessoa.obterFrequenciaMaxima(idade);
    int minIdeal, maxIdeal;
    pessoa.obterFrequenciaIdeal(freqMax, minIdeal, maxIdeal);

    cout << "\n--- Relatorio ---" << endl;
    cout << "Nome Completo: " << pessoa.getPrimeiroNome() << " " << pessoa.getSobrenome() << endl;
    cout << "Data de Nascimento: " << pessoa.getDiaNasc() << "/" << pessoa.getMesNasc() << "/" << pessoa.getAnoNasc() << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Frequencia Cardiaca Maxima: " << freqMax << " bpm" << endl;
    cout << "Frequencia Cardiaca Ideal (Alvo): Entre " << minIdeal << " e " << maxIdeal << " bpm" << endl;

    return 0;
}