#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
#define cantidad 1000

main(){
	FILE *archivo;
	int num_aleat;
	
	//inicializa el generador de numeros pseudoaleatorios
	srand((unsigned)time(NULL));
	
	archivo = fopen("c:/borrame/datos1000.txt", "w");
	if (archivo == NULL)	{
		cout << "\n Error! El archivo no se pudo abrir." << endl;
		system("pause");
		return 0;
	}
	for(int i = 1 ;i <= cantidad;i++){
		num_aleat = rand() % 1000; //Genera número pseudoaleatorio
        fprintf(archivo, "%d\n",num_aleat);		
	}
	fclose(archivo);
}
