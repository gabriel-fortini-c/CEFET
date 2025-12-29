/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int calculo_minutos (int horas, int minutos)
{
    int horas_em_min;
    printf ("Insira as horas e minutos: ");
    scanf ("%d %d", &horas, &minutos);
    horas_em_min = horas * 60;
    printf ("%d", horas_em_min + minutos);
    
    return horas_em_min + minutos;
    
}

int main ()
{
    int horas, minutos;
    
    calculo_minutos (horas, minutos);
    
    return 0;
}