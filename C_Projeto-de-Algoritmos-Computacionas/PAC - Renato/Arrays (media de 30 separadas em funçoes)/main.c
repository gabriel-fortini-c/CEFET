#include <stdio.h>

float calculaMedia (float v[], int n)
{
    float soma = 0;
    for (int i=0 ; i < n ; i++) {
        soma += v[i];
    }
    return soma / n;
}

void leNotas (float v[], int n)
{
    for (int i=0 ; i < n ; i++) {
        printf ("")/
        scanf ("%f", &v[i]);
    }
}

int main ()
{
    float notas[30];
    leNotas (notas, 30);
    printf ("%f", calculaMedia (notas, 30));
    
}