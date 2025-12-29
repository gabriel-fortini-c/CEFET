/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int bissexto (int ano)
{
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int validar_data (int dia, int mes, int ano)
{
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1)
    {
    return 0;
    }
    
    if (mes == 2) // Fevereiro
    {
        if (bissexto (ano))
        {
            if (dia > 29) return 0;
        }
        else if (dia > 28) return 0;
    }
    
    else if (mes == 4|| mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30) return 0;
    }
    else 
    {
    if(dia > 31) return 0;
    }

return 1;
}

int main()
{
    int dia, mes, ano;
    printf ("Digite o dia: ");
    scanf ("%d", &dia);
    printf ("Digite o mês: ");
    scanf ("%d", &mes);
    printf ("Digite o ano: ");
    scanf ("%d", &ano);
    
    if (validar_data(dia, mes, ano))
    {
        printf ("A data %02d/%02d/%d é válida.", dia, mes, ano);
    }
    else
    {
        printf ("A data %02d/%02d/%d é inválida.", dia, mes, ano);
    }
    
    return 0;
}
    
    
    
    
    
    
    