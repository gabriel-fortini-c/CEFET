/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void processa_passagens (int quantidade_compras)
{
    int codigo_comprador, quantidade_passagens, contador_maior_valor, ordinal=1;
    float valor, soma_cliente = 0, maior_valor = 0;
    for (int i=0; i<quantidade_compras; i++)
    {
        printf ("Insira o código do comprador e a quantidade de passagens por ele adquiridas: ");
        scanf ("%d %d", &codigo_comprador, &quantidade_passagens);
        soma_cliente = 0;
        for (int j=0; j< quantidade_passagens; j++)
        {
            printf ("Insira o valor da %dº passagem: ", ordinal);
            scanf ("%f", &valor);
            ordinal++;
            soma_cliente = soma_cliente + valor;
            if (soma_cliente > maior_valor)
            {
                contador_maior_valor = 1;
                maior_valor = soma_cliente;
            }
            else if (soma_cliente == maior_valor)
            {
                contador_maior_valor++;
            }
        }
    ordinal = 1;
    printf ("A soma do cliente é de: R$%g,00\n\n", soma_cliente);
    }
    
printf ("O maior valor foi de : R$%g, 00 e a quantidade de clientes com esse valor é : %d", maior_valor, contador_maior_valor);
}




int main ()
{
    int quantidade_compras;
    printf ("Insira a quantidade de compras realizadas: ");
    scanf ("%d", &quantidade_compras);
    processa_passagens (quantidade_compras);
}




