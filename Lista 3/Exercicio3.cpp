#include <iostream>
#include <cstdlib>
#include <ctime>

void imprimirEstado(int* vagas, int numVagas) {
    std::cout << "Estado do estacionamento: [ ";
    for (int i = 0; i < numVagas; ++i) {
        std::cout << vagas[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    using namespace std;

    srand(time(0));

    int numVagas;
    cout << "--- Simulacao de Estacionamento ---" << endl;
    do {
        cout << "Digite o numero de vagas (entre 5 e 15): ";
        cin >> numVagas;
    } while (numVagas < 5 || numVagas > 15);

    int* vagas = new int[numVagas];

    for (int i = 0; i < numVagas; ++i) {
        vagas[i] = 0;
    }

    for (int ciclo = 1; ciclo <= 24; ++ciclo) {
        cout << "\n----------------------------" << endl;
        cout << "      HORA: " << ciclo << endl;
        cout << "----------------------------" << endl;

        for (int i = 0; i < numVagas; ++i) {
            if (vagas[i] > 0) {
                vagas[i]--;
            }
        }

        bool estacionou = false;
        for (int i = 0; i < numVagas; ++i) {
            if (vagas[i] == 0) {
                int tempo = rand() % 5 + 1;
                vagas[i] = tempo;
                cout << ">> Novo carro entrou na vaga " << i + 1 << " por " << tempo << " horas." << endl;
                estacionou = true;
                break;
            }
        }

        if (!estacionou) {
            cout << ">> Estacionamento cheio! O carro nao entrou." << endl;
        }

        imprimirEstado(vagas, numVagas);
    }

    delete[] vagas;

    return 0;
}