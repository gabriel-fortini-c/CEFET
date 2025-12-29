#include <stdio.h>

void umDepartamento (int qtdFuncionarios, int *funcMaiorSalario, float *maiorSalario)
{
    int matricula, ordinal = 1;
    float salario;
    
    for (int i = 0 ; i < qtdFuncionarios ; i++) {
        printf ("Insira a matrícula do %dº funcionário: ", ordinal++);
        scanf ("%d", &matricula);
        printf ("Insira o salário desse funcionáio: ");
        scanf ("%f", &salario);
        if (*maiorSalario == 0 || salario >= *maiorSalario) {
            (*maiorSalario) = salario;
            (*funcMaiorSalario) = 1;
        }
        else if (*maiorSalario == salario) {
            (*funcMaiorSalario)++;
        }
        
        (((*maiorSalario) == salario) ? (*funcMaiorSalario)++ : (*funcMaiorSalario) == 1);
        
    }
}


int main()
{
    int codDep, qtdFuncionarios, ordinal = 1, funcMaiorSalario = 0;
    float maiorSalario = 0;
    
    while (1) {
        printf ("~~~~~~~~~~~~~~~~  %d° Departamento  ~~~~~~~~~~~~~~~~\n\n", ordinal);
        printf ("Insira o código do %dº departamento (0 para terminar): ", ordinal);
        scanf ("%d", &codDep);
        
        if (codDep == 0) break;
        
        printf ("Insira a quantidade de funcionários nesse departamento: ");
        scanf ("%d", &qtdFuncionarios);
        
        umDepartamento (qtdFuncionarios, &funcMaiorSalario, &maiorSalario);
        
        printf ("\n\nO maior salário do %dº departamento foi de R$%.2f\n", ordinal++, maiorSalario);
        printf ("A quantidade de funcionários com o maior salário foi de: %d\n\n\n", funcMaiorSalario);
    }
}
