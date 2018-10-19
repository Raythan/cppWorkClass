#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numeroAleatorio(int menor, int maior) { // Função que adiciona números aleatoriamente
    return rand()%(maior-menor+1) + menor;
}

typedef struct node{ // Struct para ser usada como lista...
	int data;
	struct node *next;	
};



void insertMaiorMenor(node **p, int a){ // Do maior para o menor
	// Variáveis
    node *ptr2, *ptr, *ptr3;
    ptr = (node *) malloc(sizeof(node));
    ptr2 = *p;
    ptr3 = NULL;
    
    // Contruct
    ptr->data = a;
	
	// Métodos	
    if(ptr2 == NULL){ // Se não tiver elementos em ptr ele aponta para o nó criado
        ptr->next = NULL;
        *p = ptr;
    }else{ // Se existir elementos vai checando
        while(ptr2 != NULL && ptr2->data > ptr->data){ // valor do atual maior que o novo? se sim, 
            ptr3 = ptr2; // o anterior antes 'nulo' recebe o atual
            ptr2 = ptr2->next; // atual recebe o próximo
        }
        ptr->next = ptr2; // próximo do que foi criado recebe o atual
        if(ptr3 == NULL){ // Se o anterior for igual a nulo entao o atual recebe novo
            *p = ptr;
        } else{ // Se não o anterior recebe o novo
            ptr3->next = ptr;
        }
    }
    system("cls");
	printf("\nAdicionei %d a lista\n\n", a);
}

void insert(node **front, node **rear, int a){ // Adicionar elementos no fim da lista
	int i = 0;
	if(*front==NULL){
		node *ptr = (node *)malloc(sizeof(node));
		*front = *rear = ptr;
		ptr->data = a;
		ptr->next = NULL;
		system("cls");
		printf("\nAdicionei %d a lista que estava vazia\n\n", a);
	}else{
		node *ptr = (node *)malloc(sizeof(node)); // valor do nó a ser atribuido
		node *ptr2 = *rear; // checa posição atual
		
		// Parte que atribui os valores a serem adicionados
		ptr->data = a;
		ptr->next = NULL;
		
		ptr2->next = ptr;
		ptr2 = ptr;
		*rear = ptr2;
		printf("\nAdicionei %d a lista\n\n", a);
	}
}; 


void front(); // Remover elementos
void display(node *ptr, node *rear){ // Imprime a lista
	system("cls");
	printf("Primeiro -> ");
	while(ptr!=NULL){
		//if(ptr!=rear){
			printf("| %d | ", ptr->data);
		//}
		
		ptr = ptr->next;
	}
	printf("<- Ultimo.");
	printf("\n\n\n");
}; 
void rearAleatorio(); // Insere numeros aleatórios na fila

int header(int x){ // Cabeçalho que mostra ao usuário o que ele pode fazer
	printf("Digite a operacao desejada.\n");
	printf("1 - Adicionar numeros manualmente.\n");
	printf("2 - Remover primeiro numero.\n");
	printf("4 - Mostrar lista.\n");
	printf("5 - Adicionar N numeros automaticamente.\n");
	printf("6 - Apaga lista.\n");
	printf("0 - Sair.\n");
	printf("Opcao: ");
	scanf("%d", &x);
	system("cls");
	return x;
}

int main(){
	//Variáveis
	int n = 1, // Quantidade de números para serem adicionados e 
	d = 1;  // Decisao do switch
	node *front, // cabeça
	*rear, // fim da lista
	*ptr; // percorre a lista
	
	rear = front = NULL;
	
	// Implementação
	srand(time(NULL)); // Funcao necessária para os numeros serem inseridos sem repetição
	while(d!=0){
		d = header(d);
		switch(d){
			case 1:
				printf("Que numero gostaria de adicionar?\n");
				scanf("%d", &n);
				insert(&front, &rear, n);
				//printf("front->data: %d\nfront->next: %d\nrear->data: %d\nrear->next: %d\n\n", front->data, front->next, rear->data, rear->next);
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				ptr = front;
				display(ptr, rear);
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
