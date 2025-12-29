#include <stdio.h>

typedef struct _pessoa Pessoa;

struct _pessoa {
    int instrucao;
    int idade;
};

void inicializa (Pessoa pessoas[])
{
    int ordinal = 1;
    
    printf (" 1 – Analfabeto\n2 – Primeiro grau\n3 – Segundo grau\n4 – Superior\n5 – Mestrado\n6 – Doutorado\n7 – Outros\n");
    for (int i = 0 ; i < 7 ; i++) {
        printf ("Insira o grau de instrucao e a idade da %dº pessoa: ", ordinal++);
        scanf ("%d %d", &pessoas[i].instrucao, &pessoas[i].idade);
    }
}

void exibe (Pessoa pessoas[])
{
    int soma[7] = {0}, qtd[7] = {0};
    int indice;
    
    for (int i = 0 ; i < 7 ; i++) {
        indice = pessoas[i].instrucao - 1;
        soma[indice] += pessoas[i].idade;
        qtd[indice]++;
    }
    
    for (int i = 0 ; i < 7 ; i++) {
        if (qtd[i] > 0) {
            printf ("Media de idade no nivel %d: %.2f\n", i + 1, (float)soma[i] / qtd[i]);
        }
        else {
            printf ("Sem dados!\n");
        }
    }
}

int main()
{
    Pessoa pessoas[50] = {0};
    
    inicializa (pessoas);
    exibe (pessoas);
    
    
    return 0;
}