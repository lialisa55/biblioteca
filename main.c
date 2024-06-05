#include <stdio.h>
#include <stdlib.h>

void receber(int num){
    char *titulo, *autor;
    int ano;

    titulo = (char**) malloc(num * sizeof(char*));
    autor = (char**) malloc(num * sizeof(char*));
    ano = (int*) malloc(num * sizeof(int));

    for (int i = 0; i < num; i++){
        titulo[i] = (char*) malloc(100 * sizeof(char));
        autor[i] = (char*) malloc(100 * sizeof(char));

        fscanf(stdin, "%s %s %d", titulo[i], autor[i], &ano[i]);
        printf("%s, %s, %d", titulo[i], autor[i], ano[i]);
    }
}

int main()
{
    int n;
    scanf("%d ", &n);

    receber(n);

    return 0;
}
