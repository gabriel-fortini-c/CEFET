/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int calcula_soma (int x, int y, int * z)
{
    int soma = x + y + z;
    return soma;
}

int calcula_media (int copiaN1, int copiaN2, int copiaN3)
{
    int media = (copiaN1 + copiaN2 + copiaN3) / 3;
    return media;
}

int main()
{
    int n1, n2, n3;
    int soma = 0;
    printf("Soma: %d", soma);
    printf ("Insira três números naturais: ");
    scanf ("%d %d %d", &n1, &n2, &n3);
    printf ("A soma é: %d\nA média é: %d", calcula_soma(n1,n2,n3), calcula_media(n1,n2,n3));

    return 0;
}