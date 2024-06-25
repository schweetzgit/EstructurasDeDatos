#include<iostream>
#include<conio.h>
using namespace std;
#define tam 2

typedef struct Mascota{
	int idMascota;
	char nombre[35];
	char especie[30];
	char genero;
}mascota;

void leerVeterinaria(mascota veterinaria[tam]){
	printf("\n Lectura de registros mascota\n");
	for(int i = 0; i < tam; i++){
		printf(" \n Registro de Mascota %d \n",i+1);
		printf(" Identificador de la mascota: ");
		cin>>veterinaria[i].idMascota;
		printf(" Nombre: ");
		fflush(stdin);
		gets(veterinaria[i].nombre);
		printf(" Especie: ");
		gets(veterinaria[i].especie);
		printf(" Genero [h-hembra, m-macho]: ");
		cin>>veterinaria[i].genero;
	}
}

void imprimirVeterinaria(mascota veterinaria[tam]){
	printf("\n Registros mascota almacenados en el vector\n");
	for(int i = 0; i < tam; i++){
		cout<<"\n idMascota: "<<veterinaria[i].idMascota;
		cout<<"\n Nombre: " <<veterinaria[i].nombre;
		cout<<"\n Especie: "<<veterinaria[i].especie;
		cout<<"\n Genero [h-hembra, m-macho]: "<< veterinaria[i].genero;
		cout<<endl;
	}
}

main(){
	int opc;
	mascota veterinariaMaskota[tam];
	do{
		cout<<"\n 1. Leer un vector de registros mascota: ";
		cout<<"\n 2. Imprimir el vector de registros mascota: ";
		cout<<"\n 3. Salir";
		cout<<"\n Elija una opcion: ";
		cin>> opc;
		
		switch(opc){
			case 1: 
				leerVeterinaria(veterinariaMaskota);
			    break;
			case 2: 
				imprimirVeterinaria(veterinariaMaskota);
			    break;	
			case 3: 
				cout<<"\n Hasta la vista. Fin de ejecucion.";
			    getch();
			    break;
			default: 
				cout<<"\n Opción incorrecta, vuelva a elegir.\n Pulse tecla para continuar";
				getch();
		}	
	}while(opc != 3);
	cout<<"\n El espacio de memoria que ocupa un vector de tipo estructura mascota es "<< sizeof(veterinariaMaskota)<<endl;
}
