#include <stdio.h>

void leNumeros (int num[], int numeros)
{
    
    for (int i=0 ; i < numeros ; i++) {
        printf ("Insira o número: ");
        scanf ("%d", &num[i]);
    }
}

int calculaMaior (int num[], int numero)
{
    int maior = 0;
    for (int i=0 ; i < numero ; i++) {
        if (maior == 0 || num[i] > maior) {
            maior = num[i];
        }
    }
    return maior;
}

int main ()
{
    int num[10] = {0};
    leNumeros (num, 10);
    printf ("O maior número é: %d", calculaMaior(num, 10));
    
    return 0;
}