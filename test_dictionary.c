#include<stdio.h>
#include "hasing_open_dictionary.c"
void readFile(char* fileName, Dictionary *d){
	FILE *f;
	f=fopen(fileName, "r");
	int x;
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f, "%d", &x);
			insertDictionary(x, d);
		}
	}
	fclose(f);
}
void readDictionary(Dictionary d){
	int i=2;
		Position p;
		p= d[i];
		while(p->Next!=NULL){
			printf("%d ", p->Next->Data);
			p=p->Next;
		}

//	while(i < B){
//		p= d[i];
//		while(p->Next!=NULL){
//			printf("%d ", p->Next->Data);
//			p=p->Next;
//		}
//		i++;
//	}
}
int main(){
	Dictionary d;
	char *fileName ="data.txt";
	makenullDictionary(&d);
	readFile(fileName, &d);
	readDictionary(d);
//	deleteDictionary(23, &d);
//	deleteDictionary(54, &d);
//	deleteDictionary(3434, &d);
//	printf("\n");
//	readDictionary(d);
	
return 0;
}

