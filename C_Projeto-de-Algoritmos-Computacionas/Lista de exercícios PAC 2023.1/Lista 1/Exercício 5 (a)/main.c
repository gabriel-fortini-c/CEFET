/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int calculo_minutos (int horas, int minutos)
{
    int horas_em_min;
    horas_em_min = horas * 60;
    return horas_em_min + minutos;
    
}

int main ()
{
    int horas, minutos;
    printf ("Insira as horas e minutos: ");
    scanf ("%d %d", &horas, &minutos);
    printf ("%d", calculo_minutos (horas, minutos));
    
    return 0;
}
