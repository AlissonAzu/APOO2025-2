#include "Pokemon.h"

using namespace std;

Pokemon::Pokemon(string n, int nv, string tp) 
    : nome(n), nivel(nv), tipoPrincipal(tp) {}

void Pokemon::receberDano(int dano) {
    cout << nome << " recebeu dano!" << endl;
}