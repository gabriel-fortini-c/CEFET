#include <stdio.h>
#include <math.h>

void descobrePalindromo (int numero)
{
    int qtdAlgarismos = 0, somaInv = 0, digitoInverso, inverso;
    int numeroTeste1  = numero, numeroTeste2 = numero;
    
    for (int i = 0 ; numeroTeste1 != 0 ; i++) {
        numeroTeste1 /= 10;
        qtdAlgarismos++;
    }
    
    int j = qtdAlgarismos - 1;
    for (j ; numeroTeste2 = 0 ; j--) {
        digitoInverso = numero % 10;
        inverso = digitoInverso * (pow(10, j));
        somaInv += inverso;
        numero = numero / 10;
    }
    
    if (somaInv == numero) {
        printf ("O número é Palíndromo.\n");
    }
    if (somaInv != numero) {
        printf ("O número não é Palíndromo.\n");
    }    
}

int main ()
{
    int i, numero;
    for (i=0 ; i < 100 ; i++) {
        printf ("Número: ");
        scanf ("%d", &numero);
        descobrePalindromo (numero);
    }
    
    return 0;
}