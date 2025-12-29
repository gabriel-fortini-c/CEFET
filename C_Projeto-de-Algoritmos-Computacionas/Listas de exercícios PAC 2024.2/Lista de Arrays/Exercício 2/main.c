#include <stdio.h>

void calculaImparPar (int v[], int qtd, int *impares, int *pares) 
{
    int i;
    
    *pares = 0;
    *impares = 0;
    
    for (i = 0 ; i < qtd ; i++) {
        if (v[i] % 2 == 0) {
            (*pares)++;
        }
        else {
            (*impares)++;
        }
    }
}

int main ()
{
    int i, v[30], ordinal = 1, pares, impares;
    
    for (i = 0 ; i < 30 ; i++) {
        printf ("%dº valor: ", ordinal++);
        scanf ("%d", &v[i]);
    }
    calculaImparPar (v, 30, &pares, &impares);
    
    printf ("Pares: %d\n", pares);
    printf ("Ímpares: %d", impares);
    
    return 0;
}