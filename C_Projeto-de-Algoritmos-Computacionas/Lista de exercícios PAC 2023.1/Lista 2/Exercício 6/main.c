#include <stdio.h>
#include <math.h>

float calcula_distancia (float x1, float y1, float x2, float y2)
{
    float distancia = sqrt ( pow((x1 - x2), 2) + pow ((y1 - y2), 2) );
    return distancia;
}

int main ()
{
    float x1, y1, x2, y2, x3, y3;
    float d1, d2, d3;
    printf ("Insira as coordenadas do primeiro ponto: ");
    scanf ("%f %f", &x1, &y1);
    printf ("Insira as coordenadas do segundo ponto: ");
    scanf ("%f %f", &x2, &y2);
    printf ("Insira as coordenadas do terceiro ponto: ");
    scanf ("%f %f", &x3, &y3);
    
    d1 = calcula_distancia (x1, y1, x2, y2);
    d2 = calcula_distancia (x2, y2, x3, y3);
    d3 = calcula_distancia (x3, y3, x1, y1);
    
    printf ("O perímetro é: %f", d1 + d2 +d3);
    
    return 0;
}