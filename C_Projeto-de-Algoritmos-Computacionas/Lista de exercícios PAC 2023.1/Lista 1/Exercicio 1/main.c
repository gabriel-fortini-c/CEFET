/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int somar (int num1, int num2)
{
    int soma = num1 + num2;
    return soma;
}

int main ()
{
    int n1, n2;
    printf ("Entre com dois numeros inteiros: ");
    scanf ("%d %d", &n1, &n2);
    printf ("A soma eh: %d", somar (n1, n2));
    
    return 0;
}