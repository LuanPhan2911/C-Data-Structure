#include<stdio.h>
#define MAXLENGTH 100
typedef int ElementType;
typedef int Position;
struct Dictionary{
	ElementType Data[MAXLENGTH];
	Position Last;	
};
typedef struct Dictionary Dictionary;

void makenullDictionary(Dictionary * d){
	d->Last=0;
}
int emptyDictionary(Dictionary d){
	return d.Last==0;
}
int fullDictionary(Dictionary d){
	return d.Last ==MAXLENGTH;
}
void insertDictionary(ElementType x, Dictionary *d){
	if(!member(x, d)){
		d->Data[d->Last]=x;
		(d->Last)++;
	}
}
int member(ElementType x, Dictionary d){
	int found =0;
	Position p =1;
	while(p <= d.Last && !found){
		if(d.Data[p-1]==x){
			found =1;
		}else{
			p++;
		}
	}
	return found;
}
void deleteDictionary(ElementType x, Dictionary *d){
	Position p =1;
	int found =0;
	while(p<= d->Last&& !found){
		if(d->Data[p-1]==x){
			found=1;
		}else{
			p++;
		}
	}
	if(found){
		d->Data[p-1]= d->Data[d->Last-1];
		(d->Last)--;
	
	}
}


