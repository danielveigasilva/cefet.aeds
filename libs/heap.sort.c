#include <stdio.h>
#include "helper.h"
#include "heap.h"

void __down_heap__(int *Vector, int i, int n){
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

void __up_heap__(int *Vector, int i){
  int parent = Vector[i];
  Vector[0] = parent;
  while (Vector[(int)i/2] < parent)
  {
    SwapPosition(Vector, i, (int)i/2);
    i = (int)i/2;
  }
  Vector[i] = parent;
}

void __build_heap__(int *Vector, int n)
{
  for (int i = (n / 2); i >= 0 ; i--)
    __down_heap__(Vector, i, n-1);
}

void HeapSort(int *Vector, int n){
    
    __build_heap__(Vector, n);

    for (int i = n - 1; i >= 1; i--){
      SwapPosition(Vector, 0, i);
      __down_heap__(Vector, 0, i - 1);
    }
}
