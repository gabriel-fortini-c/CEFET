/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 
int verificaPerfeito(int numero) {
    int soma = 0;
    for(int i=1; i<numero; i++) 
    {
        if(numero%i==0) 
        {
            soma += i;
        }
    }
    if(soma == numero) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
    return soma == numero;
}
 
int main() 
{
    int numero, quantidade=0;
    printf ("Insira a 100 números inteiros: \n");
    for(int i=0; i<5; i++) 
    {
        printf ("Insira o número: ");
        scanf("%d",&numero);
        if(verificaPerfeito(numero)) 
        {
            quantidade = quantidade + 1;
            printf("O numero %d é perfeito\n",numero);
        } 
        else 
        {
            printf("O numero %d não é perfeito\n",numero);
        }
    }
    printf("\nA quantidade de números perfeito é de: %d números\n",quantidade);
    return 0;
}