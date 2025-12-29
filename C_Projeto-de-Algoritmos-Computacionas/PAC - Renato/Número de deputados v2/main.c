/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>


int calcular_dep (int pop_uf)
{
    int calculo_dep = round((double)pop_uf * 513 / 190755799); 
    // 513 é o número de cadeiras e 190755799 é a população total do Brasil
    
    if (calculo_dep < 8) return 8;
    if (calculo_dep >70) return 70;
    
    return calculo_dep;
    
}

int main ()
{
    int populacao, num_dep;
    printf ("Digite a população do estado: ");
    scanf ("%d", &populacao);
    num_dep = calcular_dep (populacao);
    printf ("O número de deputados desse estado são: %d", num_dep);
    
    return 0;
}
