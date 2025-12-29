#include <stdio.h>

void insertionSort (int V[], int qtd)
{
    int i, j, chave;
    
    for (i = 1 ; i < qtd ; i++) {
        chave = V[i];
        j = i - 1;
        
        while (j >= 0 && V[j] > chave) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = chave;
    }
}

int main()
{
    int V[7] = {4, 6, 1 ,7 ,3, 2, 9};
    int A[7] = {1, 2, 3, 4, 5, 6, 7};
    int qtd = 7;
    
    insertionSort (V, qtd);
    insertionSort (A, qtd);
    
    for (int i = 0 ; i < qtd ; i++) {
        printf ("%d° elemento: %d\n", i + 1, V[i]);
    }
    printf ("\n");
    for (int i = 0 ; i < qtd ; i++) {
        printf ("%d° elemento: %d\n", i + 1, A[i]);
    }
}