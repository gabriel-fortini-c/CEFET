#include <stdio.h>

int calcula_soma (int n1, int n2, int n3)
{
    int soma = n1 + n2 + n3;
    printf ("A soma eh: %d\n", soma);
    return soma;
}

int calcula_media (int n1, int n2, int n3)
{
    int media = (n1 + n2 + n3) / 3;
    printf ("A media eh: %d", media);
}

int main()
{
    int n1, n2, n3;
    printf("Insira 3 numeros inteiros: ");
    scanf ("%d %d %d", &n1, &n2, &n3);
    calcula_soma (n1, n2, n3);
    calcula_media (n1, n2, n3);

    return 0;
}