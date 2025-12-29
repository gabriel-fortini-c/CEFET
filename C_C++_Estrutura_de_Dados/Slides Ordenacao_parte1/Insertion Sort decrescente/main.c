#include <stdio.h>
#define qtd 5

void ordena (int f[]) //insertion sort
{
    int i, j, chave;
    
    for (i = 1 ; i < qtd ; i++) {
        chave = f[i];
        j = i - 1;
        
        while (j >= 0 && f[j] < chave) {
            f[j + 1] = f[j];
            j--;
        }
        
        f[j + 1] = chave;
    }
}

int main()
{
    int f[5] = {1, 2, 3, 4, 5};
    
    ordena(f);
    
    for (int i = 0 ; i < qtd ; i++) {
        printf ("%d\n", f[i]);
    }

    return 0;
}