#include <stdio.h>

int verificaPerfeito (int numero)
{
    int k;
    if (numero < 1) {
        return 0;
    }
    
    for (k=1 ; k*k <= numero ; k++) {
        if (k*k == numero) {
            return 1;
        }
    }
    return 0;
}

int main ()
{
    int numero;
    printf ("Insira: ");
    scanf ("%d", &numero);
    printf ("%d", verificaPerfeito (numero));
    
    return 0;
}