#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void receber(int num, char** titulos, char** autores, int* anos, int* quantidades){
    for (int i = 0; i < num; i++){
        char titulo[100], autor[50];
        int ano;
        scanf(" %99[^,], %49[^,], %d", titulo, autor, &ano);

        int is_duplicate = 0;
        for (int j = 0; j < i; j++){
            if (strcmp(titulo, titulos[j]) == 0 &&
                strcmp(autor, autores[j]) == 0 &&
                ano == anos[j]){
                quantidades[j]++;
                is_duplicate = 1;
                break;
            }
        }
        if(!is_duplicate){
            titulos[i] = strdup(titulo);
            autores[i] = strdup(autor);
            anos[i] = ano;
            quantidades[i] = 1;
        }
    }
}

void catalogar(int num, char** titulos, char** autores, int* anos, int* quantidades){
    printf("Catalogo de Livros:\n");
    for (int i = 0; i < num; i++) {
        printf("Livro %d:\nTitulo: %s\nAutor: %s\nAno: %d\nQuantidade: %d\n", i+1, titulos[i], autores[i], anos[i], quantidades[i]);
        if(i != num-1){
            printf("\n");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char **titulos = malloc(n * sizeof(char*));
    char **autores = malloc(n * sizeof(char*));
    int *anos = malloc(n * sizeof(int));
    int *quantidades = calloc(n, sizeof(int));

    receber(n, titulos, autores, anos, quantidades);
    catalogar(n, titulos, autores, anos, quantidades);

    for(int i = 0; i < n; i++){
        free(titulos[i]);
        free(autores[i]);
    }
    free(titulos);
    free(autores);
    free(anos);
    free(quantidades);

    return 0;
}
