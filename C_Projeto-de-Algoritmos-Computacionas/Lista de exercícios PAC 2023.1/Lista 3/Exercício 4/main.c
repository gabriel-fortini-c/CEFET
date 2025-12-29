#include <stdio.h>

int valida_matricula (int matricula)
{
    int aa, s, nn;
    aa = (matricula / 1000);
    s = ((matricula / 100) % 10);
    nn = (matricula % 100);
    
    if (aa < 10 || aa > 22) return 1;
    if (s != 1 && s != 2) return 1;
    if (nn < 1 || nn > 90) return 1;
    else return 0;
}

int main ()
{
    int matricula;
    printf ("Insira a matrícula: ");
    scanf ("%d", &matricula);
    if (valida_matricula (matricula) == 0){
        printf ("Matrícula válida.");
    }
    else {
        printf ("Matrícula inválida.");
    }
    
    return 0;
}
