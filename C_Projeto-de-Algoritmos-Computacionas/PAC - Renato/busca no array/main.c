#include <stdio.h>

void leArray (int v[], int qtdElementos)
{
    
    for (int i=0 ; i < qtdElementos ; i++) {
        printf ("Insira o número: ");
        scanf ("%d", &v[i]);
    }
}

int busca (int v[], int qtdElementos, int x)
{
    for (int i=0 ; i < qtdElementos ; i++) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main ()
{
    int x, v[1000] = {0};
    leArray (v, 5);
    printf ("Insira o valor de x para verificar no Array: ");
    scanf ("%d", &x);
    printf ("A posição é: %d", busca(v, 5, x));
    
    return 0;
}