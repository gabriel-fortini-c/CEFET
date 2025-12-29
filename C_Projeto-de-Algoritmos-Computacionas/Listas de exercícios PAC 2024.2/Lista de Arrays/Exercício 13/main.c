#include <stdio.h>

typedef struct _Plano Plano;

struct _Plano {
    int cod;
    float valor;
    int minutos;
    float valorExcedente;
};

int lePlanos (Plano planos[])
{
    int qtdPlanos = 0, ordinal = 1;
    
    for (int i = 0 ; i < 20 ; i++) {
        printf ("~~~~~~~~~~~~~~ Plano %d ~~~~~~~~~~~~~~\n", ordinal++);
        printf ("Insira o código do plano: ");
        scanf ("%d", &planos[i].cod);
        
        if (planos[i].cod == 0) {
            break;
        }
        
        printf ("Insira o valor do plano: ");
        scanf ("%f", &planos[i].valor);
        printf ("Insira a quantidade de minutos livres do plano: ");
        scanf ("%d", &planos[i].minutos);
        printf ("Insira o valor dos minutos excedentes do plano: ");
        scanf ("%f", &planos[i].valorExcedente);
        
        qtdPlanos++;
    }
    
    return qtdPlanos;
}

void exibePlanos (int qtdPlanos, Plano planos[], int minDesejados)
{
    
    printf ("De acordo com os minutos desejados, temos esses planos: \n");
    
    for (int i = 0 ; i < qtdPlanos ; i++) {
        if (planos[i].minutos == minDesejados) {
            printf ("Plano %d pelo valor de R$%.2f\n", planos[i].cod, planos[i].valor);
            printf ("Valor dos minutos excedentes: %.2f\n", planos[i].valorExcedente);
            
            printf ("\n\n");
        }
    }
}

int main ()
{
    Plano planos[20];
    int minDesejados, qtdPlanos;
    
    qtdPlanos = lePlanos(planos);
    
    while (1) {
        printf ("\n\n\nInsira a quantidade de minutos desejadas: ");
        scanf ("%d", &minDesejados);
        
        if (minDesejados == 0) {
            break;
        }
        
        exibePlanos(qtdPlanos, planos, minDesejados);
    }
    printf ("Fim do programa!");
    
    return 0;
}


