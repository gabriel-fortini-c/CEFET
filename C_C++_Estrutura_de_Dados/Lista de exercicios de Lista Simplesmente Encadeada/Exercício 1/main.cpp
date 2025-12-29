/*1 - Implemente uma função que tenha como valor de retorno o comprimento de uma
lista encadeada, isto é, que calcule o número de nós de uma lista. */ 

#include <iostream>

struct no {
int info;
struct no * prox;
};
 
typedef struct no * noPtr;
noPtr topo = NULL;

int percorrerLista () 
{
    noPtr aux;
    int contador = 0;
    
    aux = topo;
    while (aux != NULL) {
        contador++;
        aux = aux -> prox;
    }
    
    
    return contador;
}