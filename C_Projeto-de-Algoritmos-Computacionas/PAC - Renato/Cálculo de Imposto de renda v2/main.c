/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float salario_liquido (float salario_bruto)
{
    float aliquota;
    if (salario_bruto > 4664.68)
    {
        aliquota = 0.275;
        return salario_bruto - ((salario_bruto * aliquota) - 869.36);
    }
    else if (salario_bruto >= 3751.06)
    {
        aliquota = 0.225;
        return salario_bruto - ((salario_bruto * aliquota) - 636.13);
    }
    else if (salario_bruto >= 2826.66)
    {
        aliquota = 0.15;
        return salario_bruto - ((salario_bruto * aliquota) - 354.80);
    }
    else if (salario_bruto >= 1903.99)
    {
        aliquota = 0.075;
        return salario_bruto - ((salario_bruto * aliquota) - 142.80);
    }
    else
    {
        return salario_bruto;
    }
}


int main()
{
    float salario_bruto;
    scanf ("%f", &salario_bruto);
    printf ("O seu salário líquido é de: R$ %.2f", salario_liquido (salario_bruto));
    
    return 0;
}