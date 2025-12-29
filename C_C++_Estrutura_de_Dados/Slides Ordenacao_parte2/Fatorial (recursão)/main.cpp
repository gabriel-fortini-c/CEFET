#include <iostream>
using namespace std;

int fatorial (int num) 
{
    if (num <= 1) {
        return 1;
    }
    else {
        return num * fatorial(num - 1);
    }
}

int main()
{
    int num, i;
    
    cout<<"Insira um número (maiores ou iguais a 0) para calcular o fatorial dele: ";
    cin >> num;
    
    cout << num << "! = " << fatorial(num);

    return 0;
}