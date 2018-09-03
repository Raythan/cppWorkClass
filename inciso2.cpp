/* 2. Ler 10 valores inteiros positivos. Armazenar esses elementos num vetor e fazer um histograma que
represente os valores armazenados.
Exemplo:
Elemento/indice Valor Histograma
0 19 *******************
1 3 ***
2 15 ***************
3 7 *******
4 11 ***********
5 9 *********
6 13 *************
7 5 *****
8 17 *****************
9 1 */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

int main() {
	int i,
	c,
	vetor[9];
	for(i=0;i<4;i++){
		printf("Digite o valor para ser armazenado em Vetor[i: %d]: ", i);
		scanf("%d", &vetor[i]);
	}
	printf(" ");
	for(i=0;i<4;i++){
		printf("Vetor[i: %d]: %d --> ", i, vetor[i]);
		for(c=0;c<vetor[i];c++){
			printf("*");
		}
		printf(" ");
	}
return 0;
