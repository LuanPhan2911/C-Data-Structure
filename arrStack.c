#include<stdio.h>

#define MaxLength 100
typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int TopIdx;	
} Stack;
void makenullStack(Stack *s){
	s->TopIdx = MaxLength;
}
int emptyStack(Stack s){
	return s.TopIdx==MaxLength;
}
int fullStack(Stack s){
	return s.TopIdx==0;
}
void push(ElementType x, Stack *s){
	if(fullStack(*s)){
		printf("Stack da day!");
	}else{
		s->TopIdx--;
		s->Elements[s->TopIdx]=x;
	}
}
void pop(Stack *s){
	s->TopIdx++;
}
ElementType top(Stack s){
	return s.Elements[s.TopIdx];
}
void printStack(Stack s){
	while(!emptyStack(s)){
		printf("%d ", top(s));
		pop(&s);
	}
	printf("\n");
}

