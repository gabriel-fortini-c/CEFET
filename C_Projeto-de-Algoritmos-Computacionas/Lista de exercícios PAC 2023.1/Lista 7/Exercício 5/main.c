#include <stdio.h>

typedef struct depto Tdepto;

struct depto
{
    int qtd;
    float soma;
};

void calculaDepto (Tdepto departamento[30])
{
    int i = 0, ordinal = 1;
    float salMedio;
    
    for (i = 0 ; i < 5 ; i++) {
        salMedio = departamento[i].soma / departamento[i].qtd;
        
        printf ("~~~~~~~~~~~~~~~~~~~~~ %d° Departamento ~~~~~~~~~~~~~~~~~~~~~\n", ordinal++);
        printf ("O código do departamento: %d\n", i + 1);
        printf ("O salário médio desse departamento é de: R$%.2f\n", salMedio);
    }
}

int main () 
{
    Tdepto departamento [30];
    int i = 0, ordinal = 1;
    
    for (i = 0 ; i < 30 ; i++) {
        printf ("Insira a quantidadede funcionários do %d° Departamento: ", ordinal);
        scanf ("%d", &departamento[i].qtd);
        printf ("Insira a soma de salários do %d° Departamento: ", ordinal++);
        scanf ("%f", &departamento[i].soma);
    }
    
    calculaDepto (departamento);
    
    return 0;
}









