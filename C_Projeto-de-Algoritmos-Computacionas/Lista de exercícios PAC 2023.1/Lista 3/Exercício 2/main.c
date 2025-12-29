
#include <stdio.h>

void situacao_eleitoral (int idade)
{
    if (idade < 16)
    {
        printf ("Não eleitor.");
    }
    else if ((16 <= idade && idade < 18) || (idade > 70))
    {
        printf ("Eleitor facultativo.");
    }
    else if (18 <= idade && idade < 70)
    {
        printf ("Eleitor.");
    }
}

int main ()
{
    int idade;
    printf ("Insira a idade: ");
    scanf ("%d", &idade);
    situacao_eleitoral(idade);
    
    return 0;
}