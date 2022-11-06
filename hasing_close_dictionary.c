#include<stdio.h>
#define B 100
#define Empty 1000
#define Deleted -1000
typedef int ElementType;
typedef ElementType Dictionary[B];

void makenullDictionary(Dictionary *d){
	int i=0;
	while(i< B){
		(*d)[i]= Empty;
		i++;
	}
}
int emptyDictionary(Dictionary d){
	int isEmpty =1;
	int i=0;
	while(i< B && isEmpty){
		if(d[i]!=Empty&& d[i]!=Deleted){
			isEmpty=1;
		}else{
			i++;
		}
	}
	return isEmpty;
}
int h(ElementType x){
	return x% B;
}

int member(ElementType x, Dictionary d){
	int p= h(x);
	int i=0, found =0;
	while(i< B && !found && d[(i+p) % B]!=Empty ){
		if(d[p]==x){
			found =1;
		}else{
			i++;	
		}
	
	}
	return found;
}
void insertDictionary(ElementType x, Dictionary *d){
	if(!member(x,*d)){
		int p= h(x);
		int i=0;
		while(i < B&& (*d)[(i+p)%B]!=Empty && (*d)[(i+ p)% B]!=Deleted){
			i++;
		}
		if(i < B){
			(*d)[(i+p)%B]= x;
		}
	}
	
}
void deleteDictionary(ElementType x, Dictionary (*d)){
	int p= h(x);
	int i=0, found =0;
	while(i<B&& !found && (*d)[(i+p)%B]!=Empty){
		if((*d)[i]==x){
			found =1;
		}else{
			i++;
		}
	}
	if(found){
		(*d)[(i+p)%B]= Deleted;
	}
}

