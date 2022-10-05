#include <stdio.h>
#define MAXLENGHT 100
typedef int ElementType;
struct Queue{
	ElementType Elements[MAXLENGHT];
	int Front, Rear;
};
typedef struct Queue Queue;
void makenullQueue(Queue *q){
	q->Front =-1;
	q->Rear =-1;
}
int emptyQueue(Queue q){
	return q.Rear ==-1;
}
int fullQueue(Queue q){
	return q.Rear - q.Front+1 ==MAXLENGHT;
}
ElementType front(Queue q){
	return q.Elements[q.Front];
}
void enQueue(ElementType x, Queue *q){
	int i;
	if(fullQueue(*q)){// hang day
		printf("Hang day!");
	}else{
		if(emptyQueue(*q)){//hang rong
		q->Front =0;
		}
		if(q->Rear== MAXLENGHT-1){	//hang bi tran
			for(i = q->Front; i<= q->Rear; i++){
				q->Elements[i- q->Front]= q->Elements[i];
			}
			q->Front =0;
		}
		q->Elements[++q->Rear]= x;
	}
	
}
void deQueue(Queue *q){
	// hàng có 1 phan tu
	if(q->Front== q->Rear){
		makenullQueue(q);
	}else{
		q->Front++;
	}
}



