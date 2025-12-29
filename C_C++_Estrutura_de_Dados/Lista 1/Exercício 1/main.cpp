/*
1. Usando como referência a explicação do algoritmo a seguir, faça uma função que ordene um array com 50 
elementos inteiros. Informe a complexidade de pior caso do algoritmo desenvolvido.  
O algoritmo percorre o array e a cada comparação entre os elementos, verifica e, caso necessário, troca o maior 
elemento com o menor. Ao chegar na última posição do array e após realizar a verificação final, o menor elemento 
estará na primeira posição da lista. Depois, percorre o array, realiza as comparações e caso necessário faz as trocas. 
Ao alcançar o final desta rodada, o segundo menor valor estará na segunda posição do array. Este procedimento é 
realizado sucessivamente, até que a lista esteja toda classificada em ordem crescente. 
*/

#include <iostream>
using namespace std;
#define qtd 10

void ordena (int * array) // buble sort
{
    int i, j, aux;
    
    for (i = 0 ; i < qtd ; i++) {
        for (j = (i + 1) ; j < qtd ; j++) {
            if (array[j] < array[i]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
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

A complexidade de pior caso é O(n^2) pois para cada elemento percorrido ele compara com todos os outros.
*/






