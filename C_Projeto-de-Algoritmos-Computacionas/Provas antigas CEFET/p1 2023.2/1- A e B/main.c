#include <stdio.h>

int leDadosResidencia (int numMoradores)
{
    int comodos, idade, maior = 0, contador = 0;
    printf ("Insira o número de cômodos da casa: ");
    scanf ("%d", &comodos);
    for (int i=0 ; i < numMoradores ; i++) {
        printf ("Insira a idade do morador: ");
        scanf ("%d", &idade);
        
        if (idade < 18) {
            contador ++;
        }
        
        if (i == 0 || idade > maior) {
            maior = idade;
        }
        
    }
    printf ("Menores de idade: %d\n", contador);
    printf ("Idade do morador mais velho: %d\n", maior);
    return comodos;
}

int main ()
{
    int numMoradores = -1, contadorResidencia = 0, contadorTresComodos = 0, comodos; 
    
    while (numMoradores != 0) {
        printf ("Insira o numero de moradores da casa (0 para encerrar): ");
        scanf ("%d", &numMoradores);
        
        if (numMoradores != 0) {
            comodos = leDadosResidencia(numMoradores);
            printf ("%d", comodos);
            contadorResidencia++;
            
            if (comodos > 3) {
                contadorTresComodos++;
            }
        }
    }
    printf ("O numero de casas visitadas foi de: %d\n", contadorResidencia);
    printf ("O numero de casa com mais de 3 comodos foi de: %d\n", contadorTresComodos);
    
    return 0;
}





