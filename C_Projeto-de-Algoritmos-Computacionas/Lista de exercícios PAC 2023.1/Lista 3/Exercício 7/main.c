#include <stdio.h>

void pagamento_dinheiro (float despesa)
{
    float valorPago;
    printf ("Insira o valor pago: ");
    scanf ("%f", &valorPago);
    if (valorPago == despesa) {
        printf ("Não há troco.");
    }
    else {
        printf ("O valor do troco é de: R$%.02f", valorPago - despesa);
    }
}

int main ()
{
    float despesa;
    char formaPagamento;
    printf ("Valor da despesa: ");
    scanf ("%f", &despesa);
    printf ("\nForma de pagamento: Débito (D), Crédito (C) ou dinheiro (N): ");
    scanf (" %c", &formaPagamento);
    
    if (formaPagamento == 'D' || formaPagamento == 'C') {
        printf ("Não há troco.\n");
    }
    if (formaPagamento == 'N') {
        pagamento_dinheiro (despesa);
    }
    
    return 0;
}