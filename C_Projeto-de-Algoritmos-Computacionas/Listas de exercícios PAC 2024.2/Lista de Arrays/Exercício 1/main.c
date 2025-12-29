#include <stdio.h>

float calculaMedia (int v[], int qtd) 
{
    int i;
    float soma = 0;
    
    for (i = 0 ; i < qtd ; i++) {
        soma += v[i];
    }
    
    return soma / qtd;
}

int main ()
{
    int i, v[10], ordinal = 1;
    
    for (i = 0 ; i < 10 ; i++) {
        printf ("%d° valor: ", ordinal++);
        scanf ("%d", &v[i]);
    }
    
    printf ("Média: %.2f", calculaMedia(v, 10));
    
    return 0;
}