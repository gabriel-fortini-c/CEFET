// Heap (zero-based)

#include <iostream>
using namespace std;

void troca (int *, int *);
void subir (int *, int);
void descer (int *, int, int);
void inserir (int *, int, int *);
void remover (int *, int *);



int main() {
    const int TAM = 100;
    int heap[TAM];  // Vetor do heap
    int qtde = -1;  // Índice do último elemento (-1 indica vazio)

    int opcao, valor;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Inserir\n";
        cout << "2. Remover maior\n";
        cout << "3. Listar heap\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                inserir(heap, valor, &qtde);
                cout << "Valor inserido no heap.\n";
                break;
            case 2:
                if (qtde >= 0) {
                    cout << "Maior elemento removido: " << heap[0] << endl;
                    remover(heap, &qtde);
                } else {
                    cout << "Heap vazio!\n";
                }
                break;
            case 3:
                cout << "Heap: ";
                for (int i = 0; i <= qtde; i++) {
                    cout << heap[i] << " ";
                }
                cout << endl;
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}

void troca(int *x, int *y)
{
    int aux;     // variável comum, não ponteiro
    aux = *x;
    *x = *y;
    *y = aux;
}

void subir (int A[], int i)
{
    int j = (i - 1) / 2;
    
    if (j >= 0) {
        if (A[i] > A[j]) {
            troca (&A[i], &A[j]);
            subir (A, j);
        }
    }
}

void descer (int A[], int i, int q)
{
    int left = (2 * i) + 1; // se fosse one-based: left = (2 * i)
    int right = (2 * i) + 2; // se fosse one-based: right = (2 * i) + 1
    
    int maior = i;
    
    // verificar se há filhos 
    if (right <= q && A[right] > A[i]) {
        maior = right;
    }
    
    if (left <= q && A[left] > A[maior]) {
        maior = left;
    }
    
    if (maior != i) { // caso essa condição seja falsa (maior == i), o array já é um heap
        // troca com o filho maior e chama a função de novo
        troca (&A[i], &A[maior]);
        descer (A, maior, q);
    }
}

void inserir (int A[], int valor, int * t)
{
    *t = *t + 1; // como é zero-based, é necessário o +1
    A[*t] = valor;
    subir (A, *t);
}

void remover (int A[], int * q)
{
    A[0] = A[*q];
    *q = *q - 1;
    descer (A, 0, *q);
}




