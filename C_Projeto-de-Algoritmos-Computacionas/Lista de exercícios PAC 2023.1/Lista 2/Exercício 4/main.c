#include <stdio.h>

float calcula_media (float nota1, float nota2)
{
    float media = (nota1 + nota2) / 2;
    return media;
}

int main ()
{
    int matricula;
    float n1, n2, t1, t2, media_prova, media_trabalho, media_final;
    printf ("Insira a matrícula: ");
    scanf ("%d", &matricula);
    printf ("Insira as notas das provas 1 e 2: ");
    scanf ("%f %f", &n1, &n2);
    printf ("Insira as notas dos trabalhos 1 e 2: ");
    scanf ("%f %f", &t1, &t2);
    media_prova = calcula_media (n1, n2);
    media_trabalho = calcula_media (t1,t2);
    media_final = (media_prova + media_trabalho) / 2;
    printf ("A matrícula é: %d\n", matricula);
    printf ("A média das provas é: %g\n", media_prova);
    printf ("A média dos trabalhos é: %g\n", media_trabalho);
    printf ("A média das final é: %g\n", media_final);
    
    
}