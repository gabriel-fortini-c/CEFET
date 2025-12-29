/*
3. Considere um algoritmo de ordenação que percorra um array de números inteiros da esquerda para a direita 
conforme o esquema de funcionamento a seguir.

(Ver imagem e explicação no PDF)

Usando como referência a explicação anterior do algoritmo de ordenação, que parece com o embaralhamento de 
cartas, faça uma função que ordene um array com 10 elementos inteiros. Informe também a complexidade de pior 
caso do algoritmo criado. 
*/

#include <iostream>
using namespace std;
#define qtd 10

void ordena (int * array) // Insertion Sort
{
    int i, j, aux;
    
    for (i = 1 ; i < qtd ; i++) {
        aux = array[i];
        j = i - 1;
        
        while ((j >= 0) && (array[j] > aux)) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = aux;
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

A complexidade de pior caso será O(n^2) pois o array pode percorrer todo array em cada comparação.
*/


