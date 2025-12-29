/*
2. O algoritmo de ordenação é executado para organizar os elementos numa lista ou em ordem crescente ou 
em ordem decrescente. Usando como referência a explicação do algoritmo a seguir, faça a função que coloque em 
ordem decrescente um array com 50 elementos inteiros.  
O elemento que está na primeira posição do array é comparado com o segundo elemento. Se na comparação o 
elemento da primeira posição for menor, então é feita a troca entre eles. Novamente o elemento da primeira 
posição é comparado com o terceiro elemento e se o elemento da primeira posição for menor é feita a troca. Esse 
procedimento é feito até percorrer todo o array, ou seja, o primeiro elemento é comparado com os restantes. Ao 
final da primeira rodada, após todas as comparações e trocas, o maior valor estará na primeira posição. Na segunda 
rodada, o segundo elemento do array é comparado com o terceiro e se o segundo elemento for menor, então é 
feita a troca. Depois, o segundo elemento é comparado com o quarto elemento que está no vetor. Se o segundo 
elemento for menor, é feita a troca. Faz-se o mesmo processo com os próximos elementos e ao final da segunda 
rodada, após as comparações e possíveis trocas, o segundo maior elemento estará na segunda posição do array. 
Este processo é feito até alcançar o penúltimo elemento do array que será comparado com o último e, se o 
penúltimo elemento for menor, então é trocado com o último elemento. Ao final deste processo, o array estará 
ordenado de forma decrescente.  
*/
#include <iostream>
using namespace std;
#define n 50

void ordena (int array[]) // Buble Sort decrescente
{
    int i, j, aux;
    
    for (i = 0 ; i < n ; i++) {
        for (j = i + 1 ; j < n ; j++) {
            if (array[j] > array [i]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}





