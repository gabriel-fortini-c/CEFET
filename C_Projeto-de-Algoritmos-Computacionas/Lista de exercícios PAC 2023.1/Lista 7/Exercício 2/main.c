#include <stdio.h>

void calculaArray (int v[], int qtd, int *qtdPares, int *qtdImpares)
{
    int i = 0;
    for (i = 0 ; i < qtd ; i++) {
        if (v[i] % 2 == 0) {
            (*qtdPares)++;
        }
        else {
            (*qtdImpares)++;
        }
    }
}

int main ()
{
    int ordinal = 1, valor, i, qtdPares = 0, qtdImpares = 0;
    int v[10];
    for (i = 0 ; i < 10 ; i++) {
        printf ("Insira o valor do %dº elemento do array: ", ordinal++);
        scanf ("%d", &valor);
        v[i] = valor;
    }
    
    calculaArray (v, 10, &qtdPares, &qtdImpares);
    
    printf ("Quantidade de pares: %d\n", qtdPares);
    printf ("Quantidade de ímpares: %d\n", qtdImpares);
}