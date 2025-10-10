#include <iostream>
#include <string>
using namespace std;

class Mago {
public:
    Mago(); //Construtor Padrão
    ~Mago(); //Destrutor
    Mago(string nome, int idade, string escolaDeMagia);//Contrutor personalizado
    //Metodos setters
    void alterarNome(string nome);
    void alterarIdade(int idade);
    //Metodos getters
    int retornarIdade();
    string retornarNome();
    
    void andar();
    void falar(string msg);
    void invocarMagia();

private:
    string nome;
    int idade;
    string escolaDeMagia;

};