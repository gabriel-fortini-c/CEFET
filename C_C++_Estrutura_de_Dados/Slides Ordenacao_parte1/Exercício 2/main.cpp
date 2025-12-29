#include <iostream>
#define qtd 4
using namespace std;

struct Funcionarios {
    int matricula;
    float salario;
};

void ordena (Funcionarios f[]) //insertion sort
{
    int i, j;
    Funcionarios chave;
    
    for (i = 1 ; i < qtd ; i++) {
        chave = f[i];
        j = i - 1;
        
        while (j >= 0 && f[j].salario < chave.salario) {
            f[j + 1] = f[j];
            j--;
        }
        
        f[j + 1] = chave;
    }
}


int main()
{
    Funcionarios f[qtd];
    int i;
    
    for (i = 0 ; i < qtd ; i++) {
        cout << i + 1 << "° Funcionário" << endl;
        cout << "Insira a matrícula: ";
        cin >> f[i].matricula;
        cout << "Insira o salário: ";
        cin >> f[i].salario;
    }
    
    ordena(f);
    
    for (i = 0 ; i < qtd ; i++) {
        cout << "Matrícula: " << f[i].matricula << ", Salário: " << f[i].salario << endl;
    }

    return 0;
}