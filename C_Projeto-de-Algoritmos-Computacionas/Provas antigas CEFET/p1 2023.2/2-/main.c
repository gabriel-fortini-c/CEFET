#include <stdio.h>

int main ()
{
    int qtdNormais = 0, qtdSuspeitas = 0, qtdBloqueada = 0;
    float valor, soma = 0;
    
    printf ("Insira o valor da primeira transacao: ");
    scanf ("%f", &valor);
    qtdNormais++;
    soma += valor;
    
    while (qtdBloqueada == 0) {
        printf ("Insira o valor da proxima trasacao: ");
        scanf ("%f", &valor);
        
        if (valor < (soma / qtdNormais)*1.5) {
            printf ("Transacao normal.\n");
            qtdNormais++;
            soma += valor; 
        }
        else if (valor < (soma / qtdNormais)*2) {
            printf ("Transacao suspeita.\n");
            qtdSuspeitas++;
        }
        else {
            printf ("R$%.2f\n", valor);
            printf ("Transacao bloqueada.\n");
            qtdBloqueada++;
        }
    }
    printf ("Media das normais: R$%.2f\n", soma / qtdNormais);
    printf ("Normais: %d\nSuspeitas: %d\n", qtdNormais, qtdSuspeitas);
    
    return 0;
}