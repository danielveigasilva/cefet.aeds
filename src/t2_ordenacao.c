#include <stdio.h>
#include <string.h>
#include <helper.h>
#include <sort.h>

void SortAndPrint(int *vector, int n, char *algorithm){

	int newVector[n];
	for(int i = 0; i < n; i++)
		newVector[i] = vector[i];

	printf("%s (%s):\n", algorithm, Sort(newVector, n, algorithm));
	printv(newVector, n);
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

	SortAndPrint(vector, size, "Selecao");
	SortAndPrint(vector, size, "Insercao");
	SortAndPrint(vector, size, "MergeSort");
	SortAndPrint(vector, size, "QuickSort");
	SortAndPrint(vector, size, "ShellSort");

    return 0;
}
