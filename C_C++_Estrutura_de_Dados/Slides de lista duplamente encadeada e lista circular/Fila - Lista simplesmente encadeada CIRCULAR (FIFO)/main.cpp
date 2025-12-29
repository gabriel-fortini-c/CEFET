// Lista Simplesmente Encadeada Circular - First In, First Out

#include <iostream>
using namespace std;

struct no {
    int info;
    struct no * prox;
};

typedef struct no * noPtr;
void inserir(noPtr *, noPtr *, int *);
void retirar(noPtr *, noPtr *, int *);
void listar(noPtr, int);
bool listaVazia(noPtr);
void menu();

int main ()
{
    menu ();
    
    return 0;
}

void menu ()
{
    noPtr topo = NULL;
    noPtr ult = NULL;
    int op, qtde = 0;
    
    cout << "Escolha dentre as opções (0 para finalizar): " << endl;
    cout << "1. Inserir elemento \n2. Retirar elemento \n3. Listar elementos" << endl;
    
    do {
        cout << "\nEscolha => ";
        cin >> op;
        switch(op) {
            case 1: inserir(&topo, &ult, &qtde);
            cout << "A lista possui " << qtde << "no(s). \n" << endl; break;
            case 2: retirar(&topo, &ult, &qtde); break;
            case 3: listar(topo, qtde); break;
        }
    } while (op !=0); 
}

void inserir (noPtr * inicio, noPtr *fim, int *q)
{
    noPtr p = new no;
    
    cout << "Insira o valor do elemento: ";
    cin >> p->info;
    
    if (*inicio == NULL) { // Caso a lista esteja vazia
        p->prox = p;
        *inicio = p;
        *fim = p;
    }
    else {
        p->prox = *inicio;   // novo nó aponta para o antigo primeiro nó
        (*fim)->prox = p;  // o último nó agora aponta para o novo primeiro nó (manter circularidade)
        *inicio = p; // atualiza o ponteiro de início para o novo nó inserido
    }
    (*q)++; // Atualiza o contador de elementos
}

void retirar (noPtr *inicio, noPtr * fim, int * q)
{
    noPtr apagar;
    
    if (!listaVazia (*inicio)) {
        if (*inicio == *fim) {
            apagar = *inicio;
            *inicio = NULL;
            *fim = NULL;
        }
        else {
            noPtr aux = *inicio; 
            while (aux->prox != *fim) { // encontra o último nó
                aux = aux->prox;
            }
            apagar = *fim;
            *fim = aux;
            (*fim)->prox = *inicio;
        }
        delete (apagar);
        (*q)--;
        cout << "Elemento mais antigo da lista retirado." << endl;
    }
    else cout << "A lista está vazia." << endl;
}

void listar (noPtr inicio, int q)
{
    if(!listaVazia(inicio)) {
        for (int i = 0; i < q; i++) {
            cout<< inicio->info << "\t";
            inicio = inicio->prox;
        }
    }
    else cout<< "Listavazia!" << endl;
}
bool listaVazia (noPtr copiaTopo)
{
    if (copiaTopo) 
        return false;
    else 
        return true;
}