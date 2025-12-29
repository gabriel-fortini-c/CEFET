#include <stdio.h>

float processaDepartamento (int cod, int quantFuncionarios)
{
    int matricula, i;
    float salario, soma = 0;
    for (i = 0 ; i < quantFuncionarios ; i++) {
        printf ("Insira a matrícula e o salário do funcionário: ");
        scanf ("%d %f", &matricula, &salario);
        soma += salario;
    }
    printf ("Código do departamento: %d\nA soma de salário desse departamento é de R$%.02f\n\n", cod, soma);
    return soma;
}

int main ()
{
    int cod, quantFuncionarios, i;
    float somaDepartamento;
    for (i=0 ; i < 2 ; i++) {
        printf ("Insira o código e a quantidade de funcionários do departamento: ");
        scanf ("%d %d", &cod, &quantFuncionarios);
        somaDepartamento +=processaDepartamento(cod, quantFuncionarios);
    }
    printf ("A soma de salários de todos os departamentos é de R$%.02f", somaDepartamento);
    return 0;
}