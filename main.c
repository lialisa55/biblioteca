#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void receber(int num, char** titulo, char** autor, int* ano, int* quantidade){
    for (int i = 0; i < num; i++){
        titulo[i] = (char*) malloc(100 * sizeof(char));
        autor[i] = (char*) malloc(100 * sizeof(char));

        fscanf(stdin, " %99[^,], %99[^,], %d", titulo[i], autor[i], &ano[i]);
	quantidade[i] = 1;

	for (int j = 0; j < i; j++){
		if (strcmp(titulo[i], titulo[j]) == 0 && strcmp(autor[i], autor[j]) == 0 && ano[i] == ano[j]){
			quantidade[j]++;
			quantidade[i]--;
			break;
		}
	}
	getchar();
    }
}

void catalogar(int num, char** titulo, char** autor, int* ano, int* quantidade){
	printf("Catalogo de Livros:\n");
	for (int i = 0; i < num; i++) {
		if(quantidade[i] > 0) {
			printf("Livro %d:\nTitulo: %s\nAutor: %s\nAno: %d\nQuantidade: %d\n", i+1, titulo[i], autor[i], ano[i], quantidade[i]);
			if(i != num-1){
				printf("\n");
			}
		}
		else{
			i--;
		}
	}
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char **titulo, **autor;
    int *ano, *quantidade;
    titulo = (char**) malloc(n * sizeof(char*));
    autor = (char**) malloc(n * sizeof(char*));
    ano = (int*) malloc(n * sizeof(int));
    quantidade = (int*) calloc(n, sizeof(int));

    receber(n, titulo, autor, ano, quantidade);
    catalogar(n, titulo, autor, ano, quantidade);

    for(int i = 0; i < n; i++){
	    free(titulo[i]);
	    free(autor[i]);
    }
    free(titulo);
    free(autor);
    free(ano);
    free(quantidade);

    return 0;
}
