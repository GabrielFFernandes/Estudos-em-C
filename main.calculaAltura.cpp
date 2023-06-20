#include <iostream>
#include <stdio.h>

struct estrutura
{
    float altura;
    float crescimento;
};



struct estrutura2
{
    float peso;
    float taxaPeso;
};

typedef struct estrutura Pessoa;
typedef struct estrutura2 Aumento;

int calculaAnos(Pessoa, Pessoa);
int calculaPeso(Aumento, Aumento);

int main()
{

    Aumento chico1, ze1;
    ze1.peso = 65;
    ze1.taxaPeso = 2.5;
    chico1.peso = 50;
    chico1.taxaPeso = 5;

    Pessoa chico, ze;
    ze.altura = 1.5;
    ze.crescimento = 0.02;
    chico.altura = 1.1;
    chico.crescimento = 0.03;

    printf("Quantidade de anos para Chico passar a altura de Ze: %d", calculaAnos(chico, ze));

    printf("\nQuantidade de anos para Chico passar o peso de Ze: %d", calculaPeso(chico1, ze1));

    return 0;
}

int calculaAnos(Pessoa chico, Pessoa ze)
{
    int  contador = 0;
    while(ze.altura > chico.altura)
    {
        ze.altura = ze.altura + ze.crescimento;
        chico.altura =  chico.altura + chico.crescimento;

        contador ++;
    }

    return contador;
}

int calculaPeso(Aumento chico1, Aumento ze1)
{
    int  contador1 = 0;
    while(ze1.peso > chico1.peso)
    {
        ze1.peso = ze1.peso + ze1.taxaPeso;
        chico1.peso =  chico1.peso + chico1.taxaPeso;

        contador1 ++;
    }

    return contador1;
}
