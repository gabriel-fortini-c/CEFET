#include <stdio.h>

void descobrePalindromo (int numero)
{
    int soma = 0;
    int y, x = numero;
    
    while (x > 0) {
        y = x % 10;
        x = x / 10;
        soma = (soma * 10) + y;
    }
    if (soma == numero){
        printf ("É palíndromo.\n");
    }
    else { 
        printf ("Não é palíndromo.\n");
    }
}

int main ()
{
    int numero;
    for (int i=0 ; i < 100 ; i++) {
        printf ("Número: ");
        scanf ("%d", &numero);
        descobrePalindromo(numero);
    }
    return 0;
}