#include <stdio.h>

int calculo_semanas (int total_dias)
{
    int semanas, dias;
    semanas = total_dias / 7;
    dias  = total_dias % 7;
    printf ("%d semanas e %d dias.", semanas, dias);
}

int main ()
{
    int total_dias;
    printf ("Insira o total de dias: ");
    scanf ("%d", &total_dias);
    calculo_semanas (total_dias);
    
    return 0;
}