#include <stdio.h>
int maior_numero (int n1, int n2, int n3)
{
    int maior;
    if (n1 > n2 && n1 > n3) maior = n1;
    if (n2 > n1 && n2 > n3) maior = n2;
    if (n3 > n1 && n3 > n2) maior = n3;
    return maior;
}

int main ()
{
    int n1, n2, n3;
    printf ("Insira três números inteiros diferentes: ");
    scanf ("%d %d %d", &n1, &n2, &n3);
    printf ("O maior número é: %d", maior_numero(n1, n2, n3));
    
    return 0;
}