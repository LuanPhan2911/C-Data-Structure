#include<stdio.h>
#define MaxLength 100
typedef  int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List;
void makenullList (List * l){
	l->Last =0;
}
int emptyList(List l){
	return l.Last ==0;
}
int fullList(List l){
	return l.Last==MaxLength;
}
Position first(List l){
	return 1;
}
Position endList(List l){
	return l.Last+1;
}
Position next (Position p, List l){
	return p+1;
}
Position previous(Position p, List l){
	return p-1;
}
ElementType retrieve(Position p, List l){
	return l.Elements[p-1];
}
void insertList(ElementType x, Position p, List *l){
	if(l->Last==MaxLength){
		printf("Danh sach day!\n");
	}else if(p<1 || p>l->Last+1){
		printf("Vi tri khong hop le!\n");
	}else{
		Position q= l->Last;
		while(q>= p){
			l->Elements[q]=l->Elements[q-1]; 	
			q--;
		}
		l->Elements[p-1]= x;
		l->Last++;	
	}
}
void deleteList(Position p, List *l){
	if(p<1 || p>l->Last){
		printf("Vi tri khong hop le!\n");
	}else if(emptyList(*l)){
		printf("Danh sach rong!\n");
	}else{
		Position q = l->Last;
		while(p<q){
			l->Elements[p-1]= l->Elements[p];
			p++;
		}
		l->Last--;
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
    Position n;
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
					swap(&l->Elements[p-1], &l->Elements[q-1]);
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
					swap(&l->Elements[p-1], &l->Elements[q-1]);
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

