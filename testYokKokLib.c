#include <stdio.h>
//#include "pointerList.c"
//#include "arrStack.c"
//#include "pointerStack.c"
#include "arrCycleQueue.c";
#include <string.h>
void ignore(char *str)
{
	if (str[strlen(str) - 1] == '\n')
	{
		str[strlen(str) - 1] = '\0';
	}
}

void readFile(char *fileName, int *arr, int *n)
{
	FILE *f;
	f = fopen(fileName, "r");
	int x;
	while (!feof(f))
	{
		fscanf(f, "%d", &x);
		arr[*n] = x;
		(*n)++;
	}
}
int main()
{
	char *fileName = "data.txt";
	Queue q;
	int i;
	int arr[100], n = 0;
	readFile(fileName, arr, &n);
	makenullQueue(&q);
	printf("Du lieu tu file: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		enQueue(arr[i], &q);
	}

	while(!emptyQueue(q)){
		printf("%d ", front(q));
		deQueue(&q);
	}
	return 0;
}
