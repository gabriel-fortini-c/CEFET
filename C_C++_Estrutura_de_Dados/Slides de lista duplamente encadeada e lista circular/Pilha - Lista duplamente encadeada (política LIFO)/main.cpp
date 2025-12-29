// Lista duplamente encadeada - Last In, First Out

#include <iostream>
using namespace std;

struct no {
    int info;
    struct no * ant;
    struct no * prox;
};
typedef struct no * noPtr;
void inserir (noPtr *);
void retirar (noPtr *);
void listar (noPtr);
bool listaVazia (noPtr);
void menu ();

int main()
{
    menu ();
    
    return 0;
}

void menu ()
{
    noPtr topo = NULL;
    int op;
    
    cout << "Escolha dentre as opções (0 para finalizar): " << endl;
    cout << "1. Inserir elemento \n2. Retirar elemento \n3. Listar elementos" << endl;
    do {
        cout << "Escolha => ";
        cin >> op;
        
        switch (op) {
            case 1: inserir (&topo); break;
            case 2: retirar (&topo); break;
            case 3: listar (topo); break;
        }
    } while (op != 0);
}

void inserir (noPtr * copiaTopo) // inserir no ínico da lista
{
    noPtr p = new no;
    
    cout << "Insira o valor do elemento: ";
    cin >> p->info;
    
    p->ant = NULL; // como é inserido no ínicio da lista, p->ant precisar ser NULL
    
    if (listaVazia (*copiaTopo)) {
        p->prox = NULL;
    }
    else {
        p->prox = *copiaTopo; 
        (*copiaTopo)->ant = p;
    }
    *copiaTopo = p;
}

void retirar (noPtr * copiaTopo)
{
    noPtr p = (*copiaTopo);
    
    if (!listaVazia (*copiaTopo)) {
        if (p->prox == NULL) { //caso haja apenas um elemento na lista
            *copiaTopo = NULL;
        }
        else {
            *copiaTopo = (*copiaTopo)->prox; // *copiaTopo = p->prox;
            (*copiaTopo)->ant = NULL; // p->prox->ant = NULL;
        }
        delete(p);
        cout << "Elemento mais recentemente adicionado da lista retirado." << endl;
    }
    else
        cout << "A lista está vazia." << endl;
}

void listar (noPtr p)
{
    if (!listaVazia(p)) {
        cout << "Elementos da lista: " << endl;
        cout << "INICIO";
        
        while (p != NULL) {
            cout << "-->" << p->info;
            p = p->prox;
        }
        cout << "-->NULL" << endl;
    }
    else
        cout << "Lista vazia." << endl;
}

bool listaVazia (noPtr copiaTopo)
{
    if (copiaTopo) 
        return false;
    else 
        return true;
}






