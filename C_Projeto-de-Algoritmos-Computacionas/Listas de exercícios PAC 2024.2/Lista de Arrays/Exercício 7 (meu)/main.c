#include <stdio.h>

typedef struct _Cliente Cliente;

struct _Cliente {
    int numConta;
    float saldo;
};

void exibe (Cliente clientes[], int qtdClientes, float saldoMedio)
{
    int i, ordinal = 1;
    for (i = 0 ; i < qtdClientes ; i++) {
        printf ("~~~~~~~~~~~~~~~ DADOS DO %dº CLIENTE ~~~~~~~~~~~~~~~\n", ordinal++);
        printf ("Número da conta: %d\n", clientes[i].numConta);
        printf ("Saldo da conta: R$%.2f\n", clientes[i].saldo);
        
        if (clientes[i].saldo == saldoMedio) {
            printf ("O saldo é igual ao saldo médio.\n\n");
        }
        else if (clientes[i].saldo > saldoMedio) {
            printf ("O saldo é maior que o saldo médio.\n\n");
        }
        else {
            printf ("O saldo é menor que o saldo médio.\n\n");
        }
        
    }
}

int main ()
{
    int i, qtdClientes = 0, ordinal = 1;
    float saldo, soma = 0, saldoMedio;
    Cliente clientes[10573];
    
    while (1) {
        printf ("~~~~~~~~~~~~~~~ PREENCHA OS DADOS DO %dº CLIENTE ~~~~~~~~~~~~~~~\n", ordinal++);
        printf ("Insira o número da conta do cliente (0 para terminar): ");
        scanf ("%d", &clientes[qtdClientes].numConta);
        if (clientes[qtdClientes].numConta == 0) {
            break;
        }
        
        printf ("Insira o saldo do cliente: ");
        scanf ("%f", &clientes[qtdClientes].saldo);
        
        soma += clientes[qtdClientes].saldo;
        qtdClientes++;
    }
    
    if (qtdClientes > 0) {
        saldoMedio = soma / qtdClientes;
        exibe (clientes, qtdClientes, saldoMedio);
    }
    else if (clientes[qtdClientes].numConta == 0) {
        printf ("Nenhum cliente foi inserido.\n");
    }
    
    return 0;
}