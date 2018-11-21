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

void insertMaiorMenor(node **p, int a){ // Do menor para o maior
	// Variáveis
    node *ptr2, *ptr, *ptr3;
    ptr = (node *) malloc(sizeof(node));
    
    // Métodos
    ptr2 = *p;
    ptr3 = NULL;
    ptr->data = a;
		
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
	printf("Adicionei %d a lista\n\n\n", a);
}

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


void remove2(node **c, node *p){  // Remover elementos
	p = *c;
	*c = p->next;
	free(p);
};

void display(node *ptr, node *rear){ // Imprime a lista
	system("cls");
	if(ptr!=NULL){
		printf("Primeiro -> ");
		while(ptr!=NULL){
				printf("| %d | ", ptr->data);
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
			aux = numeroAleatorio(0, 10);
			insertMaiorMenor(front, aux);
		}
		system("cls");
		printf("%d numero adicionado a lista.", n);	
	}else if(n>0){
		for(i=0;i<n;i++){
			aux = numeroAleatorio(0, 10);
			insertMaiorMenor(front, aux);
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
			remove2(f, pp);
		}
		printf("Lista apagada!");
	}
	printf("\n\n\n");
};

int header(int x){ // Cabeçalho que mostra ao usuário o que ele pode fazer
	printf("Digite a operacao desejada.\n");
	printf("1 - Adicionar numeros manualmente.\n");
	printf("2 - Remover primeiro numero.\n");
	printf("3 - Mostrar lista.\n");
	printf("4 - Adicionar N numeros automaticamente.\n");
	printf("5 - Apaga lista.\n");
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
				insertMaiorMenor(&front, n);
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
			case 0:
				break;
		}
	}
	system("cls");
	printf("\nFechando programa.\nPrograma desenvolvido por Raythan Padovani Abreu Machado.\nObrigado por utilizar este software.\n\n\n");
	return 0;
}
