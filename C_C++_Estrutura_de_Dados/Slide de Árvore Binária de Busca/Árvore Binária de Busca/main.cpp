#include <iostream>
using namespace std;
struct no {
    int info;
    struct no * esq, * dir;
};

typedef struct no * noPtr;

int menu();
int listarNos();
void inserir(noPtr *, int);
void remover(noPtr *, int);
void buscar(noPtr, int);
noPtr maior(noPtr *);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
bool enderecoVazio(noPtr);

int main()
{
    int op1, op2, x;
    noPtr raiz = NULL;
    
    do {
        op1 = menu();
        
        switch (op1) {
            case 1: cout << "Elemento a inserir: ";
                    cin >> x;
                    inserir (&raiz, x);
                    break;
            case 2: cout << "Elemento a remover: ";
                    cin >> x;
                    remover (&raiz, x);
                    break;
            case 3: op2 = listarNos();
                    if (op2 == 1) listarEmOrdem(raiz);
                    if (op2 == 2) listarPreOrdem(raiz);
                    if (op2 == 3) listarPosOrdem(raiz);
                    cout << "\n" << endl;
                    break;
            case 4: cout << "Elemento a buscar: ";
                    cin >> x;
                    buscar (raiz, x);
                    break;
        }
    } while (op1 != 0);

    return 0;
}

int menu ()
{
    int opcao;
    cout << "---- Menu Principal ----\n\n"
        << "\n1.Inserir no na arvore"
        << "\n2.Remover no na arvore"
        << "\n3.Listar todos os nos da arvore"
        << "\n4.Buscar no"
        << "\n0.Sair"
        << "\nDigite uma opcao: ";
    cin >> opcao;
    return opcao;
}

int listarNos()
{
    int opcao;
    cout << "\nTipos de listagem:"
        << "\n1.Em Ordem"
        << "\n2.Pre Ordem"
        << "\n3.Pos Ordem"
        << "\n\nEscolha o tipo de listagem: ";
    cin >> opcao;
    return opcao;
}

void inserir(noPtr * p, int x)
{
    if (enderecoVazio(*p)) {
        (*p) = new no;
        (*p)->info = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
    }
    else {
        if (x < (*p)->info) 
            inserir (&(*p)->esq, x);
        else 
            inserir (&(*p)->dir, x);
    }
}

void buscar (noPtr p, int x)
{
    if (enderecoVazio(p))
        cout << "A árvore não possui elementos" << endl;
    else {
        if (x == p->info) {
            cout << "Elemento " << p->info << " encontrado!" << endl;
        }
        else {
            if (x < p->info)
                buscar (p->esq, x);
            else
                buscar (p->dir, x);
        }
    }
}

// formas de listar: 
void listarEmOrdem(noPtr p) 
{
    if (!enderecoVazio(p)) {
        listarEmOrdem(p->esq);
        cout << "\t" << p->info;
        listarEmOrdem(p->dir);
    }
}

void listarPreOrdem(noPtr p) 
{
    if (!enderecoVazio(p)) {
        cout << "\t" << p->info;
        listarPreOrdem(p->esq);
        listarPreOrdem(p->dir);
    }
}

void listarPosOrdem(noPtr p) 
{
    if (!enderecoVazio(p)) {
        listarPosOrdem(p->esq);
        listarPosOrdem(p->dir);
        cout << "\t" << p->info;
    }
}

void remover (noPtr * p, int x)
{
    noPtr aux;
    
    if (!enderecoVazio(*p)) {
        if (x == (*p)->info) {
            aux = *p;
            
            if ((*p)->esq == NULL) { // se nao tem filho na esquerda, o no da direita vira pai
                *p = (*p)->dir;
            }   
            else { // se tiver filho na esquerda
                if ((*p)->dir == NULL) { // se nao tem filho na direita, o no da esquerda vira pai
                    *p = (*p)->esq;
                }
                else { // caso tenha filho na direita
                    aux = maior(&(*p)->esq); // optei por escolher sempre o maior no da subarvora a esquerda
                    (*p)->info = aux->info;
                }
            }
            delete (aux);
            cout << "Elemento removido!" << endl;
        }
        else { // x != (*p)->info
            if (x < (*p)->info) 
                remover (&(*p)->esq, x);
            else 
                remover (&(*p)->dir, x);
        }
    }
    else 
        cout << "Árvore sem elementos!" << endl;
}


noPtr maior (noPtr * p)
{
    noPtr t;
    t = *p;
    
    if (t->dir == NULL) {
        (*p) = (*p)->esq;
        return t;
    }
    else 
        return maior(&(*p)->dir);
}

bool enderecoVazio (noPtr p)
{
    if (p) 
        return false;
    else 
        return true;
}
