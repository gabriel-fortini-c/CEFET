#include <stdio.h>
#include <string.h>

int buscaUF(char ufs[27][3], char ufProcurada[]) {
	for(int i=0; i<27; i++) {
		if(strcmp(ufs[i],ufProcurada)==0) {
			return i;
		}
	}
	return -1;
}

void leTotaliza(int totais[14][27], char ufs[27][3]) {
	char ufLida[3];
	int anoNascimento;
	float peso;
	scanf(" %s",ufLida);
	int pos = buscaUF(ufs,ufLida);
	while(pos != -1) {
		scanf("%d%f",&anoNascimento,&peso);
		if(peso < 2500) {
			totais[anoNascimento-2010][pos]++;
		}
		scanf(" %s",ufLida);
		pos = buscaUF(ufs,ufLida);	
	}
}

void dadosAno(int totais[14][27], char ufs[27][3], int anoProcurado) {
	for(int i=0; i<27; i++) {
		printf("%s %d\n",ufs[i],totais[anoProcurado-2010][i]);
	}
}

void dadosUF(int totais[14][27], char ufs[27][3], char ufProcurada[]) {
	int pos = buscaUF(ufs,ufProcurada);
	if(pos == -1) {
		printf("Nao Encontrado");
	}
	else {
		int contador = 0;
		for(int i=0; i<14; i++) {
			printf("%d %d\n",2010+i,totais[i][pos]);
			contador += totais[i][pos];
		}
		printf("%d\n",contador);
	}
}

int main() {

	char ufs[][3] = { "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO" };
	int totais[14][27];
	int ano;
	char uf[3];
	
	for(int i=0; i<14; i++) {
		for(int j=0; j<27; j++) {
			totais[i][j]=0;
		}
	}
	
	leTotaliza(totais,ufs);
	scanf("%d",&ano);
	dadosAno(totais,ufs,ano);
	scanf(" %s",uf);
	dadosUF(totais,ufs,uf);
	return 0;
}





