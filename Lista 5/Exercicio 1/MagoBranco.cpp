#include "MagoBranco.h"

using namespace std;

MagoBranco::MagoBranco(string n, int p, int i, string e) 
    : Mago(n, p, i, e) {}

void MagoBranco::lancarCura() const {
    cout << nome << " lanca o feitiço Curar: +50 de Vida." << endl;
}