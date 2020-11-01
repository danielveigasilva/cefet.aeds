#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "helper.h"

void InsertRandomVector(int * vector, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        vector[i] = rand() % 100; 
}

int RandomSize(int max){
    srand(time(NULL));
    return (rand() % max);
}

void PrintTable(Table table[], int row, int col)
{
    int space[col];

    for (int j = 0; j < col; j++)
    {
        space[j] = strlen(table[j].title);

		for (int i = 0; i < row; i++)
        {
            if (strlen(table[j].row[i].charContent) > space[j])
                space[j] = strlen(table[j].row[i].charContent);
        }
    }

	int lenTable = 0;
	for(int j = 0; j < col; j++)
		lenTable += (space[j] + 1);
	for(int j = 0; j < lenTable; j++)
		printf("_");
	printf("\n");

	for(int j = 0; j < col; j++)
	{
		int add_space = space[j] - strlen(table[j].title);
        printf("|%s", table[j].title);
        for (int k = 0; k < add_space; k++)
            printf(" ");
	}
	printf("|\n");

    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int add_space = space[j] - strlen(table[j].row[i].charContent);
            printf("|%s", table[j].row[i].charContent);
            for (int k = 0; k < add_space; k++)
                printf(" ");
        }
        printf("|\n");
    }
}

void Int2Str(int num, char * str)
{
    int n = num;
    int len = 0, rem = 0;
    
    if (num != 0)
    {
        while (n != 0)
        {
            len++;
            n /= 10;
        }

        for (int i = 0; i < len; i++)
        {
            rem = num % 10;
            num = num / 10;
            str[len - (i + 1)] = rem + '0';
        }
    }
    else
    {
        str[0] = '0';
        len ++;
    }
    str[len] = '\0';
}

int countDigit(int n)
{
    int c = 0;
    while (n != 0) 
    {
        n /= 10;
        c++;
    }
    return c;
}

void SwapPosition(int *Vector, int i, int j){
    int aux = Vector[i];
    Vector[i] = Vector[j];
    Vector[j] = aux;
}

void printv(int Vector[], const int n){
    printf("[");
    for (int i = 0; i < n; i++){
        if (i != 0)
            printf(",");
        printf(" %d ", Vector[i]);
    }
    printf("]");
}

void sprintv(int Vector[], const int n, int selectItem){
    printf("[");
    for (int i = 0; i < n; i++){
        if (i != 0)
            printf(",");
        if (i == selectItem)
            printf("|%d|", Vector[i]);
        else
            printf(" %d ", Vector[i]);
    }
    printf("]");
    /*
    int count_total = 3 + (n - 2) + (2*(n - 2));
    int marca = 0;

    for (int x = 0; x < n; x++){
        count_total += countDigit(Vector[x]);
    }
    char line1[count_total];
    char line2[count_total];
    char line3[count_total];

    for (int y = 0; y < count_total; y ++){
        line1[y] = NULL;
        line2[y] = NULL;
        line3[y] = NULL;
    }
    strcat(line3,"[");
    int count_spaces = 1;

    for (int i = 0; i < n; i++){
        if (i != 0){
            strcat(line3,",");
            count_spaces ++;
        }
        int sizeNum = (2 + countDigit(Vector[i]));
        char textNum[sizeNum];
        sprintf(textNum," %d ", Vector[i]);
        strcat(line3,textNum);

        if (i == selectItem){           
            int med = (int) sizeNum/2;
            marca = count_spaces + med;
        }
        count_spaces += sizeNum;
    }
    for (int y = 0; y < count_total; y ++){
        if (y == marca && marca >0){
            line1[y] = '|';
            line2[y] = 'V';
        }
        else if (y == count_total - 1){
            line1[y] = '\0';
            line2[y] = '\0';
        }
        else{
            line1[y] = ' ';
            line2[y] = ' ';
        }
    }

    strcat(line3,"]\0");

    //printf("%s\n", line1);
    printf("%s\n", line2);
    //printf("%s", line3); 
    */
}