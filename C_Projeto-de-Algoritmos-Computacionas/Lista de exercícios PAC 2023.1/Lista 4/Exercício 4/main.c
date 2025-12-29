#include <stdio.h>

float calculaHorista ()
{
    int quantHoras;
    float valorHora, salarioHorista;
    printf ("Insira a quantidade de horas trabalhadas e o valor da hora de trabalho: ");
    scanf ("%d %f", &quantHoras, &valorHora);
    salarioHorista = valorHora * quantHoras;
    return salarioHorista;
}
float calculaContratado ()
{
    float salarioContratado;
    printf ("Insira o salário do funcionário: ");
    scanf ("%f", &salarioContratado);
    return salarioContratado;
}
float calculaPrestador ()
{
    int quantServicos, i;
    float valorServicos, soma = 0;
    printf ("Insira a quantidade de serviços realizados: ");
    scanf ("%d", &quantServicos);
    for (i=0 ; i < quantServicos ; i++)
    {
        printf ("Insira o valor do serviço: ");
        scanf ("%f", &valorServicos);
        soma += valorServicos;
    }
    return soma;
}

int main ()
{
    int escolha;
    for (int i=0 ; i < 50 ; i++)
    {
        printf ("1- Horista\n2- Contratado\n3-Prestador de Serviços\n");
        printf ("Escolha uma das opções: ");
        scanf ("%d", &escolha);
        while (escolha < 1 || escolha > 3) {
            printf ("\n1- Horista\n2- Contratado\n3-Prestador de Serviços\n");
            printf ("Escolha uma das opções: ");
            scanf ("%d", &escolha);
        }
        if (escolha == 1) {
            printf ("Salário: R$%.2f\n\n", calculaHorista());
        }
        if (escolha == 2) {
            printf ("Salário: R$%.02f\n\n", calculaContratado());
        }
        if (escolha == 3) {
            printf ("Salário: R$%.02f\n\n", calculaPrestador());
        }
    }
    
    return 0;
}