#include <stdio.h>

float retornaMaior (float v[], int qtd) 
{
    float maior = v[0];
    
    for (int i = 0 ; i < qtd ; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

int main() {
    int qtd;
    
    printf("Quantos números deseja inserir? ");
    scanf("%d", &qtd);

    float v[qtd];  // Declara o vetor com tamanho definido pelo usuário

    for (int i = 0; i < qtd; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%f", &v[i]);
    }

    printf("O maior número é: %.2f\n", retornaMaior(v, qtd));

    return 0;
}