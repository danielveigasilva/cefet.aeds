#include <stdio.h>
#include "helper.h"
#include "heap.h"

void DeceHeap(int *Vector, int i, int n){
  int parent = Vector[i];
  int j = 0;
  while(i <= (int)n/2){
    j = 2*i;
    if ((j < n) && (Vector[j]) < (Vector[j+1]))
      j++;
    if (parent >= Vector[j])
      break;
    else{
      SwapPosition(Vector,i,j);
      i=j;
    }
  }
  Vector[i] = parent;
}

void SobeHeap(int *Vector, int i){
  int item = Vector[i];
  int j = (int)(i-1)/2;
  Vector[0] = item;
  while (Vector[(int)(i-1)/2] < item)
  {
    SwapPosition(Vector, i, (int)(i-1)/2);
    i = (int)(i-1)/2;
  }
  Vector[i] = item;
}

void BuildHeap(int *Vector, int n)
{
  for (int i = (n / 2); i >= 0 ; i--)
    DeceHeap(Vector, i, n-1);
}

void HeapSort(int *Vector, int n){
    
    BuildHeap(Vector, n);

    for (int i = n - 1; i >= 1; i--){
      SwapPosition(Vector, 0, i);
      DeceHeap(Vector, 0, i - 1);
    }
}
