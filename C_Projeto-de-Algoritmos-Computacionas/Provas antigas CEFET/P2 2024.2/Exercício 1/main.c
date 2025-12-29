#include <stdio.h>

typedef struct _Candidato Candidato;

struct _Candidato {
    int id;
    char nome[100];
    char cargoP[50];
    float PSalarial;
    int experiencia;
};

int inicializaCandidatos (Candidato candidatos [])
{
    int qtdCandidatos = 0;
    
    for (int i = 0 ; i < 200 ; i++) {
        printf ("ID: ");
        scanf ("%d", &candidatos[i].id);
        if (candidatos[i].id == 0){
            break;
        }
        printf ("nome: ");
        scanf ("%s", candidatos[i].nome);
        printf ("Cargo Pretendido: ");
        scanf ("%s", candidatos[i].cargoP);
        printf ("Pretensão Salarial: ");
        scanf ("%f", &candidatos[i].PSalarial);
        printf ("Anos de experiencia: ");
        scanf ("%d", &candidatos[i].experiencia);
        qtdCandidatos++;
    }
    return qtdCandidatos;
}

void OrdenaExibeCandidatos (Candidato candidatos[], int qtdCandidatos)
{
    int aux, pos, k;
    
    for (pos = 0 ; pos < (qtdCandidatos - 1) ; pos ++) {
        for (k = (pos + 1) ; k < qtdCandidatos ; k++) {
            if (candidatos[pos].experiencia < candidatos[k].experiencia) {
                aux = candidatos[k].experiencia;
                candidatos[k].experiencia = candidatos[pos].experiencia;
                candidatos[pos].experiencia = aux;
            }
        }
    }
    
    for (int i = 0 ; i < qtdCandidatos ; i++) {
        printf ("Nome: %s\n", candidatos[i].nome);
        printf ("Cargo Pretendido: %s\n", candidatos[i].cargoP);
        printf ("Pretensao salarial: R$%.2f\n", candidatos[i].PSalarial);
        printf ("Anos de experiencia: %d\n", candidatos[i].experiencia);
    }
}

int main ()
{
    Candidato candidatos [200];
    int qtdCandidatos;
    
    qtdCandidatos = inicializaCandidatos (candidatos);
    OrdenaExibeCandidatos (candidatos, qtdCandidatos);
    
    return 0;
}




