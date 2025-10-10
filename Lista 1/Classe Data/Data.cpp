#include "Data.h"

Data::Data(int d, int m, int a)
{
    dia = d;
    mes = m;
    ano = a;
}

Data::~Data()
{
}

void Data::imprimirData()
{
    cout << dia <<"/" << mes << "/" << ano;
}

void Data::imprimirDataPorExtenso(string cidade)
{
    string meses[12] = {"janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    //Escrver a data no formato <cidade>, <dia> de , <mes por extenso>
    cout << cidade << ", " << dia << " de " <<  meses[mes-1] << " de " << ano << "."; 
}
