#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
	ifstream inFile;
	string str;
	string fileContent;
	string arrayTeste[5] = {"teste", "texto"};
	
	inFile.open("C:\\Users\\raythan.machado\\Desktop\\new.txt");
	
	if (!inFile) {
		cout << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	
//	while (inFile >> x) {
//		sum = sum + x;
//	}

	while (getline(inFile, str))
	{
		//for (string teste : arrayTeste){
		for(int i = 0; i < 5; i++){
			if(arrayTeste[i] == str){
				cout << "Achei!\n";
			}
		}
		fileContent += str;
		fileContent.push_back('\n');
	}  
	
	inFile.close();

	cout << fileContent;
//    string STRING;
//	ifstream infile;
//	
//	infile.open ("new.txt");
//        while(!infile.eof) // To get you all the lines.
//        {
//	        getline(infile,STRING); // Saves the line in STRING.
//	        cout<<STRING; // Prints our STRING.
//        }
//	infile.close();
//	system ("pause");
	
	return 0;
}


