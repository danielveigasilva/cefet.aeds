#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h> 
#include "busca.h"

char result[20];
char *Busca(int *Vector, int n, int k, char *a){
    
    clock_t start = clock();
     
    if (!strcmp(a, "BuscaSequencial"))
        BuscaSequencial(Vector, n, k);
    else if (!strcmp(a, "BuscaSequencial2"))
        BuscaSequencial2(Vector, n, k);
    else if (!strcmp(a, "BuscaSequencial3"))
        BuscaSequencial3(Vector, n, k);
    else if (!strcmp(a, "BuscaBinaria"))
        BuscaBinaria(Vector, n, k);
    else if (!strcmp(a, "BuscaBinaria2"))
        BuscaBinaria2(Vector, n, k);
    else if (!strcmp(a, "BuscaBinariaRecursiva"))
        BuscaBinariaRecursiva(Vector, n, k);
    else
        return "[ERRO 404] - Algoritmo nao encontrado";

    clock_t end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC; 
    sprintf(result, "%fs", time);

    return result;
}