#include <stdio.h>
#include <string.h>

typedef struct _Livro Livro;

struct _Livro {
    char isbn[13];
    char titulo [30];
    char autorPrincipal [30];
};

int busca (Livro livros[], int qt, char *tituloProcurado)
{
    for (int i = 0 ; i < qt ; i++) {
        //if (livros[i].titulo == titulo)
        if (strcmp(livros[i].titulo, titulo) == 0) {
            return i;
        }
    }
    return -1;
}

void exibe (Livro livros [], int qt, char *tituloProcurado)
{
    int pos = busca (livros, qt, tituloProcurado);
    
    if (pos == -1) {
        printf ("Não encontrado!");
    }
    else {
        printf ("%s", livros[pos].ibsn);
        printf ("%s", livros[pos].titulo);
        printf ("%s", livros[pos].autorPrincipal);
        for (int i = 0 ; i < qt ; i++) {
            if (i != pos && strcmp(livros[i].autorPrincipal, livros[pos].autorPrincipal) == 0) {
                printf ("%s", livros[i].titulo);
            }
        }
        
    }
}





