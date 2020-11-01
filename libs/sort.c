#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h> 
#include "sort.h"

char result[20];
char *Sort(int *Vector, int n, char *a){
    
    clock_t start = clock();

    if (!strcmp(a, "Selecao"))
        SelecaoSort(Vector, n);
    else if (!strcmp(a, "ShellSort"))
        ShellSort(Vector, n);
    else if (!strcmp(a, "MergeSort"))
        MergeSort(Vector, n);
    else if (!strcmp(a,"Insercao"))
        InsercaoSort(Vector, n);
    else if (!strcmp(a,"QuickSort"))
        QuickSort(Vector, n);
    else
        return "[ERRO 404] - Algoritmo nao encontrado";

    clock_t end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC; 
    sprintf(result, "%fs", time);

    return result;
}