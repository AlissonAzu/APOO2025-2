#include <iostream>
#include "Figurinha.h"
#include "Album.h"

int main() {
    cout << "--- Meu Album de Figurinhas ---" << endl;

    Figurinha f1(10, "Neymar Jr", "Brasil");
    Figurinha f2(7, "Cristiano Ronaldo", "Portugal");
    Figurinha f3(30, "Lionel Messi", "Argentina");
    Figurinha f4(9, "Richarlison", "Brasil");
    
    Album meuAlbum;
    meuAlbum.adicionar(f1);
    meuAlbum.adicionar(f2);
    meuAlbum.adicionar(f3);
    meuAlbum.adicionar(f4);

    cout << "\nTotal de figurinhas no album: " << meuAlbum.quantidade() << endl;

    int numeroParaChecar = 30;
    if (meuAlbum.possui(numeroParaChecar)) {
        cout << "Voce possui a figurinha numero " << numeroParaChecar << "!" << endl;
    } else {
        cout << "Voce NAO possui a figurinha numero " << numeroParaChecar << "." << endl;
    }
    
    numeroParaChecar = 15;
     if (meuAlbum.possui(numeroParaChecar)) {
        cout << "Voce possui a figurinha numero " << numeroParaChecar << "!" << endl;
    } else {
        cout << "Voce NAO possui a figurinha numero " << numeroParaChecar << "." << endl;
    }

    cout << "\n--- Conteudo do Album ---" << endl;
    meuAlbum.listar();

    return 0;
}