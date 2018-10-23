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
		printf("Adicionei %d a lista que estava vazia\n\n\n", a);
	}else{
		node *ptr = (node *)malloc(sizeof(node)); // valor do nó a ser atribuido
		node *ptr2 = *rear; // checa posição atual
		
		// Parte que atribui os valores a serem adicionados
		ptr->data = a;
		ptr->next = NULL;
		
		ptr2->next = ptr;
		ptr2 = ptr;
		*rear = ptr2;
		printf("Adicionei %d a lista\n\n\n", a);
	}
};

void insertNoPrint(node **front, node **rear, int a){ // Adicionar elementos no fim da lista
	int i = 0;
	if(*front==NULL){
		node *ptr = (node *)malloc(sizeof(node));
		*front = *rear = ptr;
		ptr->data = a;
		ptr->next = NULL;
	}else{
		node *ptr = (node *)malloc(sizeof(node)); // valor do nó a ser atribuido
		node *ptr2 = *rear; // checa posição atual
		
		// Parte que atribui os valores a serem adicionados
		ptr->data = a;
		ptr->next = NULL;
		
		ptr2->next = ptr;
		ptr2 = ptr;
		*rear = ptr2;
	}
}; 

void remove(node **c, node *p){  // Remover elementos
	if(*c==NULL){
		printf("Lista vazia!");
	}else{
		p = *c;
		printf("%d removido.", p->data);
		*c = p->next;
		free(p);
	}
	printf("\n\n\n");
};

void display(node *ptr, node *rear){ // Imprime a lista
	system("cls");
	if(ptr!=NULL){
		printf("Primeiro -> ");
		while(ptr!=NULL){
			//if(ptr!=rear){
				printf("| %d | ", ptr->data);
			//}
			
			ptr = ptr->next;
		}
		printf("<- Ultimo.");
	}else{
		printf("Lista vazia!");
	}
	printf("\n\n\n");
}; 

void rearAleatorio(int n,node **front, node **rear){ // Insere numeros aleatórios na fila
	int i, aux;
	system("cls");
	printf("Quantos numeros gostaria de adicionar?\n");
	scanf("%d", &n);
	if(n==1){
		for(i=0;i<n;i++){
			aux = numeroAleatorio(0, 100);
			insertNoPrint(front, rear, aux);
		}
		system("cls");
		printf("%d numero adicionado a lista.", n);	
	}else if(n>0){
		for(i=0;i<n;i++){
			aux = numeroAleatorio(0, 100);
			insertNoPrint(front, rear, aux);
		}
		system("cls");
		printf("%d numeros adicionados a lista.", n);	
	}
	else{
		printf("O valor precisa ser maior que 0.");
	}
	
	printf("\n\n\n");
};

void destroy(node **f, node *pp){ // Apaga lista por completo
	system("cls");
	if(*f==NULL){
		printf("Lista vazia!");
	}else{
		while(*f!=NULL){
			remove(f, pp);
		}
		printf("\nLista apagada!");
	}
	printf("\n\n\n");
};

void organizarMaiorMenor(node **ptrAux){ // ordena lista do maior para o menor
	system("cls");
	node *p, *p2;
	p = *ptrAux;
	if(p==NULL){
		printf("Lista vazia!");
	}else{
		if(p->next==NULL){
			printf("A lista tem apenas 1 elemento!");
		}else{
			p2 = p->next;
			//printf("p2->data: %d\np2->next: %d\n", p2->data, p2->next);
			if(p->data>p2->data){
				printf("Entrei no if que precisava\n");
				p->next = p2->next;
				p2->next = p;
				p->next = p3;
			}else{
				printf("A lista ja esta organizada.\n");
			}
		}
	}
	printf("\n\n\n");
};
void organizarMenorMaior();

int header(int x){ // Cabeçalho que mostra ao usuário o que ele pode fazer
	printf("Digite a operacao desejada.\n");
	printf("1 - Adicionar numeros manualmente.\n");
	printf("2 - Remover primeiro numero.\n");
	printf("3 - Mostrar lista.\n");
	printf("4 - Adicionar N numeros automaticamente.\n");
	printf("5 - Apaga lista.\n");
	printf("6 - Organiza prioridade maior para menor.\n");
	printf("7 - Organiza prioridade menor para maior.\n");
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
				break;
			case 2:
				ptr = front;
				remove(&front, ptr);
				break;
			case 3:
				ptr = front;
				display(ptr, rear);
				break;
			case 4:
				rearAleatorio(n, &front, &rear);
				break;
			case 5:
				destroy(&front, ptr);
				break;
			case 6:
				ptr = front; // Continuar daqui
				organizarMaiorMenor(&ptr);
				break;
			case 7:
				break;
			case 0:
				break;
		}
	}
	system("cls");
	printf("\n\nFechando programa.\nPrograma desenvolvido por Raythan Padovani Abreu Machado.\nObrigado por utilizar este software.\n\n\n");
	
	return 0;
}
