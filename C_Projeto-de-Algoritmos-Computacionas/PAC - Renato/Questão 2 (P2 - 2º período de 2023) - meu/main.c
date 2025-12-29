#include <stdio.h>
#include <string.h>

int buscaUF (char ufs[27][3], char ufProcurada[])
{
    for (int i = 0 ; i < 27 ; i++) {
        if ( strcmp(ufs[i], ufProcurada) == 0) {
            return i;
        }
    }
    return -1;
}

void leTotaliza (int totais[14][27], char ufs[27][3]) 
{
    char uflida[3];
    int pos, anoNascimento;
    float peso;
    
    while (1) {
        printf ("Insira a UF: ");
        scanf (" %c", &uflida);
        pos = buscaUF (ufs, uflida);
        if (pos == -1) {
            break;
        }
        printf ("Insira o ano de nascimento: ");
        scanf ("%d", &anoNascimento);
        printf ("Insira o peso da crianca: ");
        scanf ("%f", &peso);
        
        if (peso < 2500) {
            totais[anoNascimento - 2010][pos]++;
        }
        
    }
}

void dadosAno (int totais[14][27], char ufs[3][27], int anoProcurado) 
{
    for (int i = 0 ; i < 27 ; i++) {
        printf ("UF: %s Quantidade abaixo do peso: %d", ufs[i], totais[anoProcurado - 2010][i]);
    }
}

void dadosUF (int totais [14][27], char ufs[3][27], char ufProcurada[])
{
    int pos = buscaUF (ufs, ufProcurada);
    if (pos == -1) {
        printf ("Nao encontrada.");
    }
    else {
        int contador = 0;
        for (int i = 0 ; i < 14 ; i++) {
            printf ("%d: %d nascidos abaixo do peso.", 2010+i, totais[i][pos]);
            contador += totais[i][pos];
        }
    printf ("Total: %d", contador);
    }
}

int main () 
{
    char ufs[27][3] = {
        "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA",
        "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN",
        "RS", "RO", "RR", "SC", "SP", "SE", "TO"
    };
    
    int totais[14][27];
    int ano;
    char uf[3];
    
    for (int i = 0 ; i < 14 ; i++) {
        for (int j = 0 ; j < 27 ; j++) {
            totais [i][j] = 0;
        }
    }
    
    leTotaliza(totais,ufs);
	scanf("%d",&ano);
	dadosAno(totais,ufs,ano);
	scanf(" %s",uf);
	dadosUF(totais,ufs,uf);
	return 0;
}