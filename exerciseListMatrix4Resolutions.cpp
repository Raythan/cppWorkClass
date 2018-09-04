Você pode compilar esse código no Dev c++
Só não está adequadamente adentado!

----------------------- INICIO DO CÓDIGO -------------------------------- 
#include <stdlib.h>
#include <stdio.h>


int main(){
	int decision = 0;
	printf("Informe qual algoritmo quer executar:\n");
	printf("1. Imprimir a matriz pelas diagonais secundarias.\n");
	printf("2. Impressao de matriz em ampulheta por linha.\n");
	printf("3. Impressao de matriz em ampulheta por coluna.\n");
	printf("4. Impressao de matriz em espiral.\n");
	scanf("%d", &decision);
	while(decision>0&&decision<=5){
		switch(decision){
			case 1:
				/******************************************************************************
				Inciso 6: Apostila de Matrizes
				
				Dada uma matriz de NxN, cujos elementos são números inteiros.
				Construa um programa que imprima os valores das 
				diagonais secundárias da matriz como no exemplo
				
				*******************************************************************************/
			{
				system("cls");
				printf("1. Imprimir a matriz pelas diagonais secundarias.\n");
				int n, // Tamanho da matriz
				i=0, // Contador de linhas
				j=0, // Contador de colunas 
				p=0, // Contador de parada
				c=0; // Decrementador de i
				
				printf("Digite o tamanho da matriz NxN: ");
				scanf("%d", &n);
				// Declara o tamanho da matriz NxN
				float mat[n][n]; // Matriz
				// Percorre a matriz guardando os valores
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("Informe o valor da matriz[%d][%d]: ", i, j);
						scanf("%f", &mat[i][j]);
					}
				}
				system("cls");
				for(i=0;i<n;i++){
					printf("|");
					for(j=0;j<n;j++){
						printf(" %.0f |", mat[i][j]);
					}
					printf("\n");
				}
				printf("\n\n");
				// Percorre a matriz imprimindo até a diagonal secundária
				for(i=0;i<n;i++){
					printf("|");
					for(j=0,p=j,c=i;j<=i;j++,c--,p++){
						printf(" %.0f |", mat[c][p]);
					}
					printf("\n");
				}
				i--; // Decrementa i em 1 pois o for anterior faz com ele termine com um valor maior do que a matriz
				// Percorre a matriz com o índice de ultima linha travado, variando as colunas.
				for(j=1;j<=i;j++){
					printf("|");
					for(c=i,p=j;p<=i;c--,p++){
						printf(" %.0f |", mat[c][p]);
					}
					printf("\n");
				}
			}
			break;
			
			case 2:
				/************************************************************************************
				Os elementos número 1 de uma matriz de NxN como mostrado no exemplo, por linha. 
				1 1 1 1 1
				0 1 1 1 0
				0 0 1 0 0
				0 1 1 1 0
				1 1 1 1 1
				************************************************************************************/
			{
				system("cls");
				printf("2. Impressao de matriz em ampulheta por linha.\n");
				int n, // Tamanho da matriz
				i=0, // Contador de linhas
				j=0, // Contador de colunas 
				p=0, // Apontador booleano, quando a execucao terminar corretamente, muda o valor de p para 1 e sai do laço
				aux=0, // Contador para a segunda parte da impressão da matriz
				checkTrue=0, // Marcador condicional do laço de impressão e gravação da matriz.
				count=1; // Operador para gerar matriz automaticamente
				// Declara o tamanho da matriz NxN
				printf("Digite o tamanho da matriz NxN: ");
				scanf("%d", &n);
				// Laço que fica executando até o usuário informar um valor ímpar
				while(p==0){
					// Confirma se a matriz é impar e tem um operador booleano para executar o laço até que finalize corretamente
					while(n%2!=0&&checkTrue==0){
						float mat[n][n]; // Matriz
						// Percorre a matriz guardando os valores manualmente
						/*for(i=0;i<n;i++){
						for(j=0;j<n;j++){
						printf("Informe o valor em [%d][%d]: ", i, j);
						scanf("%f", &mat[i][j]);
						}
						} */
						
						// Gerador de matriz ordenada automaticamente ate 9 por linha: conta 1, 2, 3, 4, 5, 6, 7, 8, 9 e volta para 1
						for(i=0;i<n;i++){
							printf("|");
							for(j=0;j<n;j++){
								mat[i][j] = count;
								if(count>=9){
									count = 0;
								}
								printf(" %.2f |", mat[i][j]);
								count++;
							}
							printf("\n");
						}
						printf("\n\n");
						// Impressão da matriz até a metade, percorrendo linha por linha
						for(i=0;i<=(n/2);i++){
							printf("|");
							for(j=i;j<n-i;j++){
								printf(" %.2f |", mat[i][j]);
							}
							printf("\n");
						}
						aux=i; // Contador auxiliar para não alterar i
						// Impressão da matriz da metade para baixo, percorrendo linha por linha
						for(;i<n;i++){
							printf("|");
							for(j=aux-2;j<=i;j++){
								printf(" %.2f |", mat[i][j]);
							}
							printf("\n");
							aux--;
						}
						p=1; // Verificador da condição laço
						checkTrue=1; // Verificador da condição do laço
					}
					// Condicional que pede outro valor se o usuário digitar um valor par para a matriz
					if(n%2==0){
						system("cls");
						printf("Voce precisa digitar um valor impar para a matriz: ");
						scanf("%d", &n);
					}
				}
			}
			break;
			case 3:
			/*************************************************************************************
			Os elementos número 1 de uma matriz de NxN como mostrado no exemplo, por coluna. 
			1 1 1 1 1
			0 1 1 1 0
			0 0 1 0 0
			0 1 1 1 0
			1 1 1 1 1
			*************************************************************************************/
			{
				system("cls");
				printf("3. Impressao de matriz em ampulheta por coluna.\n");
				int n, // Tamanho da matriz
				i=0, // Contador de linhas
				j=0, // Contador de colunas 
				p=0, // Apontador booleano, quando a execucao terminar corretamente, muda o valor de p para 1 e sai do laço
				aux=1, // Contador para a segunda parte da impressão da matriz
				checkTrue=0, // Marcador condicional do laço de impressão e gravação da matriz.
				count=1, // Operador para gerar matriz automaticamente e auxiliar na impressão por colunas
				count2=count; // Operador para auxiliar na impressão por coluna
				// Declara o tamanho da matriz NxN
				printf("Digite o tamanho da matriz NxN: ");
				scanf("%d", &n);
				// Laço que fica executando até o usuário informar um valor ímpar
				while(p==0){
					// Confirma se a matriz é impar e tem um operador booleano para executar o laço até que finalize corretamente
					while(n%2!=0&&checkTrue==0){
						float mat[n][n]; // Matriz
						// Percorre a matriz guardando os valores manualmente
						/*for(i=0;i<n;i++){
						for(j=0;j<n;j++){
						printf("Informe o valor em [%d][%d]: ", i, j);
						scanf("%f", &mat[i][j]);
						}
						} */
						
						// Gerador de matriz ordenada automaticamente ate 9 por linha: conta 1, 2, 3, 4, 5, 6, 7, 8, 9 e volta para 1
						for(i=0;i<n;i++){
							printf("|");
							for(j=0;j<n;j++){
								mat[i][j] = count;
								if(count>=9){
									count = 0;
								}
								printf(" %.2f |", mat[i][j]);
								count++;
							}
							printf("\n");
						}
						printf("\n\n");
						// Laço que imprime por coluna até a metade da matriz por coluna
						for(j=0;j<(n/2+1);j++){
							printf("|");
							for(i=0,count=0;count<aux&&aux<=(n/2+1);i++,count++){
								printf(" %.2f |", mat[i][j]);
							}
							for(i=n,count2=0;count2<count;count2++,i++){
								if(i-count==j){
								}else{
									printf(" %.2f |", mat[i-count][j]);
								}
							}
							aux++;
							printf("\n");
						}
						count--;
						aux--;
						// Laço que imprime a segunda metade da matriz por coluna
						for(;j<n;j++){
							printf("|");
							for(i=0,count=aux;aux>0&&count>1;count--,i++){
								printf(" %.2f |", mat[i][j]);
							}
							for(i=n+1,count2=aux;aux>0&&count2>1;count2--){
								printf(" %.2f |", mat[i-count2][j]);
							}
							printf("\n");
							aux--;
						}
						
						p=1; // Verificador da condição laço
						checkTrue=1; // Verificador da condição do laço
					}
					// Condicional que pede outro valor se o usuário digitar um valor par para a matriz
					if(n%2==0){
						system("cls");
						printf("Voce precisa digitar um valor impar para a matriz: ");
						scanf("%d", &n);
					}
				}
			}
			break;
			case 4:
			/********************************************************************************
			os elementos da diagonal principal de uma matriz de NxM segundo o diagrama
			do exemplo a seguir, começando pelo elemento da primeira linha, 
			primeira coluna e seguindo o sentido das flechas: "FORMATO CARACOL"
			
			********************************************************************************/
			{
				int n, // Número de linhas da matriz
				m, //Número de colunas da matriz
				i, // índice de linhas
				j, // índice de colunas
				decision = 1, // Condicionador de parada depois de correr o vetor
				count=1, // Contador para gerar matriz automaticamente
				aux1=0, // Auxiliar para marcar linha
				aux2=0; // Auxiliar para marcar coluna
				system("cls");
				printf("4. Impressao de matriz em espiral.\n");
				printf("Digite a quantidade de linhas: ");
				scanf("%d", &n);
				printf("Digite a quantidade de colunas: ");
				scanf("%d", &m);
				// Declaração da matriz
				float mat[n][m];
				// Laço aninhado que grava os valores da matriz
				/*for(i=0;i<n;i++){
				for(j=0;j<m;j++){
				printf("Digite o valor em [%d][%d]: ", i, j);
				scanf("%f", &mat[i][j]);
				}
				} */
				// Gerador de matriz ordenada automaticamente ate 9 por linha: conta 1, 2, 3, 4, 5, 6, 7, 8, 9 e volta para 1
				for(i=0;i<n;i++){
					printf("|");
					for(j=0;j<m;j++){
						mat[i][j] = count;
						if(count>=9){
							count = 0;
						}
						printf(" %.2f |", mat[i][j]);
						count++;
					}
					printf("\n");
				}
				printf("\n\n|");
				// Laço que imprime a matriz em forma de caracol
				for(;decision<=n+m;decision++){ // Não consegui pensar num método de parada eficiente, talvez possamos discutir este ponto
					for(i=aux1,j=aux2;j<m-aux2;j++){ // Imprime a primeira linha da esquerda para direita, e depois dos outros laços vai imprimindo N+1 até chegar ao centro
						printf(" %.2f |", mat[i][j]);
					}
					//printf("\ni: %d, j: %d, aux1: %d, aux2: %d\n\n", i, j, aux1, aux2);
					i++;
					for(;i<n-aux2;i++){ // Imprime a última coluna de cima para baixo, e depois dos laços vai imprimindo M-1 até chegar ao centro
						printf(" %.2f |", mat[i][j-1]);
					}
					j--;
					//printf("\ni: %d, j: %d, aux1: %d, aux2: %d\n\n", i, j, aux1, aux2);
					for(j--;j>=aux2;j--){ // Imprime a última linha da direita para esquerda e depois dos laços vai imprimindo N-1 até chegar ao centro
						printf(" %.2f |", mat[i-1][j]);
					}
					//printf("\ni: %d, j: %d, aux1: %d, aux2: %d\n\n", i, j, aux1, aux2);
					i-=2;
					j++;
					for(;i>aux2;i--){ // Imprime a primeira coluna de baixo para cima e depois dos outros laços vai imprimindo M+1 até chegar ao centro
						printf(" %.2f |", mat[i][j]);
					}
					//printf("\ni: %d, j: %d, aux1: %d, aux2: %d\n\n", i, j, aux1, aux2);
					aux1++;
					aux2++;
				}
			}
			break;
			case 5:
				printf("Digito invalido.\n");
			break;
		}
		printf("\n\nSe quiser pode executar novamente: \n");
		printf("1. Imprimir a matriz pelas diagonais secundarias.\n");
		printf("2. Impressao de matriz em ampulheta.\n");
		printf("3. Impressao de matriz em ampulheta por coluna.\n");
		printf("4. Impressao de matriz em espiral.\n");
		printf("0. Sair.\n");
		scanf("%d", &decision);
		system("cls");
		if(decision!=0&&decision!=1&&decision!=2&&decision!=3&&decision!=4&&decision!=5){
			decision = 5;
		}
	}
	return 0;
}
