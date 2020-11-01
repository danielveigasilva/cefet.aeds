#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h> 
#include "heap.h"

char result[20];
char *Heap(int *Vector, int n, char *a){
    
    clock_t start = clock();

    if (!strcmp(a, "HeapSort"))
        HeapSort(Vector, n);
    else
        return "[ERRO 404] - Algoritmo nao encontrado";

    clock_t end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC; 
    sprintf(result, "%fs", time);

    return result;
}