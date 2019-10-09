#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

void ImprimeUmArquivo(string paramPathLocation, string paramWrite){
	ofstream outFile("aprovados_e_reprovados.txt");
	outFile << paramWrite;
	outFile.close();
}

void ImprimeDoisArquivos(string paramPathLocation, string paramWrite1, string paramWrite2){
	ofstream outFileOk("aprovados.txt"), outFileNotOk("reprovados.txt");
	outFileOk << paramWrite1;
	outFileNotOk << paramWrite2;
	outFileOk.close();
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

int main(){
	ifstream inFile;
	string strParameter, fileContentOk, fileContentNotOk, pathLocation, pathDestinationOk, pathDestinationNotOk, strAux;
	string arrayTeste[5] = {"teste", "texto"};
	bool isDivideArquivo, isPalavraValida, isOpcao1Selecionada, isOpcao2Selecionada = false;
	char auxArray[255];
	
	while(!isOpcao1Selecionada){
		cout << "Digite o caminho para o arquivo de leitura incluindo a extensao...\n";
		cout << "Obs.: Se o arquivo estiver na mesma pasta que o executavel digite o nome do arquivo mais a extensao...\n";
		gets(auxArray);
		pathLocation = auxArray;
		
		pathLocation = FormatStringPath(pathLocation);
		inFile.open(pathLocation.c_str());
		
		if (!inFile) {
			cout << "Nao consegui encontrar o arquivo [[" << pathLocation << "]] por favor digite o caminho corretamente.\n\n";
		}
		else{
			isOpcao1Selecionada = true;
		}
	}
	
	while(!isOpcao2Selecionada){
		cout << "Dividir o resultado em 2 arquivos ou apenas 1?...\n";
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
	
	while (getline(inFile, strAux))
    {
    	for(int i = 0; i < 5; i++){
        	if(strAux == arrayTeste[i]){
        		fileContentNotOk += strAux;
				fileContentNotOk.push_back('\n');	
			}
			else{
				fileContentOk += strAux;
				fileContentOk.push_back('\n');
			}
		}
    }
	
	if(isOpcao2Selecionada){
		ImprimeUmArquivo(pathLocation, fileContentOk + fileContentNotOk);
	} 
	else{
		ImprimeDoisArquivos(pathLocation, fileContentOk, fileContentNotOk);
	}

	inFile.close();

//	cout << fileContentOk << " Palavras aprovadas";
//	cout << fileContentNotOk << " Palavras reprovadas";

	return 0;
}

