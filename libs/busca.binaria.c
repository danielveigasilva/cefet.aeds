#include <stdio.h>
#include <limits.h>
#include "helper.h"
#include "busca.h"

#define NOT_FOUNT -1

int BuscaBinaria(int *Vector, int n, int k){
    int c = 0;
    int f = n;
    int i;
    while (c <= f)
    {
      i = (int) (c+f)/2;
      if (Vector[i] > k)
        f = i - 1;
      else if (Vector[i] < k)
        c = i + 1;
      else
        break;
    }
    if (Vector[i] == k)
      return i;
    return NOT_FOUNT;
}

int BuscaBinaria2(int *Vector, int n, int k){
    int c = 0;
    int f = n;
    int i;
    while (c <= f)
    {
      i = (int) (c+f)/2;
      if (Vector[i] > k)
        f = i - 1;
      else if (Vector[i] < k)
        c = i + 1;
      else 
        break;
    }
    return i;
}

int __busca_binaria_recursiva__(int *Vector, int n, int k, int left, int right){
    if (left > right)
      return NOT_FOUNT;

    int i = (int) (left + right) / 2;

    if (Vector[i] < k)
      return __busca_binaria_recursiva__(Vector, n, k, i + 1, right);
    else if (Vector[i] > k)
      return __busca_binaria_recursiva__(Vector, n, k, left, i - 1);
    else
      return i;
}

int BuscaBinariaRecursiva(int *Vector, int n, int k){
  return __busca_binaria_recursiva__(Vector, n, k, 0, n - 1);
}
