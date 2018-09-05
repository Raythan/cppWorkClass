#include <stdlib.h>
#include <stdio.h>
// eliminar elemento da lista
struct node
	{
		int data;
		struct node *next;
	};
	
int main(){
	struct node *start = NULL; // nexxe momento = NULL
	struct node *ptr2; // ponteiro auxiliar
	int i = 28, num = 28; // Elemento a inserir
	struct node *ptr; // >>>> ponteiro que vai percorrer a lista
	
	node variavel;
	
	while(i != 40){
		ptr = (struct node*) malloc (sizeof(struct node));
		ptr -> data = i;
		ptr -> next = start;
		start = ptr;
		i++;
	}
	printf(">>>>>>>>>>>>>>>>>>>>>Lista enlacada!\n");
	while(ptr!=NULL)
	{			
		printf("DATA: %d\nPTR NEXT: %d\nSTART: %d\n\n", ptr -> data, ptr -> next, start);
		ptr = ptr -> next;
	}
	ptr = start;
	ptr2 = start;
	printf("LISTA ENLACADA 2\n\n");
	while(ptr!=NULL)
	{
		if(ptr2 -> data==38){
			free(ptr2);
		}
		printf("DATA: %d\nPTR NEXT: %d\n\n", ptr2 -> data, ptr2 -> next);
		ptr2 = ptr;
		ptr = ptr -> next;
	}
	
	return 0;
}
