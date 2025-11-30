#include "MagoVerde.h"

using namespace std;

MagoVerde::MagoVerde(string n, int p, int i, string e) 
    : Mago(n, p, i, e) {}

void MagoVerde::falarComAnimais() const {
    cout << nome << " conversa com um esquilo sobre a natureza da magia." << endl;
}