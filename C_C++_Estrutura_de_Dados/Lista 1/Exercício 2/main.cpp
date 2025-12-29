/*
2. Usando como referência a explicação do algoritmo a seguir, faça uma função que ordene um array com 20 
elementos inteiros. Informe a complexidade de pior caso do algoritmo desenvolvido.  
O algoritmo percorre todo o array e a cada comparação entre os elementos, verifica e, caso necessário, marca o menor 
valor da lista. Ao chegar no último elemento e após realizar a verificação final, coloca o menor elemento selecionado 
na primeira posição da lista. Depois, percorre o array e seleciona o segundo menor valor da lista seguindo a mesma 
regra, para colocá-lo na segunda posição. Faz isso com o terceiro menor valor da lista e assim sucessivamente até que 
todos os elementos da lista sejam usados e que a lista fique classificada em ordem crescente.  
*/

#include <iostream>
using namespace std;
#define qtd 10

void ordena (int * array) // Selection Sort
{
    int i, j, menor, aux;
    
    for (i = 0 ; i < qtd - 1 ; i++) {
        menor = i;
        
        for (j = i + 1 ; j < qtd ; j++) {
            if (array[menor] > array[j]) {
                menor = j;
            }
        }
        
        aux = array[i];
        array[i] = array[menor];
        array[menor] = aux;
    }
}

int main()
{
    int array[qtd] = {0, 4, 5, 1, 2, 3, 7, 9, 8, 6};
    
    ordena (array);
    
    cout << "Elementos ordenados: ";
    for (int i = 0 ; i < qtd ; i++) {
        cout << array[i];
        if (i < (qtd - 1)) cout << ",";
    }
    cout << ".";

    return 0;
}

/*
Resposta adjacente: 

A complexidade de pior caso é O(n^2) pois o array pode ser percorrido todo em cada etapa das comparações.
*/

