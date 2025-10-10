#include "Mago.h"

Mago::Mago():nome(""),idade(0),escolaDeMagia("") //inicialização junto a assinatura do Método
{
    //Inicialização dentro do bloco de código(só precisa de uma das formas)
    nome="";
    idade=0;
    escolaDeMagia="";
    cout << "Mago criado com contrutor padrão" << endl;
}

Mago::~Mago()
{
    cout << "Deixou de existir!" << endl;
}

Mago::Mago(string nome, int idade, string escolaDeMagia)
{
    this->nome = nome;
    this-> idade + idade;
    this->escolaDeMagia = escolaDeMagia;
}

void Mago::alterarNome(string nome)
{
    this->nome = nome;
}

void Mago::alterarIdade(int idade)
{
    this->idade = idade;
}

int Mago::retornarIdade()
{
    return idade;
}

string Mago::retornarNome()
{
    return nome;
}

void Mago::andar()
{
    cout << "Estou andando!" << endl;
}

void Mago::falar(string msg)
{
    cout << "Meu nome é " << this->nome << endl;
    cout << msg << endl;
}

void Mago::invocarMagia()
{
    cout << "Invocando Magia" << endl;
}
