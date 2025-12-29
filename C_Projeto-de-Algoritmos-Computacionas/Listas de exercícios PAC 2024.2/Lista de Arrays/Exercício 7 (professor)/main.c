#include <stdio.h>

typedef struct _Cliente Cliente;

struct _Cliente {
    int numeroConta;
    float saldo;
};

void exibe (Cliente clientes[], int qtd, float saldoMedio)
{
    for (int i = 0 ; i < qtd ; i++) {
        printf ("%d %f", clientes[i].numeroConta, clientes[i].saldo);
        if (clientes[i].saldo == saldoMedio) {
            printf ("Na média!");
        }
        else if (clientes[i].saldo < saldoMedio) {
            printf ("Abaixo da média");
        }
        else if (clientes[i].saldo > saldoMedio) {
            printf ("Acima da média");
        }
    }
}

int main ()
{
    Cliente clientes[10573];
    int i = 0;
    float soma = 0;

    scanf ("%d", &clientes[i].numeroConta);
    while (clientes[i].numeroConta != 0) {
        scanf ("%f", &clientes[i].saldo);
        soma += clientes[i].numeroConta;
        i++;
        scanf ("%d", &clientes[i].numeroConta);
        
    }
    float media = soma / i;
    exibe (clientes, i, media);
    
    return 0;
}