#include <stdio.h>

float posto ()
{
    float soma , cod, valor, maior;
    soma = 0;
    for (int i = 0; i < 20; i++ )
    {
        printf ("Insira o código do posto e o valor por ele arrecadado: ");
        scanf ("%f %f", &cod, &valor);
        soma = soma + valor;
        if (i == 0 || valor > maior)
        {
            maior = valor;
        }
    }
    printf ("O maior valor arrecadado é: %g\n", maior);
    return soma;
}


int main()
{
    float op = posto ();
    printf ("%f", op);
}