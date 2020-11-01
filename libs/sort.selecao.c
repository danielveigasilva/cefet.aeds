#include <stdio.h>
#include "sort.h"

void SelecaoSort(int *Vector, int n)
{
    for (int i = 0; i < n - 1; i++){
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (Vector[j] < Vector[m])
                m = j;
        int aux = Vector[i];
        Vector[i] = Vector[m];
        Vector[m] = aux;
    }
}