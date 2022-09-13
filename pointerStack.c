#include<stdio.h>
#include<stdlib.h>


typedef int ElementType;
 struct  Node{
	ElementType Element;
	struct Node *Top;
};
typedef struct Node Node;
typedef struct Node* Stack;
void makenullStack(Stack *s){
	Node* header= (Node *)malloc(sizeof(Node));
	header->Top=NULL;
	(*s)= header;
}
int emptyStack(Stack s){
	return s->Top==NULL;
}
void push(ElementType x, Stack *s){
	Node * header = *s;
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->Element= x;
	temp->Top= header->Top;
	header->Top= temp;
}
void pop(Stack *s){
	Node * temp = (*s)->Top;
	(*s)->Top= temp->Top;
	free(temp);
}
ElementType top(Stack s){
	return s->Top->Element;
}
void printStack(Stack s){
	while(!emptyStack(s)){
		printf("%d ", top(s));
		pop(&s);
	}
	printf("\n");
}

