#include <iostream>
using namespace std;

struct no { // nós da lista
    int info;
    struct no * prox;
};

typedef struct no * noPtr; // apelido para ponteiros para struct noPtr
noPtr topo = NULL; // ponteiro para o primeiro elemento da lista

bool listaVazia ()
{
    if (topo) 
        return false;
    else
        return true;
}

void pop () // desempilha
{
    noPtr p = topo;
    if (!listaVazia()) {
        topo = topo -> prox;
        delete (p);
        cout << "\nO último elemento da lista foi removido." << endl;
    }
    else {
        cout << "A lista está vazia." << endl;
    }
}

void push () // empilhar
{
    noPtr p;
    int valor;
    
    p = new(struct no);
    cout << "Insira um valor: ";
    cin >> valor;
    p -> info = valor;
    p -> prox = topo; 
    topo = p; 
    cout << "O valor " << valor << " foi inserido na lista" << endl;
}

int main()
{
    int op;
    
    do {
        cout << "Escolha uma dentro das opções" << endl;
        cout << "1. Inserir um elemento \n2. Remover um elemento \n0. Encerrar e exibir a lista" << endl;
        cout << "O que você quer fazer? ";
        cin >> op;
        
        switch (op) {
            case 1: push(); break;
            case 2: pop(); break;
        } 
    } while (op != 0);
    
    noPtr p = topo;
    cout << "Elementos da Pilha: ";
    while (p != NULL) {
        cout << p -> info << endl;
        p = p -> prox;
    }

    return 0;
}