#include "Gato.h"
#include "Cachorro.h"
#include "Galinha.h"
#include <vector>

using namespace std;

int main() {
    cout << "--- EXERCICIO 2: CLASSES ABSTRATAS (ANIMAIS) ---" << endl;
    
    // Animal a("Teste", "Som"); // Descomente para testar: DARA ERRO DE COMPILACAO!
    cout << "Tentativa de instanciar Animal diretamente resultaria em erro (Classe Abstrata)." << endl;
    
    Gato felix("Felix", "Miau");
    Cachorro rex("Rex", "Au Au");
    Galinha gertrude("Gertrude", "Cocorico");

    vector<Animal*> animais;
    animais.push_back(&felix);
    animais.push_back(&rex);
    animais.push_back(&gertrude);

    cout << "\n--- Polimorfismo em Acao ---" << endl;
    for (Animal* a : animais) {
        a->info();
        a->fazerSom();
    }

    return 0;
}