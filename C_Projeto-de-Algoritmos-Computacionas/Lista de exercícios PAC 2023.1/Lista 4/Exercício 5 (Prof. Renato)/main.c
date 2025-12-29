/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float processar_departamento (int codigo, int quantidade_funcionario)
{
    float soma_salario = 0, salario;
    int matricula;
    
    for (int i=0; i < quantidade_funcionario; i++)
    {
        printf ("Insira a matícula e o salário: ");
        scanf ("%d %f", &matricula, &salario);
        soma_salario = soma_salario + salario;
    }
    
    printf ("%d %f\n", codigo, soma_salario);
    return soma_salario;
}


int main ()
{
    int codigo, quantidade_funcionario;
    float soma = 0;
    
    for (int i = 0; i < 3; i++)
    {
        printf ("Insira o código do departamento e a quantidade de funcionário: ");
        scanf ("%d %d", &codigo, &quantidade_funcionario);
        soma = soma + processar_departamento (codigo, quantidade_funcionario);
    }
    
    printf ("A soma de todos os departamentos: %g", soma);
    return 0;
}



