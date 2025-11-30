#include "Pokedex.h"
#include "PokemonFogo.h"
#include "Squirtle.h"
#include "PokemonEletrico.h" 
#include "PokemonPedra.h"    
#include <memory> 

using namespace std;

int main() {
    Pokedex minhaPokedex;

    minhaPokedex.carregarDeArquivo("pokedex_data.csv");

    if (minhaPokedex.getCatalogo().size() < 5) {
        cout << "\n--- Adicionando Pokemons iniciais ---" << endl;
    
        Pokemon* charmander = new PokemonFogo("Charmander", 15, 750);
        Pokemon* wartortle = new PokemonAgua("Wartortle", 20); 
        Pokemon* squirtle = new Squirtle(5); 

        Pokemon* pikachu = new PokemonEletrico("Pikachu", 18, 220);
        Pokemon* geodude = new PokemonPedra("Geodude", 14, 80);

        minhaPokedex.adicionarPokemon(charmander);
        minhaPokedex.adicionarPokemon(wartortle);
        minhaPokedex.adicionarPokemon(squirtle);
        minhaPokedex.adicionarPokemon(pikachu); 
        minhaPokedex.adicionarPokemon(geodude);
    }
    
    minhaPokedex.listarTodos();

    cout << "\n--- Demonstracao de Polimorfismo ---" << endl;
    for (const auto& p : minhaPokedex.getCatalogo()) {
        p->atacar(); 
    }

    cout << "\n--- Demonstracao de Sobrecarga ---" << endl;
    PokemonFogo *vulpix = new PokemonFogo("Vulpix"); 
    vulpix->exibirStatus();
    delete vulpix;

    minhaPokedex.salvarParaArquivo("pokedex_data.csv");

    return 0;
}