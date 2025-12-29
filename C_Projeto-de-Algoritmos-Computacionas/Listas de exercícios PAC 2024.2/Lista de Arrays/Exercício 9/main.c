#include <stdio.h>

void inicializa (int departamentos[])
{
    int codDep, idade, indice, ordinal = 1;
    
    for (int i = 0 ; i < 20 ; i++) {
        printf ("Insira o codigo do departamento: ");
        scanf ("%d", &codDep);
        
        printf ("Insira a idade do %dº funcionario: ", ordinal++);
        scanf ("%d", &idade);
        
        indice = codDep - 10;
        
        if (idade > departamentos[indice]) {
            departamentos[indice] = idade;
        }
    }
}

void exibe (int departamentos[])
{
    int indice;
    
    for (int i = 0 ; i < 11 ; i++) {
        indice = i + 10;
        printf ("Departamento %d: %d anos\n", indice, departamentos[i]);
    }
}

int main()
{
    int departamentos[11] = {0};
    inicializa(departamentos);
    exibe(departamentos);
    
    return 0;
}