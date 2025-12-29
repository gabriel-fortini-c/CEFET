#include <iostream>
using namespace std;

int fibonacci (int n) 
{
    if (n <= 2) {
        return 1;
    }
    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}


int main()
{
    int n, i;
    
    cout << "Entre com a quantidade de termos da sequencia: ";
    cin >> n;
    
    for (i = 0 ; i < n ; i++) {
        cout << i + 1 << "° termo: "<< fibonacci(i + 1) << "\t";
    }

    return 0;
}