#include <stdio.h>
#include "arrList.c"
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
	int arr[100], n = 0;
	List l;
	int i;
	makenullList(&l);

	readFile(fileName, arr, &n);
	printf("Du lieu tu file: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		insertList(arr[i], endList(l), &l);
	}
	printf("Du lieu tu List: \n");
	printList(l);
	sort(&l, 1);
	printf("Du lieu da sap xep: \n");
	printList(l);
	distinct(&l);
	printf("Du lieu da loc trung: \n");
	printList(l);

	return 0;
}
