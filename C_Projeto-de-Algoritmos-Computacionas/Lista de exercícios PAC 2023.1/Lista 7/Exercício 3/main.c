#include <stdio.h>

int calculaArray (float v[], int qtd, float media)
{
    int qtdAcima = 0;
    for (int i = 0 ; i < qtd ; i++) {
        if (v[i] > media) {
            qtdAcima++;
        }
    }
    return qtdAcima;
}

int main ()
{
    int ordinal = 1, qtdAcima;
    float maior = 0, media, valor, soma = 0;
    float v[10];
    
    for (int i = 0 ; i < 10 ; i++) {
        printf ("Insira o valor do %dº elemento do array: ", ordinal++);
        scanf ("%f", &valor);
        v[i] = valor;
        soma += v[i];
    }
    
    media = soma / 10.0;
    
    qtdAcima = calculaArray (v, 10, media);
    
    printf ("A quantidade de números acima da média doi de: %d", qtdAcima);
    
    return 0;
}
