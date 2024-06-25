//Genera números pseudoaleatorios
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

main(){
	int cantidadPseudo, numPseudo;
	
	//Inicializar el generador de números pseudoaleatorios
	srand
	((unsigned)time(NULL));
	
	cout<<"\n Cuantos numeros pseudoaleatorios deseas generar: ";
	cin>>cantidadPseudo;
	
	for(int i = 1; i <= cantidadPseudo; i++){
		numPseudo = rand();
		cout<<"\n Pseudoaleatorio "<< i <<": "<< numPseudo;
	}
	
}

