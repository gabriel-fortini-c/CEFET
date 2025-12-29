//Exercício 2 da lista de duplamente encadeada e circular

#include <iostream>
using namespace std;
#define T 5

struct no {
    int info;
    struct no * ant;
    struct no * prox;
};
typedef struct no * noPtr;

bool listaVazia (noPtr copiaTopo)
{
    if (copiaTopo) return false;
    else return true;
}

void inserir (noPtr * copiaTopo, noPtr * copiaUlt, int x) // inserir no ínico da lista
{
    noPtr p = new no;
    
    p->info = x;
    
    p->ant = NULL; // como é inserido no ínicio da lista, p->ant precisar ser NULL
    
    if (listaVazia (*copiaTopo)) {
        p->prox = NULL;
        *copiaUlt = p;  // Atualiza o ponteiro do último nó
    }
    else {
        p->prox = *copiaTopo;
        (*copiaTopo)->ant = p;
    }
    *copiaTopo = p;
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

int somar (noPtr);
int maior (noPtr, noPtr);
void intercala(noPtr , noPtr, noPtr *, noPtr *);
void inserirFinal(noPtr *, noPtr *, int );

int main ()
{
    int i, x;
    noPtr topoL1 = NULL, topoL2 = NULL;
    noPtr ultL1 = NULL, ultL2 = NULL;
    
    cout << "Exercício 2: \n\n";
    
    cout << "Introdução: \n";
    cout << "Insira " << T <<  " elementos na Lista 1" << endl;
    
    for (i = 0 ; i < T ; i++) {
        cout << i + 1 << "º elemento: ";
        cin >> x;
        inserir (&topoL1, &ultL1, x);
    }
    cout << "Listagem da lista 1: ";
    listar (topoL1);
    
    cout << "\n\nAgora insira " << T <<  " elementos na Lista 2" << endl;
    
    for (i = 0 ; i < T ; i++) {
        cout << i + 1 << "º elemento: ";
        cin >> x;
        inserir (&topoL2, &ultL2, x);
    }
    cout << "Listagem da lista 2: ";
    listar (topoL2);
    
    cout << "\n\nItens: \n";
    cout << "Item a) Somar elementos da lista 1: " << somar (topoL1) << endl;
    cout << "Item b) Somar elementos da lista 2: " << somar (topoL2) << endl;
    cout << "Item c) Maior elemento das listas juntas: " << maior (topoL1, topoL2) << endl;
    
    cout << "Item d) Lista 3 (intercalação de L1 e L2): ";
    noPtr topoL3 = NULL, ultL3 = NULL;
    intercala(topoL1, topoL2, &topoL3, &ultL3);
    listar(topoL3); 

}

int somar (noPtr p) // p é uma cópia do topo da lista
{
    int soma = 0;
    
    while (p != NULL) {
        soma += p->info;
        p = p->prox;
    }
    return soma;
}

int maior (noPtr p1, noPtr p2) // p1 e p2 são cópias dos topos das listas 
{
    int maior = 0;
    
    while (p1 != NULL) {
        if (maior == 0 || p1->info > maior) {
            maior = p1->info;
        }
        p1 = p1->prox;
    }
    while (p2 != NULL) {
        if (maior == 0 || p2->info > maior) {
            maior = p2->info;
        }
        p2 = p2->prox;
    }
    return maior;
}

void inserirFinal(noPtr *topo, noPtr *ult, int x) 
{
    noPtr p = new no;
    p->info = x;
    p->prox = NULL;
    p->ant = NULL;

    if (listaVazia(*topo)) {
        *topo = *ult = p;
    } else {
        (*ult)->prox = p;
        p->ant = *ult;
        *ult = p;
    }
}

void intercala(noPtr t1, noPtr t2, noPtr *t3, noPtr *ult3) {
    while (t1 != NULL || t2 != NULL) {
        if (t1 != NULL) {
            inserirFinal(t3, ult3, t1->info);
            t1 = t1->prox;
        }
        if (t2 != NULL) {
            inserirFinal(t3, ult3, t2->info);
            t2 = t2->prox;
        }
    }
}








