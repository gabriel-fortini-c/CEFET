/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int menu ()
{
    int d, i=1;
    printf ("Escolha: 1. Buscar \n 2. Cadastrar \n 3. Relatório \n 4. Excluir \n 5. Sair \n");
    printf ("Faça sua escolha: ");
    scanf ("%d", &d);
    
    while (i != 0)
    {
        if (d >= 1 && d <= 5)
        {
            printf ("Escolheu uma opção válida!");
            i = 0;
        }
        else
        {
            printf ("\nEscolheu uma opção inválida!\n\n");
            printf ("Escolha: 1. Buscar \n 2. Cadastrar \n 3. Relatório \n 4. Excluir \n 5. Sair \n");
            printf ("Faça sua escolha: ");
            scanf ("%d", &d);
        }
        
    }
}


int main ()
{
    int op = menu ();
    printf ("%d", op);
}







