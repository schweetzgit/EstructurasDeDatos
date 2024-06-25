#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//Funcion genera numeros pseudoaleatorios
int generapseudoaleatorio(int n){
	return rand()%n; //reducir a un numero
}

//Funcion principal
main(){
	int totalNPseudo;
	time_t timeInicial, timeFinal, n;
	srand((unsigned)time(NULL));
	
	timeInicial = time(NULL);
	
	cout<<"\n Cuantos numeros pseudoaleatorios desea generar: ";
	cin>>totalNPseudo;
	cout<<"\n Cual es el numero pseudoaleatorio mas grande que se requiere generar: ";
	cin>>n;
	
	for(int i = 1; i <= totalNPseudo; i++){
		cout<<"\n Pseudoaleatorio "<<i<<": "<<generapseudoaleatorio(n);
	}
	
	timeFinal = time(NULL);
	cout<<"\n\n Tiempo de inicio de sesion: "<<asctime(localtime(&timeInicial));
	cout<<"\n Tiempo de finalizacion de sesion: "<<asctime(localtime(&timeFinal));
	cout<<"\n Tiempo total de permanencia: "<<difftime(timeFinal, timeInicial)<<" segundos";
}
