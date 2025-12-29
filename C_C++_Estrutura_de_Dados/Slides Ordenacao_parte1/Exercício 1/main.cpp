#include <iostream>
#define tam 50
using namespace std;

void bubbleSort (int b[]) 
{
    int i, j, aux;
    
    for (i = 0 ; i < (tam - 1) ; i++) {
        for (j = i + 1 ; j < tam ; j++) {
            if (b[i] > b[j]) {
                aux = b[i];
                b[i] = b[j];
                b[j] = aux;
            }
        }
    }
}

void selectionSort (int s[]) 
{
    int i, j, menor, aux;
    
    for (i = 0 ; i < tam ; i++) {
        menor = i;
        
        for (j = i + 1 ; j < tam ; j++) {
            if (s[menor] > s[j]) {
                menor = j;
            }
        }
        
        aux = s[i];
        s[i] = s[menor];
        s[menor] = aux;
    }
}

void insertionSort (int I[])
{
    int i, j, chave;
    
    for (i = 1 ; i < tam ; i++) {
        chave = I[i];
        j = i - 1;
        
        while (j >= 0 && I[j] > chave) {
            I[j + 1] = I[j];
            j--;
        }
        
        I[j + 1] = chave;
    }
}


int main()
{
    int i, j, num, b[tam], s[tam], I[tam];
    
    for (i = 0 ; i < tam ; i++) {
        cout << "Insira um numero: ";
        cin >> num;
        b[i] = s[i] = I[i] = num;
    }
    
    bubbleSort(b);
    selectionSort(s);
    insertionSort(I);
    
    i = 0;
    cout << "Ordenado por Bubble Sort: ";
    for (i = 0 ; i < tam ; i++) {
        cout << b[i];
        if (i < tam - 1) cout << ", ";
    }
    cout << "." << endl;
    
    i = 0;
    cout << "Ordenado por Selection Sort: ";
    for (i = 0 ; i < tam ; i++) {
        cout << s[i];
        if (i < tam - 1) cout << ", ";
    }
    cout << "." << endl;i = 0;
    
    cout << "Ordenado por Insertion Sort: ";
    for (i = 0 ; i < tam ; i++) {
        cout << I[i];
        if (i < tam - 1) cout << ", ";
    }
    cout << "." << endl;

    return 0;
}