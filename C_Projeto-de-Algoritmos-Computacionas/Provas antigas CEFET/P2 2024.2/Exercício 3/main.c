#include <stdio.h>
    void function(float passagem[32][32]){
        float maior_passagem = -1; 
        int indice_I = -1, indice_J = -1; 
    
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (i != j && passagem[i][j] > maior_passagem) { 
                maior_passagem = passagem[i][j];
                indice_I = i;
                indice_J = j;
            }
        }
    }
        
        printf("%d\n",indice_I);
        printf("%d",Indice_J);
    }
