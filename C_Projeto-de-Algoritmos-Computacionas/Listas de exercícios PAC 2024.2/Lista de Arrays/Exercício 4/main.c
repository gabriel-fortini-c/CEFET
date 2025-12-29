#include <stdio.h>

int calculaArray (float v[], int qtd)
{
    int i = 0, qtdAcima = 0;
    
    for (i = 0 ; i < qtd ; i++) {
        if (v[i] > v[qtd - 1]) {
            qtdAcima++;
        }
    }
    return qtdAcima;
}

int main () 
{
    int i, ordinal = 1;
    float v[10];
    
    for (i = 0 ; i < 10 ; i++) {
        printf ("%dº valor: ", ordinal++);
        scanf ("%f", &v[i]);
    }
    
    printf ("Qtd acima do ultimo elemento do vetor: %d", calculaArray(v, 10));
}