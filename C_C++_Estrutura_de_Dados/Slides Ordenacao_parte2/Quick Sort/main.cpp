#include <iostream>
#define n 5
using namespace std;

void troca (int * x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quicksort (int a[], int inicio, int fim) 
{
    int i, j, chave;
    
    if ((fim - inicio) < 2) {
        if ((fim - inicio) == 1) {
            if (a[inicio] > a[fim]) {
                troca (&a[inicio], &a[fim]);
            }
        }
    }
    else {
        i = inicio;
        j = fim;
        chave = a[inicio];
        
        while (j > i) {
            i++;
            while (a[i] < chave) {
                i++;
            }
            while (a[j] > chave) {
                j--;
            }
            if (j > i) {
                troca (&a[i], &a[j]);
            }
        }
        troca (&a[inicio], &a[j]);
        quicksort (a, inicio, j - 1);
        quicksort (a, j + 1, fim);
    }
}

int main()
{
    int i, a[n];
    
    cout << "Insira elementos para o array: " << endl;
    for (i = 0 ;  i < n ; i++) {
        cout << i + 1 << "° elemento: ";
        cin >> a[i];
    }
    
    quicksort (a, 0, n - 1);
    
    cout << "Ordenado por Quick Sort: " << endl;
    for (i = 0 ;  i < n ; i++) {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "." << endl;
    

    return 0;
}