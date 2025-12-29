#include <stdio.h>

int main ()
{
    float notas[30] = {0};
    float soma = 0, media;
    for (int i=0 ; i < 30 ; i++) {
        printf ("Nota: ");
        scanf ("%f", notas[i]);
        soma += notas[i];
    }
    media = soma / 30;
    
    for (int i=0 ; i < 30 ; i++) {
        if (notas[i] < media) {
            printf ("Nota abaixo da média: %f\n", notas[i]);
        }
    }
    
    return 0;
}