#include <stdio.h>
#include <stdlib.h>

typedef struct node{ // Struct para ser usada como lista...
	int data;
	struct node *next;	
};

void prioridade(node **p, int a){ // Do menor para o maior
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


void imprime(node *ptr, node *rear){ // Imprime a lista
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


int main(){
	//Variáveis
	int n = 1, // Quantidade de números para serem adicionados e 
	d = 1;  // Decisao do switch
	node *front, // cabeça
	*rear, // fim da lista
	*ptr; // percorre a lista
	
	// Implementação
	rear = front = NULL;
	while(d!=0){
		printf("Adiciona numeros enquanto nao for 0.\nQue numero gostaria de adicionar?\n");
		scanf("%d", &n);
		prioridade(&front, n);
		ptr = front;
		imprime(ptr, rear);
		d = n;
	}
	return 0;
}
