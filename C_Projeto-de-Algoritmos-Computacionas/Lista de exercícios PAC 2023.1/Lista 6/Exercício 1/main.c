#include <stdio.h>

int leValidaTipo () 
{
    int tipo;
    
    do {
        printf ("1- Fruta \n2- Legume \n3- Verdura \n");
        printf ("Qual tipo do produto? ");
        scanf ("%d", &tipo);
        
        if (tipo < 1 || tipo > 3) {
            printf ("Escolha uma opcao valida!");
        }
    } while (tipo < 1 || tipo > 3);
    
    return tipo;
}

void leProdutos (int qtd, int *qtdFrutas, int *qtdLegumes, int *qtdVerduras) 
{
    int i, cod, tipo, ordinal = 1;
    for (i=0 ; i < qtd ; i++) {
        printf ("Insira do codigo do %dº produto: ", ordinal++);
        scanf ("%d", &cod);
        tipo = leValidaTipo();
        
        if (tipo == 1) {
            (*qtdFrutas)++;
        }
        if (tipo == 2) {
            (*qtdLegumes)++;
        }
        if (tipo == 3) {
            (*qtdVerduras)++;
        }
    }
}

int main ()
{
    int qtd, qtdFrutas = 0, qtdLegumes = 0, qtdVerduras = 0;
    
    printf ("Insira a quantidade de produtos comercializados: ");
    scanf ("%d", &qtd);
    leProdutos(qtd, &qtdFrutas, &qtdLegumes, &qtdVerduras);
    
    printf ("A quantidade de Frutas foi de: %d\n", qtdFrutas);
    printf ("A quantidade de Legumes foi de: %d\n", qtdLegumes);
    printf ("A quantidade de Verduras foi de: %d\n", qtdVerduras);
    
    return 0;
}