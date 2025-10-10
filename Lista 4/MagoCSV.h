#pragma once
#include <string>
#include "Mago.h"

using namespace std;

class MagoCSV {
public:
    void serialize(Mago* magos, int nLinhas, const string& nomeArquivo);

    Mago* deserialize(const string& nomeArquivo, int nLinhas, int nColunas);
};