#include <stdio.h>
#include <string.h>

typedef struct _Aluno Aluno;

struct _Aluno {
    char nome[40];
    float notas[4];
    int idade;
};


void imprimeAluno(Aluno a) {
    printf("Dados do Aluno\n");
    printf("Nome: %s\n",a.nome);
    for(int i=0; i<4; i++) {
        printf("Nota %d: %f\n",i,a.notas[i]);
    }
    printf("Idade: %d\n",a.idade);
}

void leAluno(Aluno* a) {
    printf("Entre com os dados do Aluno:\n");
    printf("Nome: ");
    scanf("%[^\n]s",a->nome);
    for(int i=0; i<4; i++) {
        printf("Entre com a nota %d: ",i);
        scanf("%f",&a->notas[i]);
    }
    printf("Entre com a idade: ");
    scanf("%d",&a->idade);
}

int main()
{
    Aluno a[100];
    int qt;
    printf("Entre com a quantidade de Alunos: ");
    scanf("%d",&qt);
    for(int i=0; i<qt; i++) {
        leAluno(&a[i]);
    }
    printf("*** Acabou a Leitura ***\n");
    for(int i=0; i<qt; i++) {
        imprimeAluno(a[i]);
    }
    return 0;
}
