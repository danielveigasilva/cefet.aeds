#include <stdio.h>
#include <math.h>
#include "sort.h"

int __partition__(int *Vector, int left, int right){
    int i = left;
    int j = right;
    int ind = (left+right)/2;
    int pivot = Vector[ind];
    while (i <= j)
    {
        while (Vector[i] < pivot)
            i++;
        while (Vector[j] > pivot)
            j--;

        if (i < j){
            int aux=Vector[i];
            Vector[i]=Vector[j];
            Vector[j]=aux;
            i ++;
            j --;
        }
        else{
            break;
        }
    }
    return j;
}

void __quicksort__(int *Vector, int left, int right){
    if (left < right){
        int pivot = __partition__(Vector, left, right);
        __quicksort__(Vector, left, pivot);
        __quicksort__(Vector, pivot + 1, right);
    }
}

void QuickSort(int *Vector, int n)
{
    __quicksort__(Vector, 0, n - 1);
}