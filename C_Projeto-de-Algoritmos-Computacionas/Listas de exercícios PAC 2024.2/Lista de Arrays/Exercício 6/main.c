#include <stdio.h>

void somaArray (float v[], float a[], int qtd, float soma[])
{
    for (int i = 0 ; i < qtd ; i++) {
        soma[i] = v[i] + a[i];
    }
}

int main()
{
    float v[5], a[5], soma[5];
    int qtd, ordinal = 1;
    
    for (int i = 0 ; i < 5 ; i++) {
        printf ("Insira o %dº valor do 1º vetor: ", ordinal++);
        scanf ("%f", &v[i]);
    }
    
    ordinal = 1;
    for (int i = 0 ; i < 5 ; i++) {
        printf ("Insira o %dº valor do 2º vetor: ", ordinal++);
        scanf ("%f", &a[i]);
    }
    
    somaArray(v, a, 5, soma);
    
    ordinal = 1;
    for (int i = 0 ; i < 5 ; i++) {
        printf ("O %dº valor do vetor de soma é: %g\n", ordinal++, soma[i]);
    }
    return 0;
}


