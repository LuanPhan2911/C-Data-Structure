#include<stdio.h>
#define MAXLENGHT 100
typedef int ElementType;
struct Queue{
	ElementType Elements[MAXLENGHT];
	int Front, Rear;
};
typedef struct Queue Queue;
void makenullQueue(Queue *q){
	q->Rear =-1;
	q->Front =-1;
}
int emptyQueue(Queue q){
	return q.Rear ==-1;
}
int fullQueue(Queue q){
	return (q.Rear - q.Front+1)%MAXLENGHT ==0;
}
ElementType front(Queue q){
	return q.Elements[q.Front];
}
void deQueue(Queue *q){
	if(q->Rear ==q ->Front){
		makenullQueue(q);
	}else{
		q->Front =(q->Front+1)% MAXLENGHT;
	}
}
void enQueue(ElementType x, Queue *q){
	if(fullQueue(*q)){
		printf("Hang day!");
	}else{
		if(emptyQueue(*q)){
			q->Front=0;
		}
		q->Elements[(++q->Rear)%MAXLENGHT]=x;
	}
	
}


