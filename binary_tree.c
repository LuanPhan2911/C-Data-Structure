#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
struct Node{
	DataType Data;
	struct Node *Left, *Right; 
};
typedef struct Node Node;
typedef struct Node* Tree;

void makenullTree(Tree *t){
	(*t)=NULL;
}
int EmptyTree(Tree t){
	return t==NULL;
}
Tree leftChild(Tree t){
	if(t!=NULL){
		return t->Left;
	}
	return NULL;
}
Tree rightChild(Tree t){
	if(t!=NULL){
		return t->Right;
	}
	return NULL;
}
int isLeaf(Tree t){
	if(t!=NULL){
		return leftChild(t)==NULL && rightChild(t) ==NULL;
	}
	return 0;
}
void preOrder(Tree t){
	if(t!=NULL){
		printf("%d ", t->Data);
		if(leftChild(t)!=NULL){
			preOrder(leftChild(t));
		}
		if(rightChild(t)!=NULL){
			preOrder(rightChild(t));
		}
	}
}
void inOrder(Tree t){
	if(t!=NULL){
	
		if(leftChild(t)!=NULL){
			inOrder(leftChild(t));
		}
		printf("%d ", t->Data);
		if(rightChild(t)!=NULL){
			inOrder(rightChild(t));
		}
	}
}
void posOrder(Tree t){
	if(t!=NULL){
	
		if(leftChild(t)!=NULL){
			posOrder(leftChild(t));
		}
		if(rightChild(t)!=NULL){
			posOrder(rightChild(t));
		}
			printf("%d ", t->Data);
	}
}
int nb_nodes(Tree t){
	if(t==NULL){
		return 0;
	}else{
		return 1+ nb_nodes(leftChild(t))+ nb_nodes(rightChild(t));
	}
}
int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
Tree create2(DataType data, Tree left, Tree right){
	Tree t;
	t= (Tree)malloc(sizeof(Node));
	t->Data= data;
	t->Left= left;
	t->Right= right;
	return t;
}
Tree createNode(DataType data){
	Tree t;
	makenullTree(&t);
	t= (Tree)malloc(sizeof(Node));
	t->Data= data;
	t->Left=NULL;
	t->Right=NULL;
}
int heightTree(Tree t){
	if(t==NULL){
		return 0;
	}else{
		return max(heightTree(leftChild(t)), heightTree(rightChild(t)))+1;
	}
}
int maxTree(Tree t){
	if(t==NULL){
		return -999;
	}
	int max= t->Data;
	int maxLeft = maxTree(leftChild(t));
	int maxRight = maxTree(rightChild(t));
	if(max < maxLeft){
		max = maxLeft;
	}
	if(max <maxRight){
		max = maxRight;
	}
	return max;
}



