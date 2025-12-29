/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float multiplicar (float num1, float num2)
{
    float multiplicacao = num1 * num2;
    return multiplicacao;
}

int main()
{
    float num1, num2;
    printf ("Escreva dois números reais: ");
    scanf ("%f %f", &num1, &num2);
    printf ("%g", multiplicar(num1, num2));
    
    return 0;
}