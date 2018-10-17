
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numeroAleatorio(int menor, int maior) { // Função que adiciona números aleatoriamente
    return rand()%(maior-menor+1) + menor;
}

typedef struct queueList{ // Struct para ser usada como lista...
	int data;
	struct queueList *next;	
};

typedef struct q{ // Struct que vai apontar para a cabeça e fim da lista
	struct queueList *front;
	struct queueList *rear;
};

void rear(q *pointer, queueList *lista, int a){ // Adicionar elementos no fim da lista
	queueList *ptr;
	ptr = (queueList *)malloc(sizeof(queueList));
	ptr->data = a;
	pointer->front = pointer->rear = lista; // <<<<<<<<<<<<<< ERRO NESSA PARTE
	// printf("pointer->front->data: %d\npointer->rear->data: %d\nlista->data: %d.", pointer->front->data, pointer->rear->data, lista->data );
	
}; 

void front(); // Remover elementos
void display(); // Imprime a lista
void rearAleatorio(); // Insere numeros aleatórios na fila

int header(int x){ // Cabeçalho que mostra ao usuário o que ele pode fazer
	printf("Digite a operacao desejada.\n");
	printf("1 - Adicionar numeros manualmente.\n");
	printf("2 - Remover primeiro numero.\n");
	printf("4 - Mostrar lista.\n");
	printf("5 - Adicionar N numeros automaticamente.\n");
	printf("6 - Apaga lista.\n");
	printf("0 - Sair.\n");
	scanf("%d", &x);
	system("cls");
	return x;
}

int main(){
	//Variáveis
	int n = 1, // Quantidade de números para serem adicionados e 
	d = 1; // Decisao do switch
	queueList lista; // lista
	q *pointer;
	
	// Implementação
	srand(time(NULL)); // Funcao necessária para os numeros serem inseridos sem repetição
	while(d!=0){
		d = header(d);
		switch(d){
			case 1:
				printf("Que numero gostaria de adicionar?\n");
				scanf("%d", &n);
				rear(pointer, &lista, n);
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 0:
				break;
		}
	}
	system("cls");
	printf("\n\n\nFechando programa.\nPrograma desenvolvido por Raythan Padovani Abreu Machado.\nObrigado por utilizar este software.");
	
	return 0;
}
