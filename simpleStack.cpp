#include <stdio.h>
#include <stdlib.h>	// necessário p/ as funções rand() e srand()
#include <time.h>	//necessário p/ função time()

int numeroAleatorio(int menor, int maior) { // Função que adiciona números aleatoriamente
    return rand()%(maior-menor+1) + menor;
} 

typedef struct stackList{ // Struct para ser usada como lista...
	int data;
	struct stackList *next;	
};



void push(struct stackList **top, int num){ // Função que insere um elemento na cabeça da lista
	system("cls");
	stackList *ptr;
	ptr = (stackList *) malloc(sizeof(stackList));
	ptr->data = num;
	if(*top==NULL){
		*top = ptr;
		ptr->next = NULL;
	}else{
		ptr->next = *top;
		*top = ptr;
	}
	printf("Numero %d adicionado com sucesso!\n\n\n", num);
};

void pop(struct stackList **top){ // Função que remove o último elemento inserido - cabeça do nó
	system("cls");
	stackList *ptr;
	if(*top==NULL){
		printf("Lista vazia! Nao ha o que remover.");
	}else{
		ptr = *top;
		*top = ptr->next;
		free(ptr);
		printf("Operacao realizada com sucesso!");
	}
	printf("\n\n\n");
};

int peek();

int display(struct stackList **top){ // Função que imprime a lista pegando como parâmetro a cabeça do nó
	system("cls");
	struct stackList *ptr;
	ptr = *top;
	if(*top==NULL){
		printf("Lista vazia!");
	}else{
		printf("Lista: ");
		while(ptr!=NULL){
			printf("%d | ", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n\n\n");
};
int pushAuto(struct stackList **top, int a){ // Função que insere elementos aleatoriamente pela cabeça da lista
	system("cls");
	int i = 0;
	while(i<a){
		push(top, numeroAleatorio(1, 100));
		i++;
	}
};
int destroy(struct stackList **top){ // Função destroi lista chamando a função pop() que elimina elemento por elemento da cabeça da lista
	system("cls");
	if(*top==NULL){
		printf("Lista vazia! Nao ha o que destruir.\n\n\n");
	}else{
		while(*top!=NULL){
			pop(top);
		}
	}
	
};

int header(int x){ // Cabeçalho que mostra ao usuário o que ele pode fazer
	printf("Digite a operacao desejada.\n");
	printf("1 - Adicionar numeros manualmente.\n");
	printf("2 - Remover ultimo numero.\n");
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
	int tamanho = 1, // condicao necessária para execução do laço até o usuário resolver sair
	num; // Variável auxiliar para numeros manuais e quantidade de numeros inseridos automaticamente
	stackList *top = NULL; // Ponteiro que informa a cabeça da lista
	
	// Aplicaçãos
	srand(time(NULL)); // Funcao necessária para os numeros serem inseridos sem repetição
	while(tamanho!=0){
		tamanho = header(tamanho);
		
		switch(tamanho){
			case 1:
				printf("Digite o numero para adicionar: "); // Pergunta para saber qual numero adicionar
				scanf("%d", &num);
				push(&top, num); // Função insere números manualmente
				break;
			case 2:
				pop(&top); // Função que remove o último elemento da lista
				break;
			case 3:
				break;
			case 4:
				display(&top); // Função que imprime a lista
				break;
			case 5:
				printf("Quantos numeros quer adicionar? "); // Pergunta para saber quantidade a ser inserida
				scanf("%d", &num);
				pushAuto(&top, num); // Função explicada anteriormente
				break;
			case 6:
				destroy(&top); // Função destroi lista
				break;	
		}
	}
	return 0;
}
