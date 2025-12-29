/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float calculo_aumento (float preco_unitario)
{
    float novo_preco = preco_unitario + (preco_unitario*0.2);
    return novo_preco;
}

int main ()
{
    float preco;
    printf ("Insira o preco unitario: ");
    scanf ("%f", &preco);
    printf ("O novo preco eh de: R$%.2f", calculo_aumento(preco));
    
    return 0;
}