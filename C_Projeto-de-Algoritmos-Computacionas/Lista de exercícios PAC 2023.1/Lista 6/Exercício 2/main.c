#include <stdio.h>

char classificaTipo (char tipo, int *qtdNacionais, int *qtdImportados)
{
    do {
        printf ("Insira o tipo do produto \nNacional (N) ou Importado (I) \n->");
        scanf (" %c", &tipo);
        if (tipo != 'N' && tipo != 'I') {
            printf ("Escolha uma opcao valida!");
        }
    } while (tipo != 'N' && tipo != 'I');
    
        
    if (tipo == 'N') {
        (*qtdNacionais)++;
    } 
    else if (tipo == 'I'){
        (*qtdImportados)++;
    }
    
    return tipo;
}

int main ()
{
    int cod, qtdEstoque, qtdNacionais = 0, qtdImportados = 0, ordinal = 1;
    char tipo;
    float precoUni, valorEstoque;
    
    for (int i = 0 ; i < 40 ; i++) {
        printf ("~~~~%dº Produto~~~~\n", ordinal++);
        printf ("Insira o codigo do produto: ");
        scanf ("%d", &cod);
        tipo = classificaTipo (tipo, &qtdNacionais, &qtdImportados);
        printf ("Insira a quantidade em estoque: ");
        scanf ("%d", &qtdEstoque);
        printf ("Insira o preco unitario do produto: ");
        scanf ("%f", &precoUni);
        
        valorEstoque = (qtdEstoque * precoUni);
        
        printf ("\nCodigo do produto: %d\n", cod);
        printf ("Tipo do produto: %s\n", (tipo == 'N') ? "Nacional" : "Importado");
        printf ("Valor em estoque: R$%.2f\n\n", valorEstoque);
    }
    printf ("A quantidade de produtos nacionais foi de: %d\n", qtdNacionais);
    printf ("A quantidade de produtos importado foi de: %d", qtdImportados);
    
    return 0;
}