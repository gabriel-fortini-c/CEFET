#include <iostream>
#define tam 8
using namespace std;

void merge (int leftArray[], int leftSide, int rightArray[], int rightSide, int array[])
{
    int i = 0, l = 0, r = 0; //indices
    
    while (l < leftSide && r < rightSide) {
        if (leftArray[l] < rightArray[r]) {
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }
    
    while (l < leftSide) {
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSide) {
        array[i] = rightArray[r];
        i++;
        r++;
    }
}

void mergeSort (int array[], int length) 
{
    if (length <= 1) return;
    
    int middle = length / 2;
    int* leftArray = new int[middle];
    int* rightArray = new int[length - middle];
    
    int i = 0; //left array
    int j = 0; //right array
    
    for (; i < length ; i++) {
        if (i < middle) {
            leftArray[i] = array[i];
        }
        else {
            rightArray[j] = array[i];
            j++;
        }
    }
    
    int leftSide = length / 2;
    int rightSide = length - leftSide;
    
    mergeSort(leftArray, middle);
    mergeSort(rightArray, length - middle);
    merge(leftArray, middle, rightArray, length - middle, array);
    
    delete[] leftArray;
    delete[] rightArray;
}

int main()
{
    int array[tam] = {8, 2, 5, 3, 4, 7, 6, 1};
    int i;
    
    mergeSort(array, tam);
    
    cout << "Ordenado por merge sort: " << endl;
    for(i = 0 ; i < tam ; i++) {
        cout << array[i];
        if (i < (tam - 1)) cout << ", ";
    }
    cout << "." << endl;

    return 0;
}