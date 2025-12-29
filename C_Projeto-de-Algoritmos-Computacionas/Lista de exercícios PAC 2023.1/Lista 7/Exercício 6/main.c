#include <stdio.h>

int encontraNumero (float v[], float procurado, int qtd)
{
    int inicio = 0, meio = 0, fim = qtd - 1;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (v[meio] == procurado) {
            return meio;
        }
        else if (v[meio] < procurado) {
            inicio = meio + 1;
        }
        else {// if (v[meio] > procurado)
            fim = meio - 1;
        }
    }
    return -1;
}

int main ()
{
    float v[20];
    float procurado, valor;
    int qtd = 20, ordinal = 1, posicao;
    
    for (int i = 0 ; i < qtd ; i++) {
        printf ("Insira o valor do %dº elemento do array: ", ordinal++);
        scanf ("%f", &valor);
        v[i] = valor;
    }
    
    printf ("\n\n\nInsira um número a ser procurado: ");
    scanf ("%f", &procurado);
    
    posicao = encontraNumero(v, procurado, qtd);
    
    if (posicao == -1) {
        printf ("O seu número não está no array.");
    }
    else {
        printf ("A posição do seu número é: %d", posicao);
    }
    
    return 0;
}