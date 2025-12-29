#include <stdio.h>

int menu ()
{
    int escolha;
    
    do {
        printf ("1- Quadrado \n2- Retângulo \n3- Triângulo \n4- Trapézio \n5-FIM \n");
        printf ("Escolha: ");
        scanf ("%d", &escolha);
        
        switch (escolha) {
            case 1: escolha = 1; break;
            
            case 2: escolha = 2; break;
            
            case 3: escolha = 3; break;
            
            case 4: escolha = 4; break;
            
            case 5: escolha = 5; break;
            
            default: printf ("Escolha inválida!\n");
        }
    } while (escolha < 1 || escolha > 5);
    
}

float calculaQuadrado ()
{
    float lado;
    printf ("Insira o lado do quadrado: ");
    scanf ("%f", &lado);
    return lado * lado;
}

float calculaRetângulo ()
{ 
    float base, altura;
    printf ("Insira a base e a altura do retângulo: ");
    scanf ("%f %f", &base, &altura);
    return base * altura;
}

float calculaTriângulo ()
{
    float base, altura;
    printf ("Insira a base e a altura do triângulo: ");
    scanf ("%f %f", &base, &altura);
    return (base * altura) / 2;
}

float calculaTrapezio ()
{
    float baseMaior, baseMenor, altura;
    printf ("Insira a base maior, a base menor e a altura do trapézio: ");
    scanf ("%f %f %f", &baseMaior, &baseMenor, &altura);
    return ((baseMaior + baseMenor) * altura) / 2;
}

int main ()
{
    int escolha;
    float area;
    
    escolha = menu ();
    
    do {
        if (escolha == 1) {
            area = calculaQuadrado ();
            printf ("Área do quadrado: %f", area);
        }
        else if (escolha == 2) {
            area = calculaRetângulo ();
            printf ("Área do Retângulo: %f", area);
        }
        else if (escolha == 3) {
            area = calculaTriângulo();
            printf ("Área do Triângulo: %f", area);
        }
        else if (escolha == 4) {
            area = calculaTrapezio ();
            printf ("Área do Trapézio: %f", area);
        }
        else {
            printf ("Fim do programa!");
        }
        
        escolha = menu ();
 
    } while (escolha != 5);
    
    return 0;
}