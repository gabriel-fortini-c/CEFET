#include <stdio.h>

typedef struct _SPC SPC;

struct _SPC {
	int cpf;
	int meses;
};

int leitura_SPC (SPC pessoas[])
{
	int qtdInadimplentes = 0, ordinal = 1;

	for (int i = 0 ; i < 1000 ; i ++) {
		printf ("~~~~~~~~~~~~~ %dª Pessoa ~~~~~~~~~~~~~\n", ordinal++);
		printf ("Insira o CPF da pessoa: ");
		scanf ("%d", &pessoas[i].cpf);
		
		if (pessoas[i].cpf == 0) {
		    break;
		}
		
		printf ("A quantos meses ela está inadimplente? ");
        scanf ("%d", &pessoas[i].meses);
        
        qtdInadimplentes++;
	}
	
	return qtdInadimplentes;
}

int busca (SPC pessoas[], int qtd, int procurado)
{
    for (int i = 0 ; i < qtd ; i++) {
        if (procurado == pessoas[i].cpf) {
            return i;
        }
    }
    return -1;
}

int main ()
{
    SPC pessoas[1000];
    int cpf, codProduto, qtdComprada;
    float precoUnitario;
    int qtdInadimplentes;
    
    qtdInadimplentes = leitura_SPC(pessoas);
    
    for (int i = 0 ; i < 50 ; i++) {
        printf ("Insira o CPF do cliente: ");
        scanf ("%d", &cpf);
        
        int resultado = busca (pessoas, qtdInadimplentes, cpf);
        
        if (resultado == -1) {
            float soma = 0;
            while (1) {
                printf ("Insira o código do produto: ");
                scanf ("%d", &codProduto);
                
                if (codProduto == 0) {
                    break;
                }
                
                printf ("Insira a quantidade desse produto comprada: ");
                scanf ("%d", &qtdComprada);
                printf ("Insira o preço unitário do produto: ");
                scanf ("%f", &precoUnitario);
                
                int total =  precoUnitario * qtdComprada;
                soma += total;
            }
            printf ("Valor a ser pago: R$%.2f\n", soma);
        }
        else {
            printf ("Venda cancelada. Cliente inadimplente a %d meses\n", pessoas[resultado].meses);
        }
    }
    
    return 0;
}

