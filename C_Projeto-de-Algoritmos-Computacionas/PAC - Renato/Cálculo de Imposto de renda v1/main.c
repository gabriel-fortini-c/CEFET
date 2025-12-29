/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float salario, aliquota, salario_liquido;
    scanf ("%f", &salario);
    
    if (salario > 4664.08)
    {
        aliquota = 0.275;
        salario_liquido = salario - ((salario * aliquota) - 869.36);
        printf ("O salário líquido é de: R$ %.2f", salario_liquido);
    }
    else if (salario >= 3751.06)
    {
        aliquota = 0.225;
        salario_liquido = salario - ((salario * aliquota) - 636.13);
        printf ("O salário líquido é de: R$ %.2f", salario_liquido);
    }
    else if (salario >= 2826.66)
    {
        aliquota = 0.15;
        salario_liquido = salario - ((salario * aliquota) - 354.80);
        printf ("O salário líquido é de: R$ %.2f", salario_liquido);
    }
    else if (salario >= 1903.99)
    {
        aliquota = 0.075;
        salario_liquido = salario - ((salario * aliquota) - 142.80);
        printf ("O salário líquido é de: R$ %.2f", salario_liquido);
    }
    else
    {
        printf ("O salário líquido é de: %.2f", salario);
    }
    return 0;
}