/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x1, x2, x;
    printf ("Entre com a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    delta = (b*b) - (4*a*c);
    
    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf ("Possui duas raizes reais: %.0f e %.0f", x1, x2);
    }
    
    else // delta menor ou igual a zero
    {
        if (delta == 0) // delta igual a zero
        {
            x = -b / (2*a);
            printf ("Possui uma unica raiz: %.0f", x);
        }
        else // delta menor que zero
        {
            printf ("Nao possui raizes reais");
        }
    }
    
    return 0;
}
