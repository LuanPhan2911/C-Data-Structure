#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left, *Right;
	int height; 
};
typedef struct Node* Tree;
Tree search(KeyType x, Tree t){
	if(t==NULL){
		return NULL;
	}
	if(t->Key > x){
		return search(x, t->Left);
	}
	if(t->Key < x){
		return search(x, t->Right);
	}
	return t;
}
void makenullTree(Tree *t){
	*t=NULL;
}
void createNode(KeyType x, Tree * t){
	makenullTree(t);
	(*t)= (Tree)malloc(sizeof(struct Node));
		(*t)->Key=x;
		(*t)->Left=NULL;
		(*t)->Right=NULL;
		(*t)->height= 1;
}
void leftRotate(Tree *t){
	Tree n = (*t)->Right;
	Tree temp = n->Left;
	
	(*t)->Right= temp;
	n->Left= (*t);
	
	(*t)->height= max(height((*t)->Left), height((*t)->Right)) +1;
	n->height= max(height(n->Left), height(n->Right))+1;

	*t= n;
	
}
void rightRotate(Tree *t){
	Tree n= (*t)->Left;
	Tree temp= n->Right;
	
	n->Right = (*t);
	(*t)->Left= temp;
	
	(*t)->height= max(height((*t)->Left), height((*t)->Right)) +1;
	n->height= max(height(n->Left), height(n->Right))+1;
	
	*t= n;
	
}
void insertNode(KeyType x, Tree *t){
	if((*t)==NULL){
		createNode(x, t);
	}else{
		if((*t)->Key < x){
			insertNode(x, &(*t)->Right);
		}
		if((*t)->Key > x){
			insertNode(x, &(*t)->Left);
		}
	}
	(*t)->height= 1+ max(height((*t)->Left), height((*t)->Right));
	int balance = getBalance(*t);
//	printf("Check balance %d\n", balance);
	if(balance > 1 && x < (*t)->Left->Key){
		//LL
		rightRotate(t);
	}
	if(balance > 1 && x > (*t)->Left->Key){
//		//RL
		leftRotate(&(*t)->Left);
		rightRotate(t);
	}
	if(balance < -1 && x > (*t)->Right->Key){
		//RR
		leftRotate(t);
	}
	if(balance < -1 && x < (*t)->Right->Key){
		//LR
		rightRotate(&(*t)->Right);
		leftRotate(t);	
	}
	

}

int getBalance(Tree t){
	if(t==NULL){
		return 0;
	}else{
		return height(t->Left)- height(t->Right);
	}
}
int max(int a, int b){
	return a> b? a: b;
}
int height(Tree t){
	if(t==NULL){
		return 0;
	}else{
		return t->height;
	}
}
void inOrder(Tree t){
	if(t!=NULL){
		inOrder(t->Left);
		printf("%d -> %d\n", t->Key, t->height);
		inOrder(t->Right);
	}
}

