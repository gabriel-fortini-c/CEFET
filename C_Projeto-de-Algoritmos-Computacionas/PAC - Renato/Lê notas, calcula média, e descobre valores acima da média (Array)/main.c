#include <stdio.h>

void leNotas (float notas[], int qtd)
{
    int ordinal = 1;
    for (int i=0 ; i < qtd ; i++) {
        printf ("Insira a %dª nota: ", ordinal);
        scanf ("%f", &notas[i]);
        ordinal++;
    }
}

float calculaMedia (float notas[], int qtd) 
{
    float soma = 0;
    
    for (int i=0 ; i < qtd ; i++) {
        soma += notas[i];    
    }
    return soma / qtd;
}

void calculaAcimaMedia (float notas[], int qtd, float media)
{
    for (int i=0 ; i < qtd ; i++) {
        if (notas[i] > media) {
            printf ("Nota acima da média: %f\n", notas[i]);
        }
    }
}

int main ()
{
    float notas[5] = {0}, media;
    leNotas (notas, 5);
    media = calculaMedia (notas, 5);
    printf ("A média é: %f\n", media);
    calculaAcimaMedia (notas, 5, media);
    
    return 0;
}




