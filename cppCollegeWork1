#include <stdlib.h>
#include <stdio.h>

int main() {
  int i = 0, // Contador
  c, // Contador para checar se os números estão no array
  n, // Quantidade de números que vão ser lidos, informados pelo usuário.
  checkNum, // Número que vai ser verificado se está presente, e em que posição está presente no VETOR
  soma, // soma dos números positivos encontrados no vetor
  p = 0, // Indice que vai ser alterado no vetor
  m, // Numero que vai ser inserido no índice indicado pelo usuário
  vetor[100][100]; // Vetor que vai armazenar os valores dos números inteiros.

  // Inciso "1. Ler N números inteiros e armazenar esses números em um vetor."
  printf("Informe quantos numeros serao lidos (No MAXIMO 100): "); // Informações para iniciar a quantidade de números que vão ser armazenados no vetor
  scanf("%d", &n);
  printf(" ");
  // "For" que vai armazenar os valores no vetor.
  for(;i<n;i++){
    printf("Digite um numero para ser armazenado em Vetor[i: %d]: ", i);
    scanf("%d", &vetor[0][i]);
  }
  printf("********** FIM DO INCISO 1 ********** ");
  // Inciso "a. Imprimir os números armazenados no vetor."
  for(i=0;i<n;i++){
  	printf("O valor armazenado em Vetor[i: %d] e de: %d ", i, vetor[0][i]);
  }
  	printf("********** FIM DO INCISO A ********** ");
  //Inciso "b. Imprimir os números armazenados nas posições pares."
  for(i=0;i<n;i+=2){
  	printf("O valor armazenado nos indices pares do Vetor[i: %d] e de: %d ", i, vetor[0][i]);
  }
  printf("********** FIM DO INCISO B ********** ");
  //Inciso "c. Imprimir os números pares armazenados no vetor."
  for(i=0;i<n;i++){
	  if(vetor[0][i] % 2 == 0){
	  	printf("O numero no Vetor[i: %d]: %d e PAR ", i, vetor[0][i]);
	  }
  }
  printf("********** FIM DO INCISO C ********** ");
  // Inciso "d. Ler um número e imprimir se o número está ou não armazenado no vetor."
  printf("Insira um numero para consultar se esta presente no vetor: ");
  scanf("%d", &checkNum);
  printf(" ");
  for(i=0,c=0;i<n;i++){
	  if(vetor[0][i] == checkNum){
		  printf("Este numero esta presente no vetor. ");
		  i = n;
		  c++;
	  }
	  if(vetor[0][i] == sizeof(vetor[0][i]) && c == 0){
	  	printf("O numero nao esta presente no Vetor. ");
	  }
  }
  printf("********** FIM DO INCISO D ********** ");
  // Inciso "e. Ler um número. Se o número está armazenado no vetor, imprimir as posições onde
  // foi achado (pode ter mais de uma ocorrência do número)."
  for(i=0,c=0;i<n;i++){
	  if(vetor[0][i] == checkNum){
		  printf("O numero esta no Vetor[i: %d] ", i);
		  c++;
	  }
		  if(vetor[0][i] == sizeof(vetor[0][i]) && c == 0){
		  printf("O numero nao esta presente no Vetor. ");
	  }
  }
  printf("********** FIM DO INCISO E ********** ");
  // Inciso "f. Somar todos os números positivos armazenados nos vetores."
  for(i=0;i<n;i++){
	  if(vetor[0][i] > 0){
	  	soma+=vetor[0][i];
	  }
  }
  printf("A soma dos numeros positivos do vetor e de: %d ", soma);
  printf("********** FIM DO INCISO F ********** ");

  /* Inciso "g. Ler um número inteiro p e um número n. 
  Armazenar o número n na componente p do vetor. 
  Imprimir o vetor original e o modificado. 
  Considerar erros no valor de p." */

  printf("Agora informe uma posicao que voce queira alterar no vetor: ");
  scanf("%d", &p); printf(" ");
  printf("Agora informe o numero que voce quer inserir nessa posicao: ");
  scanf("%d", &m); printf(" ");
  vetor[1][p] = m;
  if(p <= sizeof(vetor[0][i])){
	  for(i=0;i<n;i++){
	  	printf("O valor no Vetor[i: %d] = %d ", i, vetor[0][i]);
	  }
	  printf(" ");
	  for(p=0;p<n;p++){
	  	printf("O valor no Vetor[i: %d] = %d ", p, vetor[1][p]);
	  }
  }else{
  	printf("Voce digitou um numero de indice que nao esta no vetor!!! ");
  }
  printf("********** FIM DO INCISO G ********** ");

  /*h. Criar um novo vetor que tem armazenado o valor absoluto dos valores armazenados no vetor. Imprimir os dois vetores."
  Assim, por exemplo, se o vetor tem armazenados os valores "-56 7.3 9 -45 -3.78 0 6"
  O novo vetor terá armazenados os valores "56 7.3 9 45 3.78 0 6""*/

  for(i=0;i<n;i++){
	  if(vetor[0][i] < 0){
	  	vetor[2][i] = -1 * (vetor[0][i]);
	  }else{
	 	vetor[2][i] = vetor[0][i];
	  }
	  printf("Vetor[i: %d]: (%d) <-- Valor absoluto ", i, vetor[2][i]);
  }
  printf("********** FIM DO INCISO H ********** ");

  /* i. Criar um novo vetor que tem armazenado os números negativos armazenados no
  vetor. Imprimir os dois vetores.
  Assim, por exemplo, com o vetor do inciso anterior, o novo terá armazenados os
  valores: -56 -45 -3.78
  Observar que o novo vetor não necessariamente tem a mesma quantidade de elementos!!!! */

  for(i=0,c=0;i<n;i++){
	if(vetor[0][i] < 0){
	  vetor[2][i] = vetor[0][i];
	  printf("Elementos negativos no Vetor[i: %d]: %d ", c, vetor[2][i]);
	  c++;
	}
  }
  if(c == 0){
  	printf("Nao existem numeros negativos para realizar o inciso I!!! ");
  }
  printf("********** FIM DO INCISO I ********** ");

  return 0;
}
