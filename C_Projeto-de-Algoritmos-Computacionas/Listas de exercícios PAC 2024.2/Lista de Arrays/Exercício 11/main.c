#include <stdio.h>

int busca (int v[], int qtd, int procurado)
{
    for (int i = 0 ; i < qtd ; i++) {
        if (procurado == v[i]) {
            return i;
        }
    }
    return -1;
}

int main ()
{
    int v[1000]; 
    int qtd = 0, ordinal = 1, resultado, procurado;
    
    for (int i = 0 ; i < 100 ; i++) {
        printf ("Insira o %d° elemento do array: ", ordinal++);
        scanf ("%d", &procurado);
        
        resultado = busca (v, qtd, procurado);
        
        if (resultado == -1) {
            v[qtd] = procurado;
            qtd++;
        }
    }
    
    printf ("Aqui vai a lista de números sem repetições: \n");
    
    for (int i = 0 ; i < 100 ; i++) {
            printf ("%d\n", v[i]);
    }
    
    return 0;
}