#pragma once
#include <string>

using namespace std;

class Anamnese {
private:
    string nome;
    int idade;
    double pesoKg;
    double alturaM;
    string alergias;
    string doencasPreExistentes;
    string medicamentosEmUso;

public:
    Anamnese();
    Anamnese(string nome, int idade, double pesoKg, double alturaM, string alergias, string doencas, string medicamentos);

    void setNome(string nome);
    string getNome();
    void setIdade(int idade);
    int getIdade();
    void setPesoKg(double pesoKg);
    double getPesoKg();
    void setAlturaM(double alturaM);
    double getAlturaM();
    void setAlergias(string alergias);
    string getAlergias();
    void setDoencasPreExistentes(string doencas);
    string getDoencasPreExistentes();
    void setMedicamentosEmUso(string medicamentos);
    string getMedicamentosEmUso();

    double calcularIMC();
    void gerarResumo();
};