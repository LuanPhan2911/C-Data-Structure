#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node * Next;
};
typedef struct Node Node;
typedef struct Node* Position;
typedef struct Node * List;

void makenullList (List * l){
	Node * header = (Node*)malloc(sizeof(Node));
	header->Next =NULL;
	*l= header;
	
}
int emptyList(List l){
	return l->Next==NULL;
}

Position first(List l){
	return l;
}
Position endList(List l){
	Position p = l;
	while(p->Next!=NULL){
		p= p->Next;
	}
	return p;
}
Position next (Position p, List l){
	return p->Next;
}
Position previous(Position p, List l){
	Position q= l;
	while(q->Next!=p){
		
		q=q->Next;
	}
	return q;
}
ElementType retrieve(Position p, List l){
	if(p->Next!=NULL){
		return p->Next->Element;
	}

}
Position locate(ElementType x, List l){
	Position p= l;
	int found =0;
	while(p->Next!=NULL && !found){
		if(p->Next->Element==x){
			found=1;
		}else{
			p= p->Next;
		}
	}
	return p;
}
void insertList(ElementType x, Position p, List *l){
	Position temp =(Node *)malloc(sizeof(Node));
	temp->Element= x;
	temp->Next= p->Next;
	p->Next= temp;
}
void deleteList(Position p, List *l){
	Position temp;
	if(p->Next!=NULL){
		temp = p->Next;
		p->Next= temp->Next;
		free(temp);
	}
}
void printList(List l){
    Position e = endList(l), p= first(l);
    while(p!=e){
        printf("%d ", retrieve(p, l ));
        p= next(p, l);
    }
    printf("\n");
}

void readList(List *l){
    makenullList(l);
    ElementType x;
    int n;
    printf("Nhap so phan tu cua danh sach:\n");
    scanf("%d", &n);
    printf("Nhap gia tri cho dan sach: \n");
    int i;
    for( i=0; i<n; i++){
        scanf("%d", &x);
        insertList(x, endList(*l), l);
    }
}
void swap(ElementType *a, ElementType *b){
	int temp = *a;
	*a = *b;
	*b= temp;	
}
void sort(List *l, int type){
	Position p= first(*l), q, e= endList(*l);
	if(type>=0){
		while(p!=e){
			q= next(p, *l);
			while(q!=e){
				if(retrieve(p, *l)>retrieve(q, *l)){
					swap(&p->Next->Element, &q->Next->Element);
				}
				q=next(q, *l);
			}
			p=next(p, *l);
		}
		return;
	}
		while(p!=e){
			q= next(p, *l);
			while(q!=e){
				if(retrieve(p, *l)<retrieve(q, *l)){
					swap(&p->Next->Element, &q->Next->Element);
				}
				q=next(q, *l);
			}
			p=next(p, *l);
		}
}

void distinct(List *l){
	Position p= first(*l), q;
	while(p!=endList(*l)){
		q= next(p, *l);
		while(q!=endList(*l)){
			if(retrieve(p, *l)==retrieve(q, *l)){
				deleteList(q, l);
				q= previous(q, *l);
			}
			q=next(q, *l);
		}
		p=next(p, *l);
	}
}

