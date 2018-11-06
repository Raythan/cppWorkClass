#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 10
int nRange(int menor, int maior) {
    return rand()%(maior-menor+1) + menor;
}
void printShotable(int vt[][MAX]){
	int i, j;
	for(i=0;i<MAX;i++){
		printf("| ");
		for(j=0;j<MAX;j++){
			printf("%d | ", vt[i][j]);
		}
		printf("\n");
	}
};
void printTarget(int vt[][MAX]){
	int i, j;
	printf("\n\n  | ");
	for(j=0;j<MAX;j++){
		printf("%d | ", j);
	}
	printf("\n");
	for(i=0;i<MAX;i++){
		printf("%d | ", i);
		for(j=0;j<MAX;j++){
			if(vt[i][j]!=0){
				printf("S | ");
			}else{
				printf("N | ");
			}
			
		}
		printf("\n");
	}
};
int preenche(int vt[][MAX]){
	int i, j;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			vt[i][j] = nRange(0, 1);
		}
	}
};


int main(){
	//Variáveis
	int vt[MAX][MAX], vt2[MAX][MAX];	
	srand(time(NULL));
	preenche(vt);
	printShotable(vt);
	printTarget(vt);
	return 0;
}
