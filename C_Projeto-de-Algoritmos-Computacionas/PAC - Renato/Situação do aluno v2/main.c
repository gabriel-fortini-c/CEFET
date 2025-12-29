/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main ()
{
    float prova1, prova2, media, prova_final, media_final;
    printf ("Bem vindo ao Sistema de Verificação de Situação Acadêmica!\n\n");
    printf ("Por favor, insira a nota da prova 1: ");
    scanf ("%f", &prova1);
    printf ("Por favor, insira a nota da prova 2: ");
    scanf ("%f", &prova2);
    
    media = (prova1 + prova2) / 2;
    if (media >= 7)
    {
        printf ("\nAluno aprovado!\nMédia = %.2f", media);
    }
    else // media < 7
    {
        printf ("\nAluno com média insuficiente: %.2f.\n", media);
        printf ("Por favor, insira a nota da prova final: ");
        scanf ("%f", &prova_final);
        media_final = (media + prova_final) / 2;
        printf ("\nMédia: %.2f\n", media_final);
        
        if (media_final >= 5)
        {
            printf ("Aluno aprovado!");
        }
        else
        {
            printf ("Aluno reprovado!");
        }
    }
    return 0;
}









