#include <stdio.h>

void incializa (int notas[], int qtd)
{
    int nota, ordinal = 1;
    for (int i = 0 ; i < qtd ; i++) {
        printf ("Insira a nota do %dº aluno: ", ordinal++);
        scanf ("%d", &nota);
        notas[nota]++;
    }
}

void exibe (int notas[])
{
    for (int i = 0 ; i < 11 ; i++) {
        printf ("Notas %d: ", i);
        for (int j = 0 ; j < notas[i] ; j++) {
            printf ("*");    
        }
    printf ("\n");
    }
}

int main()
{
    int notas[100] = {0};
    int qtd = 20; // alunos
    
    incializa(notas, qtd);
    exibe(notas);

    return 0;
}