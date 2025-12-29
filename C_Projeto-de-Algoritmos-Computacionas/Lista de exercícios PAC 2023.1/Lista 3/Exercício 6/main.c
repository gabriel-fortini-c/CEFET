#include <stdio.h>
float calculaSalarioBase (float valorHora, int horas) {
    return valorHora * horas;
}

float descontarInss (float salarioBase) {
    float descInss;
    descInss = (salarioBase * 11) / 100;
    if (descInss >= 450.27) descInss = 450.27;
    return descInss;
}

float descontarIr (float salarioBase) {
    float descIr;
    if (salarioBase > 2900) {
        descIr = (salarioBase * 27.5) / 100;
    }
    else if (salarioBase > 1800 && salarioBase <= 2900) {
        descIr = (salarioBase * 15) / 100;
    }
    else {
        descIr = 0;
    }
    
    return descIr;
}

int main ()
{
    int matricula, horas;
    float valorHora, salarioBase, descInss, descIr;
    printf ("Insira a matrícula do funcionário: ");
    scanf ("%d", &matricula);
    printf ("Insira o valor da hora de trabalho e a quantidade de horas trabalhadas: ");
    scanf ("%f %d", &valorHora, &horas);
    salarioBase = calculaSalarioBase(valorHora, horas);
    descInss = descontarInss(salarioBase);
    descIr = descontarIr(salarioBase);
    printf ("\nA matrícula é: %d\n", matricula);
    printf ("O salário base é: R$%.02f\n", salarioBase);
    printf ("O desconto do INSS é de: R$%.02f\n", descInss);
    printf ("O desconto de Imposto de Renda é de: R$%.02f\n", descIr);
    printf ("O salário líquido é de: R$%.02f", salarioBase - descInss - descIr);
    
    return 0;
}


