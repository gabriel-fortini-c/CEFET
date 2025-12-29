#include <stdio.h>

int leValidaClassificacao () 
{
    int tipo;
    
    do {
        printf ("Classificaçã: 1, 2, 3 ou 4\n");
        printf ("Insira a Classificação desse produto: ");
        scanf ("%d", &tipo);
        
        if (tipo < 1 || tipo > 4) {
            printf ("Escolha um opção válida!");
        }
    } while (tipo < 1 || tipo > 4);
    
    return tipo;
}

void classe (int tipo, int *qtdEstoqueMin, int *qtdEstoqueMax)
{
    switch (tipo) {
        case 1: 
        *qtdEstoqueMin = 100;
        *qtdEstoqueMax = 120;
        break;
        
        case 2: 
        *qtdEstoqueMin = 150;
        *qtdEstoqueMax = 180;
        break;
        
        case 3: 
        *qtdEstoqueMin = 200;
        *qtdEstoqueMax = 250;
        break;
        
        case 4: 
        *qtdEstoqueMin = 250;
        *qtdEstoqueMax = 300;
        break;
    }
}

void a (int qtdEstoqueMax, int qtdEstoqueMin) {
    
}

int main()
{
    int ordinal = 1, cod, tipo, qtdEstoqueMin = 0, qtdEstoqueMax = 0;
    
    for (int i = 0 ; i < 2 ; i++) {
        printf ("~~~~~~~~~~~~~~%dº~~~~~~~~~~~~~~\n", ordinal++);
        printf ("Insira o código do produto: ");
        scanf ("%d", &cod);
        
        tipo = leValidaClassificacao();
        
        classe (tipo, &qtdEstoqueMin, &qtdEstoqueMax);
        
        printf ("Código desse produto: %d\n", cod);
        printf ("A quantidade mínima em estoque é: %d\n", qtdEstoqueMin);
        printf ("A quantidade máxima em estoque é: %d\n\n", qtdEstoqueMax);
        
    }
    return 0;
}
