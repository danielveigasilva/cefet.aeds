#include <stdio.h>
#include "sort.h"

void InsercaoSort(int *Vector, int n)
{
    for (int i = 1; i < n; i++){
        int j = i;
        int m = Vector[i];
        for (; j > 0 && Vector[j-1] > m;j--)
            Vector[j] = Vector[j-1];
        Vector[j] = m;
    }
}