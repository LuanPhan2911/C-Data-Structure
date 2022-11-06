#include<stdio.h>
#include <time.h>
#include <stdlib.h>
int random_number(){

	int r = rand();
	return r;
}
void writeFile(char * fileName){
	FILE *f;
	f=fopen(fileName,"w");
	if(f!=NULL){
		int i;
		for(i=0; i< 1000; i++){
			if(i%5==0){
				fprintf(f,"\n");
			}
			fprintf(f, "%d ", random_number());
		}
		printf("Da them thanh cong %d phan tu",i );
	}else{
		printf("Loi mo file");
	}
	fclose(f);
}

int main(){
	char *fileName ="random_int.txt";
	srand(time(NULL));   
	writeFile(fileName);





return 0;
}

