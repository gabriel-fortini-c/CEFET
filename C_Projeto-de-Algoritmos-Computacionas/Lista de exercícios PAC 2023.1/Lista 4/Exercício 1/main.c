/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int calcula_tabuada (int numero)
{
    int i;
    for (i=1 ; i <= 10 ; i++)
    {
        printf ("%d x %d = %d\n", numero, i, numero * i);
    }
}

int main ()
{
    int numero;
    printf ("Insira um número inteiro para calcular a tabuada: ");
    scanf ("%d", &numero);
    calcula_tabuada(numero);
    
    return 0;
}
