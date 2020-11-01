#include <stdio.h>
#include <limits.h>
#include "helper.h"
#include "busca.h"

#define NOT_FOUNT -1

int BuscaSequencial(int *Vector, int n, int k){
    int i = 0;
    while (i <= n && Vector[i] != k)
      i++;
    return (i <= n) ? i: NOT_FOUNT;
}

int BuscaSequencial2(int *Vector, int n, int k){
    int i = 0;
    Vector[n + 1] = k;
    while (Vector[i] != k)
      i++;
    return (i <= n) ? i: NOT_FOUNT;
}

int BuscaSequencial3(int *Vector, int n, int k){
    int i = 0;
    Vector[n] = INT_MAX;
    while (Vector[i] < k)
      i++;
    return (Vector[i] == k) ? i: NOT_FOUNT;
}
