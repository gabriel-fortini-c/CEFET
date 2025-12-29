#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
    if (argc < 2) {
        printf ("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char * linha = NULL;
    size_t tamanho = 0;
    ssize_t caracLidos;

    if (argc == 2) {
        while ((caracLidos = getline (&linha, &tamanho, stdin)) != -1) {
            if (strstr (linha, argv[1]) != NULL) {
                printf ("%s", linha);
            }
        }
        free (linha);

        return 0;
    }

    for (int i = 2 ; i < argc ; i++) {
        FILE * arquivo = fopen (argv[i], "r");

        if (arquivo == NULL) {
            printf ("wgrep: cannot open file\n");
            exit(1);
        }

        while ((caracLidos = getline (&linha, &tamanho, arquivo)) != -1) {
            if (strstr(linha, argv[1]) != NULL) {
                printf("%s", linha);
            }
        }

        fclose (arquivo);

        free (linha);
        linha = NULL;
        tamanho = 0;
    }

    return 0;
}