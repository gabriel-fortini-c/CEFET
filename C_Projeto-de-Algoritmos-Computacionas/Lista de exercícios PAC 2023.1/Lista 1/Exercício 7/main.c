#include <stdio.h>

int calculo_cedula (int valor)
{
    int valor_receber, resto1, resto2, resto3, resto4, resto5, resto6;
    printf ("O valor a receber é de: ");
    resto1 = valor;
    if (valor / 100 > 0)
    {
        valor_receber = resto1 / 100;
        printf ("%d cedulas de 100 reais, ", valor_receber);
        resto1 = valor % 100;
    }
    
    
    if (resto1 / 50 > 0)
    {
        valor_receber = resto1 / 50;
        printf ("%d cedulas de 50 reais, ", valor_receber);
        resto2 = resto1 % 50;
    }
    else resto2 = resto1;
    
    
    if (resto2 / 20 > 0)
    {
        valor_receber = resto2 / 20;
        printf ("%d cedulas de 20 reais, ", valor_receber);
        resto3 = resto2 % 20;
    }
    else resto3 = resto2;
    
    
    if (resto3 / 10 > 0)
    {
        valor_receber = resto3 / 10;
        printf ("%d cedulas de 10 reais, ", valor_receber);
        resto4 = resto3 % 10;
    }
    else resto4 = resto3;
    
    
    if (resto4 / 5 > 0)
    {
        valor_receber = resto4 / 5;
        printf ("%d cedulas de 5 reais, ", valor_receber);
        resto5 = resto4 % 5;
    }
    else resto5 = resto4;
    
    
    if (resto5 / 2 > 0)
    {
        valor_receber = resto5 / 2;
        printf ("%d cedulas de 2 reais, ", valor_receber);
        resto6 = resto5 % 2;
    }
    else resto6 = resto5;
    
    
    if (resto6 > 0)
    {
        printf ("%d cedula de 1 real", resto6);
    }
}

int main()
{
    int valor;
    printf("Insira um valor inteiro: ");
    scanf ("%d", &valor);
    calculo_cedula (valor);

    return 0;
}