#include <stdio.h>

float calculaPerifericos (int quantPerif)
{
    float precoPerif, soma = 0;
    for (int i = 0 ; i < quantPerif ; i++) {
        printf ("Insira o preço do periférico: ");
        scanf ("%f", &precoPerif);
        soma += precoPerif;
    }
    return soma;
}

int main()
{
    int codMod, quantPerif, semPerif = 0, vendas = 0;
    float precoMod = 0, precoPerif = 0, valorTotal = 0, media = 0;
    
    while (1) {
        printf("Qual o código do modelo? (0 para finalizar) ");
        scanf ("%d", &codMod);
        if (codMod == 0) {
            break;
        }
        printf("Qual o preço do modelo? ");
        scanf ("%f", &precoMod);
        printf("Quantos periféricos foram escolhidos? ");
        scanf ("%d", &quantPerif);
        precoPerif = calculaPerifericos(quantPerif);
        
        if (quantPerif == 0) {
            semPerif++;
        }
        
        valorTotal += precoMod + precoPerif;
        vendas++;
    }
    
    media = valorTotal / vendas;
    printf ("O números de compras sem periféricos adicionais foram: %d\n", semPerif);
    printf ("O valor média das vendas foi de: %g\n", media);
    
    return 0;
}