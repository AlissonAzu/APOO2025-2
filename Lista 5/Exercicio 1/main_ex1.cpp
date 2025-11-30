#include "MagoBranco.h"
#include "MagoVerde.h"

using namespace std;

int main() {
    cout << "--- EXERCICIO 1: HERANCA SIMPLES (MAGOS) ---" << endl;
    
    MagoBranco gandalf("Gandalf", 900, 2000, "Branca");
    MagoVerde radagast("Radagast", 750, 1800, "Verde");

    cout << "\n--- Gandalf (Mago Branco) ---" << endl;

    gandalf.andar();
    gandalf.falarComum(); 
    gandalf.falar();
    

    gandalf.lancarCura();
    
    cout << "\n--- Radagast (Mago Verde) ---" << endl;

    radagast.andar();
    radagast.invocarMagia();
    
    radagast.falarComAnimais();

    return 0;
}