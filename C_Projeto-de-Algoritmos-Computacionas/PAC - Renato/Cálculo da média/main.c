/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i;
    float num, soma;
    
    printf ("Digite números para cálculo da média deles. Quando quiser parar, digite um número negativo. \n");
    scanf ("%f",&num);
    soma = 0;
    i = 0;
    while (num>0)
    {
        i++;
        soma += num;
        scanf ("%f", &num);
    }
    
    if (i>0)
    {
        printf ("%g", soma / i);
    }
    else
    {
        printf ("Erro!");
    }
    
    return 0;
}
