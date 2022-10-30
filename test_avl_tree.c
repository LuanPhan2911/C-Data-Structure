
#include "AVL_tree.c"
void readFile(char * fileName, int *arr, int *n){
	FILE *f;
	f= fopen(fileName, "r");
	int x;
	while(!feof(f)){
		fscanf(f, "%d", &x);
		arr[*n]=x;
		(*n)++;
	}
	fclose(f);
}
void initTree(Tree *t, int * arr, int n){
	int i;
	for(i=0; i< n; i++){
		insertNode(arr[i], t);
	}
}
int main(){
	Tree t;
	char *fileName ="avl_tree.txt";
	makenullTree(&t);
	
	int arr[100];
	int n =0;
	readFile(fileName, arr, &n);
	initTree(&t, arr, n);
	inOrder(t);
return 0;
}

