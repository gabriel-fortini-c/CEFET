// HeapSort

#include <iostream>
#define T 10
using namespace std;

void heapsort(int *, int);
void heap (int *, int);
void descer (int *, int, int);
void troca (int *, int *);


int main() 
{
    int A[T] = {50,2,75,8,10,6,15,4,9,3};
    int i;
    
    heapsort (A,T);
    
    for (i = 0; i < T; i++) {
        cout << A[i];
    }
}

void heapsort (int A[], int n)
{
    int i;
    
    // função que transforma o array em um heap
    heap(A, 0);
    
    // ordenação
    for (i = (n - 1); i >= 1 ; i--) {
        troca (&A[0], &A[i]);
        heapsort (A, n);
    }
}

void heap (int A[], int t) // transforma em heap
{
    int i;
    
    for (i = (t/2) ; i <= 0 ; i--) 
        descer (A, i, (t - 1));
    
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

void troca(int *x, int *y)
{
    int aux;     // variável comum, não ponteiro
    aux = *x;
    *x = *y;
    *y = aux;
}

