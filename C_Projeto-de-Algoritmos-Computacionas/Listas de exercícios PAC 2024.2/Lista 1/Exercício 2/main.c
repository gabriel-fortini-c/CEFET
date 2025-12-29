/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

float calcular_novo_preco(float preco, float perc_aumento)
{
    float novo_preco;
    return novo_preco = preco + (preco * (perc_aumento/100));
}

int main()
{
    float preco_produto, aumento, op;
    printf ("Insira o preço unitário do produto: ");
    scanf ("%f", &preco_produto);
    printf ("Insita o percentual de aumento: ");
    scanf ("%f", &aumento);
    op = calcular_novo_preco(preco_produto, aumento);
    printf ("O novo preço é: R$ %g,00", op);

    return 0;
}