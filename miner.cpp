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
void printTarget(int vtv[][MAX]){
	int i, j;
	printf("\n\n  | ");
	for(j=0;j<MAX;j++){
		printf("%d | ", j);
	}
	printf("\n");
	for(i=0;i<MAX;i++){
		printf("%d | ", i);
		for(j=0;j<MAX;j++){
			if(vtv[i][j]==NULL){
				printf("  | ");
			}else if(vtv[i][j]==3){
				printf("0 | ", vtv[i][j]);
			}else if(vtv[i][j]==4){
				printf("X | ", vtv[i][j]);
			}else{
				printf("  | ", vtv[i][j]);
			}			
		}
		printf("\n");
	}
};
void preenche(int vt[][MAX]){
	int i, j;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			vt[i][j] = nRange(0, 1);
		}
	}
};
void preencheAlvo(int vt[][MAX], int vt2[][MAX], int x, int y, int i){
	if((vt2[x][y]==3&&vt[x][y]==0)){
		printf("Voce ja jogou nessa posicao.");
	}else if(vt[x][y]==0){
		vt2[x][y] = 3;	
	}else if(vt[x][y]==1){
		vt2[x][y] = 4;
	}
};
int check(int vt[][MAX], int x, int y){
	if(vt[x][y]==1){
		system("cls");
		printf("Perdeu, Acertou a mina!\n");
		return 0;
	} 
	return 1;
}

int main(){
	//Variáveis
	int vt[MAX][MAX], vt2[MAX][MAX], x, y, i=1;	
	srand(time(NULL));
	preenche(vt);
	printShotable(vt);
	printTarget(vt2);
	while(i!=0){
		printf("Linha: ");
		scanf("%d", &x);
		printf("Coluna: ");
		scanf("%d", &y);
		system("cls");
		preencheAlvo(vt, vt2, x, y, i);
		printf("\nUltima jogada: %d %d\n%d\n\n", x, y, i);
		i = check(vt, x ,y);
		if(i==0){
			printShotable(vt);
			printTarget(vt2);	
		}else{
			printTarget(vt2);
		}
	}
	return 0;
}
