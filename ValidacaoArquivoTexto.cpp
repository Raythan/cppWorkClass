#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

void ImprimeUmArquivo(string paramPathLocation, string paramWrite){
	ofstream outFile("aprovadas_e_reprovadas.csv");
	outFile << paramWrite;
	outFile.close();
}

void ImprimeDoisArquivos(string paramPathLocation, string paramWrite1, string paramWrite2){
	ofstream outFileOk("aprovadas.csv"), outFileNotOk("reprovadas.csv");
	outFileOk << paramWrite1;
	outFileOk.close();
	outFileNotOk << paramWrite2;
	outFileNotOk.close();
}

string FormatStringPath(string paramString){
	string returnBack;
	for(int i = 0; i < paramString.length(); i++){
		if(paramString[i] == '/'){
			returnBack += "\\\\";
		}
		else if(paramString[i] == '\\'){
			returnBack += "\\\\";
		}
		else{
			returnBack += paramString[i];	
		}
	}
	
	return returnBack;
}

string FormatStringReprovada(string paramString){
	string returnBack;
	for(int i = 0; i < paramString.length(); i++){
		if(paramString[i] == '-'){
			break;
		}
		returnBack += paramString[i];
	}
	
	return returnBack;
}

int main(){
	ifstream inFile;
	string strParameter, pathLocation, pathDestinationOk, pathDestinationNotOk, strAux, strAux2, strAux3,
		fileContentOk = "Palavras validas\n\n", fileContentNotOk = "\n\nPalavras invalidas\n\n";
	ifstream inFilePalavrasInvalidas;
	bool isDivideArquivo, isPalavraValida, isOpcao1Selecionada, isOpcao2Selecionada = false;
	char auxArray[255];
	
	// Esse laço só vai terminar quando o programa encontrar o arquivo de texto para leitura.
	while(!isOpcao1Selecionada){
		cout << "Digite o caminho para o arquivo de leitura incluindo a extensao...\n";
		cout << "Obs.: Se o arquivo estiver na mesma pasta que o executavel digite apenas o nome do arquivo mais a extensao.\n";
		gets(auxArray);
		pathLocation = auxArray;
		
		// A função FormatStringPath tem como proprósito formatar o caminho do arquivo de texto para leitura.
		pathLocation = FormatStringPath(pathLocation);
		inFile.open(pathLocation.c_str());
		
		// Limpeza da tela
		system("cls");
		
		// Verifica se o arquivo foi lido, se não foi, imprime a mensagem de erro. Se achou o arquivo sai do laço pelo else.
		if (!inFile) {
			cout << "Nao consegui encontrar o arquivo [[" << pathLocation << "]] por favor digite o caminho corretamente.\n\n";
		}
		else{
			isOpcao1Selecionada = true;
		}
	}
	
	// Esse método tenta abrir o arquivo de texto com as palavras que não são permitidas.
	// Se não encontrar o arquivo ele vai entrar no laço e obrigar o usuário a criar a lista,
	// de palavras não permitidas antes de prosseguir.
	// Obs.: não vai sair do laço até criar o arquivo exatamente como na descrição
	inFilePalavrasInvalidas.open("Palavras Invalidas.txt");
	while(!inFilePalavrasInvalidas){
		cout << "O arquivo [Palavras Invalidas.txt] nao foi localizado junto ao executavel.\n";
		cout << "Para o funcionamento do programa eh necessario o arquivo [Palavras Invalidas.txt]\n";
		cout << "Por favor crie o arquivo com as listas de palavras invalidas junto ao executavel antes de prosseguir.\n";
		cout << "Pressione Enter apos criar o arquivo para que eu saiba quais sao as palavras invalidas.\n";
		system("pause");
		inFilePalavrasInvalidas.open("Palavras Invalidas.txt");
		system("cls");
	}
	
	// Esse laço vai pedir a definição de saída para o usuário...
	// Se ele quer dois arquivos, aprovadas.txt e reprovadas.txt
	// ou se ele quer tudo junto num arquivo com nome aprovados_e_reprovados.txt
	while(!isOpcao2Selecionada){
		cout << "Dividir o resultado em 2 arquivos?\n";
		cout << "(1) - Sim. | (2) - Nao.\n";
		cin >> strParameter;
		
		if(strParameter == "1"){
			isDivideArquivo = true;
			isOpcao2Selecionada = true;
		}else if(strParameter == "2"){
			isOpcao2Selecionada = true;
		}else{
			system("cls");
			cout << "Voce selecionou uma resposta invalida, digite 1 ou 2...\n\n";	
		}
	}
	
	// Esse condicional fará alteração do cabeçalho "Palavras invalidas" antes da impressão de 2 arquivos...
	if(isDivideArquivo){
		fileContentNotOk = "Palavras invalidas\n\n";
	}
		
	// Esse laço faz a leitura linha a linha do arquivo a ser analisado...	
	while (getline(inFile, strAux))
    {
    	// Esse laço faz a comparação da palavra que está sendo analisada pelo laço anterior
    	// com cada palavra no arquivo "Palavras invalidas.txt"
		while(getline(inFilePalavrasInvalidas, strAux2)){
			
			// Variável utilizada para manter o valor da string não permitida
			strAux3 = strAux2;
			
			// Essa método auxiliar vai formatar a string não permitida para para validação no condicional seguinte...
			strAux2 = FormatStringReprovada(strAux2);
			
			// Esse condicional é uma flag para a montagem dos arquivos de saída...
			// se ele achar uma palavra igual, a concatenação de string mais a frente vai colocar a palavra
			// no arquivo de saída reprovadas.txt, se não vai colocar no aprovadas.txt
			if(strAux == strAux2){
				isPalavraValida = false;
				break;
			}
			else{
				isPalavraValida = true;
			}
		}
		// Esses dois métodos são para recomeçar a leitura do arquivo com as listas de palavras inválidas...
		inFilePalavrasInvalidas.close();
		inFilePalavrasInvalidas.open("Palavras Invalidas.txt");
		// Fim do reinicio
		
		// Esse condicional vai concatenar a palavra no arquivo reprovado ou aprovado
		// de acordo com a flag que vier do condicional anterior
		if(!isPalavraValida){
			fileContentNotOk += strAux3;
			fileContentNotOk.push_back('\n');
		}else{
			fileContentOk += strAux;
			fileContentOk.push_back('\n');
		}	
    }
    
    // Métodos para liberar o recurso que está sendo utilizado
    // Nesse caso são os arquivos .txt
	inFilePalavrasInvalidas.close();
	inFile.close();
	
	// Condicional que determina se imprime 1 ou 2 arquivos separados...
	if(!isDivideArquivo){
		ImprimeUmArquivo(pathLocation, fileContentOk + fileContentNotOk);
	} 
	else{
		ImprimeDoisArquivos(pathLocation, fileContentOk, fileContentNotOk);
	}

	return 0;
}
