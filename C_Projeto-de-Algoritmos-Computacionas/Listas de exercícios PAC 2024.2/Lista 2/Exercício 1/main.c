#include <stdio.h>

float valorVendaCombustivel (float preco, int quantidade)
{
	float valor = preco * quantidade;
	return valor;
}

int main ()
{
	int quantidadeGaso, quantidadeAlc, quantidadeDie;
	float precoGaso, precoAlc, precoDie;

	printf ("Insira o preco da gasolina e a quantidade comprada: ");
	scanf ("%f %d", &precoGaso, &quantidadeGaso);
	printf ("Insira o preco do alcool e quantidade comprada: ");
	scanf ("%f %d", &precoAlc, &quantidadeAlc);
	printf ("Insira o preco do diesel e quantidade comprada: ");
	scanf ("%f %d", &precoDie, &quantidadeDie);

	printf ("Gasolina: R$%.2f\n", valorVendaCombustivel (precoGaso, quantidadeGaso));
	printf ("Alcool: R$%.2f\n", valorVendaCombustivel (precoAlc, quantidadeAlc));
	printf ("Diesel: R$%.2f\n", valorVendaCombustivel (precoDie, quantidadeDie));

	return 0;
}