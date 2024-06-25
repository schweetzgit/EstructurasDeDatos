#include<iostream>
using namespace std;

typedef enum tipoFigura{
	circulo = 1,
	cuadrado,
	rectangulo,
	salir
}enumtf;

main(){
	enumtf opcion;
	do{
		printf("\n 1. Circulo");
		printf("\n 2. Cuadrado");
		printf("\n 3. Rectangulo");
		printf("\n 4. Salir");
		printf("\n Elijia una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case circulo:
				cout<<"\n La eleccion es un circulo.\n\n";
				break;
			case cuadrado:
				cout<<"\n La eleccion es un cuadrado.\n\n";
				break;
			case rectangulo:
				cout<<"\n La eleccion es un rectangulo.\n\n";
				break;
			case salir:
				break;
			default:
				cout<<"\n\n La eleccion es incorrecta.\n";
				break;
		}
	}while(opcion!=salir);
}
