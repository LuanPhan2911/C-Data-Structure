#include<stdio.h>
#include<stdlib.h>
#define B 10
typedef int ElementType;
struct Node{
	ElementType Data;
	struct Node * Next;
};
typedef struct Node Node;
typedef Node* Position;
typedef Position Dictionary[B];
int h(ElementType x){
	return x % B;
}
void makenullDictionary(Dictionary *d){
	int i;
	for(i=0; i <B; i++){
		(*d)[i]= (Node *)malloc(sizeof(Node));
		(*d)[i]->Next=NULL;
	}
}
int member(ElementType x, Dictionary d){
	Position p = d[h(x)];
	int found =0;
	while(p->Next!=NULL && !found){
		if(p->Next->Data==x){
			found =1;
		}else{
			p= p->Next;	
		}	
	}
	return found;
}
void insertDictionary(ElementType x, Dictionary *d){
	Position p = (*d)[h(x)];
	int found =0;
	while(p->Next!=NULL && !found && p->Next->Data <=x){
		if(p->Next->Data==x){
			found =1;
		}else{
			p= p->Next;
		}
	}
	if(!found){
		Position temp = (Node*)malloc(sizeof(Node));
		temp->Data=x;
		temp->Next= p->Next;
		p->Next= temp;
	}
}
void deleteDictionary(ElementType x, Dictionary *d){
	Position p= (*d)[h(x)];
	int found =0;
	while(p->Next!=NULL && !found && p->Next->Data <=x){
		if(p->Next->Data==x){
			found=1;
		}else{
			p=p->Next;
		}
	}
	if(found){
		Position temp = p->Next;
		p->Next = temp->Next;
		free(temp);
	}
}

