/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int digitos_cpf (int cpf)
{
    int cpf1, soma1, soma2, i, d1, d2;
    
    soma1 = 0;
    soma2 = 0;
    i = 9;
    
    while (i>=0)
    {
        cpf1 = cpf % 10;
        soma1 = soma1 + cpf1*i;
        soma2 = soma2 + cpf1*(i-1);
        cpf = cpf / 10;
        i = i - 1;
    }
    soma2 = soma2 + (soma1 % 11)*9;
    d1 = soma1 % 11;
    d2 = soma2 % 11;
    
    if (d1 > 10) 
    { 
        d1 = 0; 
    }
    else
    return d1*10 + d2;
}

int main ()
{
    int cpf_usuario;
    printf ("Digite seu CPF sem os dois últimos dígitos: ");
    scanf ("%d", &cpf_usuario);
    printf ("Os últimos dois dígitos são: %02d", digitos_cpf(cpf_usuario));
    
    return 0;
}










