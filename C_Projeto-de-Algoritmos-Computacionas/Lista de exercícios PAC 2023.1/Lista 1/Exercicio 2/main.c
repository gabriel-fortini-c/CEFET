/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float calcular_media (float nota1, float nota2)
{
    float media = (nota1+nota2)/2;
    return media;
}

int main ()
{
    float n1, n2;
    printf ("Entre com as duas notas: ");
    scanf ("%f %f", &n1, &n2);
    printf("A media eh: %g", calcular_media (n1, n2));
    
    return 0;
}