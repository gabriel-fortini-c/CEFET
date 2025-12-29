#include <stdio.h>

int calculaAutomoveis (int quantidade)
{
    int i, acimaDe100, contador = 0, cod, estoque;
    
    for (i=0 ; i < quantidade ; i++)
    {
        printf ("Insira o código do automóvel e a quantidade em estoque: ");
        scanf ("%d %d", &cod, &estoque);
        
        if (estoque > 1000) {
            contador++;
        }
    }
    return contador;
}

int main ()
{
    int quantidade, op;
    printf ("Insira a quantidade de automóveis diferentes que são produzidos: ");
    scanf ("%d", &quantidade);
    op = calculaAutomoveis(quantidade);
    printf ("A quantidade acima de 1000 no estoque é de %d automóveis diferentes", op);
    
    return 0;
}