#include <stdio.h>
#include <string.h>
#include <helper.h>
#include <heap.h>

void SortAndPrint(int *vector, int n, char *algorithm){

	printf("%s (%s):\n", algorithm, Heap(vector, n, algorithm));
	printv(vector, n);
	printf("\n\n");
}

int main()
{
	printf("\n");

	char r = 'x';
	printf("Deseja gerar um vetor randomico? (y/n) ");
	while(1){
		scanf(" %c", &r);
		if (r == 'y' || r == 'n')
			break;
	}

	int size = 0;
	printf("Insira o tamanho do vetor %s", r == 'y'? "(Digite 0 para tamanho randomico): ":"a ser digitado: ");
	while (1){
		scanf(" %d", &size);
		if (size <= 0 && r == 'y'){
			size = RandomSize(30);
			break;	
		}
		else if (size > 0)
			break;
	}

	int vector[size];

	if (r == 'y')
		InsertRandomVector(vector, size);
	else{
		for (int i = 0; i < size; i++)
			scanf("%d", &vector[i]);
	}

	printf("\n\n");	
	printf("Vetor Original:\n");
	printv(vector, size);
	printf("\n\n\n");

	SortAndPrint(vector, size, "HeapSort");

	printf("\n\n");
	printf("Digite um valor para inserir no Heap: ");
		
	int newVector[size+1];
	
	for (int i = 0; i < size+1; i++){
		if (i < size)
			newVector[i] = vector[i];
		else
			scanf("%d", &newVector[i]);
	}
	
	printf("\n\nHeap Resultante:\n");
	HeapSort(newVector, size+1);
	printv(newVector, size+1);
	printf("\n");

    return 0;
}
