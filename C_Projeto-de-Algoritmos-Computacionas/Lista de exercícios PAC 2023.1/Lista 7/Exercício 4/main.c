#include <stdio.h>

int calculaArray (float v[], int qtd) 
{
    int qtdMenores = 0;
    
    for (int i = 0 ; i < qtd ; i++) {
        if (v[i] < v[qtd - 1]) {
            qtdMenores++;
        }
    }
    
    return qtdMenores;
}

int main () 
{
    int ordinal = 1, qtdMenores;
    float valor;
    float v[10];
    
    for (int i = 0 ; i < 10 ; i++) {
        printf ("Insira o valor do %dº elemento do array: ", ordinal++);
        scanf ("%f", &valor);
        v[i] = valor;
    }
    
    qtdMenores = calculaArray (v, 10);
    
    printf ("A quantidade de números menores que o último elemento do array é de: %d", qtdMenores);
    
    return 0;
}