#include <stdio.h>

int retornaAcimaMedia (float v[], int qtd, float media)
{
    int qtdAcimaM = 0;
    
    for (int i = 0 ; i < qtd ; i++) {
        if (v[i] > media) {
            qtdAcimaM++;
        }
    }
    
    return qtdAcimaM;
}

int main () 
{
    int i, ordinal = 1;
    float v[10], soma = 0, media;
    
    for (i = 0 ; i < 10 ; i++) {
        printf ("%dº valor: ", ordinal++);
        scanf ("%f", &v[i]);
        soma += v[i];
    }
    media = soma / 10;
    printf ("Qtd acima da media: %d", retornaAcimaMedia(v, 10, media));;
}