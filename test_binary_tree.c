#include<stdio.h>
#include<string.h>
#include "binary_tree.c"
int findIndex(DataType x, char *str, int start, int end){
	int i= start;
	while(i<=end){
		if(str[i]==x){
			return i;
		}else{
			i++;
		}
	}
	return i;
}
int preIndex =0;
Tree createTree(char * pre, char * in, int start, int end){
    Tree n;
    makenullTree(&n);
    if(start <= end){
        n=(Tree)malloc(sizeof(struct Node));
        n->Data= pre[preIndex];
        preIndex++;
        if(start ==end){
            n->Left=NULL;
            n->Right=NULL;
        }else{
        	int inIndex =findIndex(n->Data, in, start, end);
            n->Left=createTree(pre, in, start, inIndex-1);
            n->Right = createTree(pre, in, inIndex+1,end );
         }
    }
    return n;
}
void ignore(char *str){
	if(str[strlen(str)-1]=='\n'){
		str[strlen(str)-1]='\0';
	}
}
void readFile(char * fileName, char * preOrderText, char * inOrderText){
	FILE *f;
	f= fopen(fileName, "r");
	fgets(preOrderText, 100, f);
	fgets(inOrderText, 100, f);
	ignore(preOrderText);
	ignore(inOrderText);
	
}

int main(){
//	char *fileName ="test_binary_tree.txt";
//	char preOrderText[100];
//	char inOrderText[100];
//	readFile(fileName, preOrderText, inOrderText);
//	Tree t= createTree(preOrderText, inOrderText, 0, strlen(preOrderText)-1);
	Tree t= createNode(1);
	t->Left = createNode(2);
	t->Right= createNode(3);
	t->Left->Left= createNode(4);
	t->Left->Right= createNode(6);
	t->Right->Left = createNode(10);
	t->Right->Right = createNode(5);
	t->Right->Right->Left= createNode(10);
	posOrder(t);
	printf("\n%d", maxTree(t));
	
	return 0;
}

