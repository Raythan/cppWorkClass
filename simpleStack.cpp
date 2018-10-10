#include <stdio.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

/* int numeroAleatorio(int menor, int maior) {
    return rand()%(maior-menor+1) + menor;
} */

typedef struct stackList{
	int data;
	struct stackList *next;	
};



void push(struct stackList **top, int num){
	stackList *ptr;
	
	ptr = (stackList *) malloc(sizeof(stackList));
	ptr->data = num;
	if(*top==NULL){
		*top = ptr;
		ptr->next = NULL;
		printf("Entrei no if do PUSH, PTR == NULL\n\n");
	}else{
		ptr->next = *top;
		*top = ptr;
		printf("Entrei no else do PUSH, PTR != NULL\n\n");
	}
};

void pop(struct stackList **top){ // CONTINUAR DAQUIIIIIIi
	stackList *ptr;
	if(*top==NULL){
		system("cls");
		printf("Lista vazia, favor adcionar novos elementos antes de remover.\n");
	}else{
		ptr = *top;
		*top = top->next;
		free(ptr);
	}
};
int peek();
int display();
int pushAuto();
int destroy();

int decision(int x){
	system("cls");
	printf("Quer continuar ou sair?\t");
	scanf("%d", &x);
	system("cls");
	return x;
};

int header(int x){
	printf("Digite a operacao desejada.\n");
	printf("1 - Adicionar numeros manualmente.\n");
	printf("2 - Remover numeros manualmente.\n");
	printf("3 - Mostrar primeiro elemento da lista.\n");
	printf("4 - Mostrar lista.\n");
	printf("5 - Adicionar N numeros automaticamente.\n");
	printf("6 - Destruir lista.\n");
	printf("0 - Sair.\n");
	scanf("%d", &x);
	system("cls");
	return x;
}

int main(){
	// Variáveis
	int tamanho = 1, num;
	stackList *top = NULL;
	
	// Aplicação
	while(tamanho!=0){
		tamanho = header(tamanho);
		
		switch(tamanho){
			case 1:
				printf("Digite o numero para adicionar: ");
				scanf("%d", &num);
				push(&top, num);
				//tamanho = decision(tamanho);
				tamanho = 1;
				break;
			case 2:
				pop(&top);
				tamanho = decision(tamanho);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;	
		}
	}
	return 0;
}
