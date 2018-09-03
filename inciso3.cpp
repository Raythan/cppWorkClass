/* 3. Um vetor que tem armazenado em cada componente um digito de 0 a 9 pode ser considerado
como um número inteiro positivo, portanto faz sentido determinar se esse número armazenado no
vetor é ou não um palíndromo. Faça um programa que leia um vetor desse tipo e imprima uma
mensagem caso o vetor armazenado seja ou não seja um palíndromo.
Exemplo se o vetor tem armazenados os dígitos 2 3 9 5 9 3 2, deve ser informado que esse vetor tem
armazenado um palíndromo. */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

int main() { 
	int c = 0, // contador secundario
	i, // contador inicial
	check, // check para saber se é um palindromo ou nao
	n = 2, // quantidade de numeros a serem contados
	vetor[100][100]; // vetor utilizado nas iterações
	while(n%2==0 && n>0){
		printf(" Informe a quantidade de numeros NATURAIS IMPARES a serem armazenados para checarmos se e um palindromo (NO MAXIMO 100): ");
		scanf("%d", &n);
		if(n%2!=0 && n>0){
			system("cls");
			for(i=0;i<n;i++){
				printf("Digite o numero inteiro que vai ser armazenado em: Vetor[i: %d]: ", i);
				scanf("%d", &vetor[0][i]);
			}
			i--;
			while(c!=i){
				if(vetor[0][c] == vetor[0][i]){
					check = true;
				}else{
					c=i;
					check = false;
					break;
				}
				c++;
				i--;
			}
			if(check){
				system("cls");
				printf(" O Vetor[]: ");
				for(i=0;i<n;i++){
					printf("%d, ", vetor[0][i]);
				}
				printf("e um palindromo.");
			}else{
				system("cls");
				printf(" O vetor nao e um palindromo.");
			}
		}else{
			system("cls");
			printf("****************************************************** ");
			printf("*O numero deve ser NATURAL e IMPAR, TENTE NOVAMENTE!** ");
			printf("****************************************************** ");
		}
	}
return 0;
}
