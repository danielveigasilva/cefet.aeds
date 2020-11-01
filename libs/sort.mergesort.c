#include <stdio.h>
#include "helper.h"
#include "sort.h"

void __mergevector__(int *Vector, int left, int middle, int right)
{
  int i = left;
  int j = middle + 1;
  int k = 0;

  int VectorAux[right - left + 1];

  while(i <= middle && j <=right){
      if (Vector[i] <= Vector[j]){
        VectorAux[k] = Vector[i];
        i++;
      }
      else{
        VectorAux[k] = Vector[j];
        j++;
      }
      k++;
  }
  while(i<=middle){
    VectorAux[k] = Vector[i];
    k++;
    i++;
  }
  while(j<=right){
    VectorAux[k] = Vector[j];
    k++;
    j++;
  } 

  k = 0;
  for (int x = left; x < right + 1; x++){
    Vector[x] = VectorAux[k];
    k++;
  }

}

void __mergesort__(int *Vector, int left, int right)
{
  if (left < right)
  {
    int middle = (left + right)/2;
    
    __mergesort__(Vector, left, middle);
    __mergesort__(Vector, middle+1, right);
    __mergevector__(Vector, left, middle, right);
  }
}

void MergeSort(int *Vector, int n){
    __mergesort__(Vector, 0, n - 1);
}
