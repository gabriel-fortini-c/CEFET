/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float valor, desconto, preco_final ;
    printf ("Por favor insira o valor de sua compra: ");
    scanf ("%f", &valor);

    if (valor >= 600)  
    {
        printf ("Seu desconto é de 20%%\n");
        desconto = valor * 0.20;
        printf ("O valor do desconto é: R$ %.2f\n", desconto);
        preco_final = valor - desconto;
        printf ("O valor a ser pago é: R$ %.2f\n", preco_final);
    }
        
    else if ((valor >=400) && (valor < 600))
    {
        printf ("Seu desconto é de 15%%\n");
        desconto = valor * 0.15;
        printf ("O valor do desconto é: R$ %.2f\n", desconto);
        preco_final = valor - desconto;
        printf ("O valor a ser pago é: R$ %.2f\n", preco_final);
    }
    else if ((valor >= 200) && (valor < 400))
    {
        printf ("Seu desconto é de 10%%\n");
        desconto = valor * 0.10;
        printf ("O valor do desconto é: R$ %.2f\n", desconto);
        preco_final = valor - desconto;
        printf ("O valor a ser pago é: R$ %.2f\n", preco_final);
    }
    else if (valor < 200)
    {
        printf ("Não tem desconto");
    }


    
    return 0;
}
