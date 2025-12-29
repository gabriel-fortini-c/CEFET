/*
1. Você precisa gerenciar o armazenamento dos contatos de um dispositivo e ficou definido que para incluir um 
novo contato, este deverá ser alocado sempre no final da lista. Como o espaço no dispositivo é restrito, então 
algumas vezes é necessário apagar alguns contatos, neste caso, sempre o primeiro que entrou é removido. Para 
simular este gerenciamento, você deverá implementar as funções a seguir, com complexidade de pior caso O(1), 
usando uma lista simplesmente encadeada que siga exatamente a política citada. 
• Adicionar: incluir um novo contato conforme a explicação acima. Considere que o contato seja um 
número inteiro.  
• Remover: retirar o contato que está a mais tempo na lista.   
Utilize como base a struct: 
struct contato 
{ 
int num; 
struct endereco* prox; 
}; 
*/

#include <iostream>
using namespace std;

struct contato { 
    int num; 
    struct contato * prox; 
};

typedef struct contato * noContato;

noContato inicio = NULL;
noContato final = NULL;

void adicionar ()
{
    noContato X = new (struct contato);
    cout << "Insira um novo contato: ";
    cin >> X -> num;
    X -> prox = NULL;
    
    if (inicio == NULL) {
        inicio = X;
        final = X;
    } else {
        final->prox = X;
        final = X;
    }
}

void remover ()
{
    if (inicio == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }
    
    noContato X = inicio;
    inicio = inicio -> prox;
    
    if (inicio == NULL)
        final = NULL; // A lista ficou vazia
    
    delete (X);
