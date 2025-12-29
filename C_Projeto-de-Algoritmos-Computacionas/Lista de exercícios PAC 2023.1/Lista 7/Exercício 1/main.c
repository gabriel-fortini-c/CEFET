#include <stdio.h>

int produtoArray (int array[], int qtd) 
{
    int produto = 1;
    for (int i = 0 ; i < qtd ; i++) {
        produto *= array[i];
    }
    
    return produto;
}

int main ()
{
    int ordinal = 1, valor;
    int array[5];
    for (int i = 0 ; i < 5 ; i++) {
        printf ("Insira o valor do %dº elemento do array: ", ordinal++);
        scanf ("%d", &valor);
        array[i] = valor;
    }
    
    printf ("O produto é: %d", produtoArray(array, 5));
    
    return 0;
}
