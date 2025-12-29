#include <iostream>
#define tam 9
using namespace std;

int partition (int array[], int start, int end) 
{
    int pivot = array[end];
    int i = start - 1, j, temp;
    
    for (j = start ; j <= end - 1 ; j++) {
        if (array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    i++;
    temp = array[i];
    array[i] = array[end];
    array[end] = temp;
    
    return i;
}

void quicksort (int array[], int start, int end) 
{
    if (end <= start) return;
    
    int pivot = partition (array, start, end);
    quicksort (array, start, pivot - 1);
    quicksort (array, pivot + 1, end);
    
}

int main()
{
    int array[tam] = {8, 2, 5, 3, 9, 4, 7, 6, 1};
    int i;
    
    quicksort (array, 0, tam - 1);
    
    cout << "Ordenado por quick sort: " << endl;
    for(i = 0 ; i < tam ; i++) {
        cout << array[i];
        if (i < (tam - 1)) cout << ", ";
    }
    cout << "." << endl;

    return 0;
}