/*
2. Considere listas encadeadas de valores inteiros e implemente uma função para retornar o número de nós da lista 
que possuem o campo info com valores maiores que N. Peça ao usuário para informar o valor de N.  
*/

#include <iostream>
using namespace std;

struct no {
    int num;
    struct no * prox;
};

typedef struct no * noPtr;

noPtr topo = NULL;

int procurar (int valor)
{
    noPtr aux = topo;
    int contador = 0;
    
    while (aux != NULL) {
        if (aux -> info > valor) {
            contador++;
        }
        aux = aux -> prox;
    }
    return contador;
}

int main()
{
    int valor, qtd;
    
    cout << "Insira um valor para saber quantos elementos da lista são maiores que ele: ";
    cin >> valor;
    
    qtd = procurar (valor);
    
    cout << "Quantidade de elementos maiores que " << valor << ":" << qtd << endl;

    return 0;
}