/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float calcular_valor ()
{
    float preco_c, quant, valor;
    printf ("Insira o valor do combustivel: ");
    scanf ("%f", &preco_c);
    printf ("Insira a quantidade de combustivel: ");
    scanf ("%f", &quant);
    valor = preco_c*quant;
    printf ("o valor a ser pago eh de: %g", valor);
    
}

int main ()
{
    calcular_valor ();
    
    return 0;
}
