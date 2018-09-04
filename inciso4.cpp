// 4. Ler um número inteiro e testar se esse número é um palíndromo. Dica: usar o exercício anterior.
// Para ler uma string usar: scanf(“ %[^ ]”, s) onde s foi declarado como, por exemplo, char s[24].
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
int main() {
	char s[100]; // String que vai ser avaliada
	int i, //Contador primario que vai contar a string até o fim
	check = false, // Variável se checa verdadeiro ou falso palindromo
	c = 2; // Contador secundário que vai comparar se o fim e o começo são iguais
	printf('Digite uma palavra para verificarmos se e um palindromo: ');
	scanf(' %s', &s);
	for(;c%2==0;c=c){
		for(c=0;s[c]!='';c++){
		}
		if(c%2!=0){
			c--;
			for(i=0;i!=c;i++){
				if(s[i]==s[c]){
					check = true;
				}else{
					check = false;
					break;
				}
				c--;
			}
			if(check){
				printf('Palindromo.');
				break;
			}else{
				printf('Nao palindromo.');
				break;
			}
		}else{
			system('cls');
			printf('Voce precisa digitar um numero de caracteres impares para saber se e um palindromo Digite novamente! ');
			scanf(' %s', &s);
		}
	}
	return 0;
}

