
/*
struct student
{
  int num;
  float dec;
  char vet[20];
} variavel, variavel2;

struct student variavel;
struct student array[];

variavel.num = 0;
array[i].num = 0;
variavel = {0, 2.4, "nome"};
-----------------------------------------------------------------
typedef struct student
{	
  int num;
  float dec;
  char vet[20];
}
typedef struct nomeDaSctruct equivalência;
student variavel;

quando estiver trabalhando com ponteiro o acesso aos elementos não é feito por . mas por ->


--------------------------------
struct student, *prt_stud
{	
  int num;
  float dec;
  char vet[20];
}
>>>> ptr_stud = &student; // adiciona o endereço de memória da sctruct student
(*ptr_stud).num = 40; // Atribui o valor 40 a num na struct student
ptr_stud->num = 40; // Atribui o valor 40 a num na struct student

LISTA ENLAÇADA -------------------------
	struct node
	{
		int data;
		struct node *next;
	}
	struct node *start; // >>>> nesse momento = NULL;
	struct node *ptr; // >>>> ponteiro que vai percorrer a lista
	ptr = start;
	while(ptr != NULL)
	{
		printf("\t %d", ptr -> data);
		ptr = ptr -> next;
	}

*/

#include <stdlib.h>
#include <stdio.h>

typedef struct iniTable
{
	char nomeComprador[100];
	int qtdProdutos;
	float valorProdutos;
};

 

void printVector(int n, int vet[]){
	int i = 0;
	printf("\n +--------------------+\n| This is your vector! |\n +--------------------+\n ");
	for(i=0;i<n;i++){
		printf("-------");
	}
	printf("\n|");
	for(i=0;i<n;i++){
		printf(" [ %d ] ", vet[i]);
	}
	printf("|\n ");
	for(i=0;i<n;i++){
		printf("-------");
	}
	printf("\n");
}

void readVector(int nIns, int vetIns[]){
	int i;
	for(i=0;i<nIns;i++){
		printf("Element on I[%d]: ", i);
		scanf("%d", &vetIns[i]);
	}
}

void iniOptionsPrint(){
	printf("Please info what you want to do.\n");
	char option1[] = ("1 - Increase elements on N position of a N size vector.\n"), // Operation for input elements
	option2[] = ("2 - Decrease elements of N position of a N size vector.\n"), // Operation for remove elements
	option3[] = ("3 - Get the result of 2 ordenated arrays.\n"),
	option4[] = ("4 - Multiply matrix. >>>>>>>>> On Going <<<<<<<<<\n"),
	option5[] = ("5 - Make a product list! >>>>>>>>> On Going <<<<<<<<<\n"),
	optionFinal[] = ("0 or 6+ - For exit!\n"); // Query for exit script
	printf(option1);
	printf(option2);
	printf(option3);
	printf(option4);
	printf(option5);
	printf(optionFinal);
}

int main() {
	//Add or remove numbers inside an array of integer
	int decision = 0, // Decision for loop the architecture while the user wants
	decision2 = 0, // Decision for avoid invalid input on insert elements on array
	newVet = 0, // Variable used for markup in the first printable text
	n = 0, // Size of the array
	n2 = 0, // Size of the first array in mix arrays
	n3 = 0, // Size of the second array in mix arrays
	n4 = 0, // Size of the third array in mix arrays
	i, // Counter; index of third array in mix arrays
	i2, // index of first array in mix arrays
	i3, // index of second array in mix arrays
	d, // Variable used for markup
	add, // Variable used for add the number, and next used for add the next number in the array
	aux, // Variable for keep the value of the next position on array.
	vet[n], // Array used on the 2 first problems.
	vet2[n2],// Array used for solve mix 2 arrays
	vet3[n3], // Array used for solve mix 2 arrays
	vet4[n4], // Array used for solve mix 2 arrays
	ind, // Decision that you choise for solve what index you want to add.
	ind2 = 0; // Decision that you choise for solve what index you want to remove.
	char autor[] = ("\n\nClosing software down!\nThis software have been produced and distribuited for\nRaythan Padovani Abreu Machado.\nWe really appreciate the preference.");
	typedef struct iniTable table[n];
	{ 
		while(decision==0){
			int decision3 = 3; // Decision for avoid invalid input on rollback and decision
			char rollback[] = ("Do you want to exit?\n(1) - Yes.\n(2) - No."), // Finalização do software
			optionVector[] = ("Do you want to use the same vector?\n(1) - Yes.\n(2) - No."); // Query for use the same vector
			system("cls");
			if(newVet==0){
				printf("This software make some operations.\n");
			}
			iniOptionsPrint();
			scanf("%d", &d);
			system("cls");
			{
				if((newVet==0 && d==1) || (newVet==0 && d==2)){ // Vector building
					while(n==0){
						//void lerVetor(int n, int i, int vet[]);
						printf("Plase info the vector size: \n");
						scanf("%d", &n);
						system("cls");
						for(i=0&&n!=0;i<n;i++){
							printf("\nInput the value on index[%d]: ", (i+1));
							scanf("%d", &vet[i]);
						}
					}
				}
				system("cls");
				
				if(d==1){
					printVector(n, vet);
					while(decision2!=n){ // loop for avoid mistake
						// Inserting elements where pointed by user
						printf("\nPlease info where did you want to add a number? 1 - %d\n", (n + 1));
						scanf("%d", &ind); 
						decision2 = ind; // Increased rule 15-08
						if(decision2 > (n+1) || decision2 == 0){
							printf("\nPlease input a valid number!!\n");
							scanf("%d", &ind); 
							decision2 = ind; // Increased rule 15-08
							if(decision2 > (n+1) || decision2 == 0){
								system("cls");
							}
						}else if(decision2 <= (n+1)){
							decision2 = n;
						}
					}
					printf("Please info what number do you want to add:\n");
					scanf("%d", &add);
					ind--;
					n++;
					for(i=ind;i<n;i++){
						aux = vet[i]; vet[i] = add; add = aux;
					}
					system("cls");
					
					printVector(n, vet);
				
					while(decision3>2){ // loop for avoid mistake // Loop for avoid mistake
						printf("\n\n%s\n", rollback); //Decision for continue or not
						scanf("%d", &decision);
						if(decision==2){
							decision = 0;
							printf("\n%s\n", optionVector);
							scanf("%d", &newVet);
							decision3 = 1;
							if(newVet==2){
								newVet = 0; n = 0;
							}
						}else{
							printf(autor);
							decision = 1;
							decision3 = 1;
						}
					}
				}else if(d==2&&n>1){
					printVector(n, vet);
					while(ind2<1||ind2>n){
						printf("\nPlease info where did you want to remove a number? 1 - %d\n", n);
						scanf("%d", &ind2);
					}
					ind2--;
					for(i=ind2;i<(n-1);i++){
						vet[i] = vet[(i+1)];
					}
					n--;
					system("cls");
					
					printVector(n = 2, vet); // Print Vector
					
					printf("\n\n%s\n", rollback); //Decision for continue or not
					scanf("%d", &decision);
					if(decision==2){
						decision = 0;
						printf("\n%s\n", optionVector);
						scanf("%d", &newVet);
					if(newVet==2){
						newVet = 0; n = 0;
					}
					}else{
						printf(autor);
						decision = 1;
					}
				}else if(d==2&&n<2){
					printVector(n, vet);
					printf("\n\n------This vector is too small for delete elements.------\n");
					printf("\n\n%s\n", rollback); //Decision for continue or not
					scanf("%d", &decision);
					if(decision==2){
						decision = 0;
						printf("\n%s\n", optionVector);
						scanf("%d", &newVet);
					if(newVet==2){
						newVet = 0; n = 0;
					}
					}else{
						printf(autor);
						decision = 1;
					}
				}else if(d==3){
					printf("\nInfo the vector size: \n"); 
					scanf("%d", &n2);
					readVector(n2, vet2);
					system("cls");
					printf("\nInfo the vector2 size: \n");
					scanf("%d", &n3);
					readVector(n3, vet3); // Reading the two vectors sizes and pushing in
					system("cls");
					printVector(n2, vet2);
					printVector(n3, vet3); // Printing the two vectors for UI  
					n4 = n2 + n3; i = 0; i2 = 0; i3 = 0;
					printf("\n\n");
					
					while(i<n4){
						if(vet2[i2]!=NULL&&i2<n2){
							printf("vet2[i2:%d]: %d\n", i2, vet2[i2]);
							vet4[i] = vet2[i2];
							i2++; i++;
						}
						if(vet3[i3]!=NULL&&i3<n3){
							printf("vet3[i3:%d]: %d\n", i3, vet3[i3]);
							vet4[i] = vet3[i3];
							i3++; i++;
						} // These two conditions verify if the matrix finish length, IF Yes stop input numbers
					} // Work correctly =)
					printf("\nVector3: ");
					printVector(n4, vet4);
					printf("\n");
					system("pause"); 
				}
				else{
					system("cls");
					printf(autor);
					decision = 1;
				}
			}
		}
	}
	return 0;
}
