/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 
int verificaPerfeito(int numero) 
{
    int soma = 0;
    for(int i=1; i<numero; i++) 
    {
        if(numero%i==0) 
        {
            soma += i;
        }
    }
    return soma == numero;
}
 
int main() 
{
    int quantidade, contador=0;
    printf ("Insira a quantidade: ");
    scanf ("%d", &quantidade);
    for(int i=1; i<=quantidade; i++) 
    {
        if(verificaPerfeito(i)) 
        {
            contador ++;
            printf("O numero %d é perfeito\n", i);
        } 
        else 
        {
            printf("O numero %d não é perfeito\n", i);
        }
    }
    printf("\nA quantidade de números perfeito é de: %d números\n",contador);
    return 0;
}
