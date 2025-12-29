#include <stdio.h>

float calcula_caixa (float a, float b, float c)
{
    float volume_caixa = a * b * c;
    return volume_caixa;
}

float calcula_cilindro (float raio, float altura)
{
    float volume_cilindro = 3.1415 * raio * altura;
    return volume_cilindro;
}


int main()
{
    float a, b, h, d, raio, volume_final;
    printf ("Insira as duas arestas e a altura da caixa: ");
    scanf ("%f %f %f", &a, &b, &h);
    printf ("Insira o diâmetro do buraco da caixa: ");
    scanf ("%f", &d);
    raio = d / 2;
    volume_final = calcula_caixa (a, b, h) - calcula_cilindro (raio, h);
    
    printf ("O volume da caixa com o buraco é: %f", volume_final);
    
    return 0;

}