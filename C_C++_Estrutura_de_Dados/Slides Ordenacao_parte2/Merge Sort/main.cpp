#include <iostream>
#define n 10
using namespace std;

void intercala(int a[], int inicio, int fim, int meio) 
{
    int i, aux[n], posLivre = inicio, inicioA1 = inicio, inicioA2 = meio + 1;
    
    while (inicioA1 <= meio && inicioA2 <= fim) {
        if (a[inicioA1] > a[inicioA2]) {
            aux[posLivre] = a[inicioA2];
            inicioA2++;
        }
        else {
            aux[posLivre] = a[inicioA1];
            inicioA1++;
        }
        posLivre++;
    }
    
    for (i = inicioA1 ; i <= meio ; i++) {
        aux[posLivre] = a[i];
        posLivre++;
    }
    for (i = inicioA2 ; i <= fim ; i++) {
        aux[posLivre] = a[i];
        posLivre++;
    }
    for (i = inicio ; i <= fim ; i++) {
        a[i] = aux[i];
    }
    
}

void mergesort (int a[], int inicio, int fim) 
{
    int meio;
    
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergesort(a, inicio, meio);
        mergesort(a, meio + 1, fim);
        intercala(a, inicio, fim, meio);
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
    
    mergesort (a, 0, n - 1);
    
    cout << "Ordenado por Merge Sort: " << endl;
    for (i = 0 ;  i < n ; i++) {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "." << endl;
    

    return 0;
}