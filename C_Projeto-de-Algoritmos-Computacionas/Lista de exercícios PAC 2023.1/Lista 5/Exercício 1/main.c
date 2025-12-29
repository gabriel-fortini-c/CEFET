#include <stdio.h>

float processaDepartamento (int quantDownloads, float preco)
{
    float tamanho, pagamento, soma = 0;
    for (int i=0 ; i < quantDownloads ; i++) {
        printf ("Insira o tamanho de do Download: ");
        scanf ("%f", &tamanho);
        pagamento = tamanho * preco;
        soma += pagamento; 
    }
    printf ("O valor a ser pago por esse cliente é de R$%.2f\n\n", soma);
    return soma;
}

int main ()
{
    int contador = 0, quantDownloads = 1;
    float preco, valor, maior = 0, soma = 0, media;
    printf ("Insira o preço pro MByte: ");
    scanf ("%f", &preco);
    
    while (1) {
        printf ("Insira a quantidade de Downloads que o cliente fez (0 para encerrar): ");
        scanf ("%d", &quantDownloads);
        
        if (quantDownloads == 0) {
            break;
        }
        valor = processaDepartamento (quantDownloads, preco);
        soma += valor;
        contador++;
        
        if (valor > maior) {
            maior = valor;
        }
    }
    media = soma / contador;
    printf ("O maior valor a ser pago é R$%.2f\n", maior);
    printf ("A média dos valores a serem pagos é de R$%.2f\n", media);
    
    return 0;
}
