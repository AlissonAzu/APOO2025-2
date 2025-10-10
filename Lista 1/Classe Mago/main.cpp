#include "Mago.h"

int main()
{
    Mago mago; //criando um objeto da classe mago.

    // Invocando os métodos
    mago.andar();
    mago.falar("Olá mundo da OO");
    mago.invocarMagia();

   // Alterar o  nome do objeto invando o metodo setter alterarNome 
    mago.alterarNome("Merlin");
    mago.alterarIdade(100);
    
    mago.falar("");
    //Instanciando um objeto uilizando o construtor padrão
    Mago mago2("Harry Potter",12,"Hogwarts");
    Mago mago3("Gandalf",300,"Mordor");
    
    mago2.falar("Olá");
    mago3.falar("Olá");
    int menorIdade;
    string maisNovo;
    if(mago.retornarIdade() < mago2.retornarIdade())
    {
        menorIdade = mago.retornarIdade();
        maisNovo = mago.retornarNome();
    }
    else if(mago2.retornarIdade() < mago3.retornarIdade())
    {
        menorIdade = mago2.retornarIdade();
        maisNovo = mago2.retornarNome();
    }
    else
    {
        menorIdade = mago3.retornarIdade();
        maisNovo = mago3.retornarNome();
    }

    cout << "O mago mais novo chama-se " << maisNovo << "e sua idade é " << menorIdade << endl;

    getchar(); // Espera apertar uma tecla
    return 0;
}
