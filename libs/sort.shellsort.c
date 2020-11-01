#include <stdio.h>
#include "sort.h"

void ShellSort(int *Vector, int n)
{
  int passo = n/2;
  while (passo > 0){
      for (int i = passo; i < n; i++){
          int aux = Vector[i];
          int j = i;
          while (j >= passo && Vector[j-passo] > aux){
              Vector[j] = Vector[j-passo];
              j = j-passo;
          }
          Vector[j] = aux;
      }
      passo = passo/2;
  }
}