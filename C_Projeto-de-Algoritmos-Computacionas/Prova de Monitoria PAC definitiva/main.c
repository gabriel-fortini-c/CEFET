#include <stdio.h>
#include <string.h>

typedef struct _Cliente Cliente;

struct _Cliente {
    int codCliente;
    char nome[30];
};

typedef struct _Movimentacoes Movimentacoes;

struct _Movimentacoes {
    int codCliente;
    char codOp;
    int codInvest;
    float valor;
};

int leDadosClientes(Cliente clientes[], float matrizValores[][3]) {
    int i = 0;
    
    printf("\n~~~~~~~~~~~~~~~~ Leitura de clientes ~~~~~~~~~~~~~~~~\n");
    
    do {
        printf("Insira o código do cliente (-1 para encerrar): ");
        scanf("%d", &clientes[i].codCliente);
        
        if (clientes[i].codCliente == -1) {
            return i;
        }
        
        printf("Insira o nome do cliente: "); 
        scanf(" %[^\n]", clientes[i].nome);
        
        printf("Insira o valor atual no investimento 1: ");
        scanf("%f", &matrizValores[i][0]);
        
        printf("Insira o valor atual no investimento 2: ");
        scanf("%f", &matrizValores[i][1]);
        
        printf("Insira o valor atual no investimento 3: ");
        scanf("%f", &matrizValores[i][2]);
        
        i++;
    } while (i < 6000);
    
    return i;
}

int busca(Cliente clientes[], int codProcurado, int qtdClientes) {
    int i = 0;
    
    for (i = 0; i < qtdClientes; i++) {
        if (codProcurado == clientes[i].codCliente) {
            return i;
        }
    }
    
    return -1;
}

void ordenaClientes(Cliente clientes[], int qtdClientes, float matrizValores[][3]) {
    int i, k;
    Cliente aux;
    float auxValores[3];
    
    for (i = 0; i < (qtdClientes - 1); i++) {
        for (k = i + 1; k < qtdClientes; k++) {
            if (strcmp(clientes[i].nome, clientes[k].nome) > 0) {
                aux = clientes[i];
                clientes[i] = clientes[k];
                clientes[k] = aux;
                
                memcpy(auxValores, matrizValores[i], sizeof(auxValores));
                memcpy(matrizValores[i], matrizValores[k], sizeof(auxValores));
                memcpy(matrizValores[k], auxValores, sizeof(auxValores));
            }
        }
    }
}

void emitirRelatorio(Cliente clientes[], int qtdClientes, float matrizValores[][3], float valorTransNaoRealizada) {
    int i;
    
    printf("\n\n\n| %-20s | %-6s | %-10s | %-10s | %-10s |\n", "Nome", "Codigo", "Valor Ap.1", "Valor Ap.2", "Valor Ap.3");
    printf("|----------------------|--------|------------|------------|------------|\n");
    
    for (i = 0; i < qtdClientes; i++) {
        printf("| %-20s | %-6d | %-10.2f | %-10.2f | %-10.2f |\n", 
               clientes[i].nome, 
               clientes[i].codCliente, 
               matrizValores[i][0], 
               matrizValores[i][1], 
               matrizValores[i][2]);
    }
    printf("Valor total das operações não realizadas: %.2f\n\n\n", valorTransNaoRealizada);
}

void exibeZerados(Cliente clientes[], int qtdClientes, float matrizValores[][3]) {
    int i;
    
    printf("\nCliente(s) com todas as aplicações zeradas: \n\n");
    
    for (i = 0; i < qtdClientes; i++) {
        if (matrizValores[i][0] == 0 && matrizValores[i][1] == 0 && matrizValores[i][2] == 0) {
            printf("%s \n\n", clientes[i].nome);
        }
    }
}

void exibeMaior(Cliente clientes[], int qtdClientes, float matrizValores[][3]) {
    int i;
    int indiceMaior = 0;
    float soma = 0, maior = 0;
    
    for (i = 0; i < qtdClientes; i++) {
        soma = matrizValores[i][0] + matrizValores[i][1] + matrizValores[i][2];
        
        if (soma >= maior) {
            maior = soma;
            indiceMaior = i;
        }
    }
    
    printf("\nCliente com maior valor aplicado: \n");
    printf("Nome: %s \n", clientes[indiceMaior].nome);
    printf("Valor total aplicado: %.2f\n", maior);
}

float processarMovimentacoes(Movimentacoes mov[], Cliente clientes[], float matrizValores[][3], int qtdClientes) {
    int ordinal = 1, i = 0, qtdErro, resultado;
    float valorTransNaoRealizada = 0;
    
    printf("\n\n\n~~~~~~~~~~~~~~~ Processo de Movimentações ~~~~~~~~~~~~~~~\n");
    
    do {
        printf("~~~~~~~~~~~~ %dª Movimentação ~~~~~~~~~~~~\n", ordinal++);
        
        qtdErro = 0;
        
        printf("Insira o código do cliente (-1 para finalizar): ");
        scanf("%d", &mov[i].codCliente);
        
        if (mov[i].codCliente == -1) {
            break;
        }
        
        resultado = busca(clientes, mov[i].codCliente, qtdClientes);
        if (resultado == -1) {
            printf("Código de cliente inválido!\n");
            qtdErro++;
        }
        
        printf("\nQual operação desejas? ('A' para aplicação e 'R' para Resgate): ");
        scanf(" %c", &mov[i].codOp);
        if (mov[i].codOp != 'A' && mov[i].codOp != 'R') {
            printf("Código de operação inválido!\n");
            qtdErro++;
        }
        
        printf("\nQual dos tipos de investimento desejas realizar essa operação? (1, 2 ou 3): ");
        scanf("%d", &mov[i].codInvest);
        if (mov[i].codInvest < 1 || mov[i].codInvest > 3) {
            printf("Código de investimento Inválido!\n");
            qtdErro++;
        }
        
        printf("\nQual o valor que desejas para essa operação? ");
        scanf("%f", &mov[i].valor);
        if (mov[i].codOp == 'R') {
            if (mov[i].valor > matrizValores[resultado][mov[i].codInvest - 1]) {
                printf("Saldo insuficiente!\n");
                qtdErro++;
            }
        }
        
        if (qtdErro > 0) {
            printf("\n*Operação não realizada*: Cliente %d, Operação %c, Investimento %d, Valor %.2f\n",
                   mov[i].codCliente, mov[i].codOp, mov[i].codInvest, mov[i].valor);
            valorTransNaoRealizada += mov[i].valor;
        } 
        else {
            if (mov[i].codOp == 'A') {
                matrizValores[resultado][mov[i].codInvest - 1] += mov[i].valor;
            } else if (mov[i].codOp == 'R') {
                matrizValores[resultado][mov[i].codInvest - 1] -= mov[i].valor;
            }       
        }   
        
        i++;
    } while (i < 60000);
    
    return valorTransNaoRealizada;
}

int main() {
    Cliente clientes[6000];
    Movimentacoes mov[60000];
    int qtdClientes;
    float matrizValores[6000][3];
    float valorTransNaoRealizada;
    
    qtdClientes = leDadosClientes(clientes, matrizValores);
    
    valorTransNaoRealizada = processarMovimentacoes(mov, clientes, matrizValores, qtdClientes);
    
    ordenaClientes(clientes, qtdClientes, matrizValores);
    
    emitirRelatorio(clientes, qtdClientes, matrizValores, valorTransNaoRealizada);
    
    exibeZerados(clientes, qtdClientes, matrizValores);
    
    exibeMaior(clientes, qtdClientes, matrizValores);
    
    return 0;
}