#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

typedef struct nodo{
	char dato;
	struct nodo *ptr;
}nod;

nod *inic = NULL;

void insertar(char nvoChar){
	nod *aux = inic;
	nod *nvo;
	nvo = (nod *) malloc(sizeof(nod));
	nvo->ptr = NULL;
	nvo->dato = nvoChar;
	if(inic == NULL){
		inic = nvo;
		return;
	}
	while(aux->ptr != NULL){
		aux = aux->ptr;
	}
	aux->ptr = nvo;
}
void borrar(){
	nodo *aux1 = inic;
	if(inic == NULL){
		cout<<"\n Cola vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	inic = aux1->ptr;
	cout<<"\n Se borra: "<<aux1->dato;
	free(aux1);
}
void imprimir(){
	nod *aux1 = inic;
	cout<<endl;
	if(inic == NULL){
		cout<<"\n Cola vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	while(aux1 != NULL){
		cout<<" ["<<aux1->dato<<"] <--";
		aux1 = aux1->ptr;
	}
	cout<<"\n\n Pulse tecla para continuar.";
	getch();
}
void buscar(char buscado){
	nod *aux1 = inic;
	int posicion = 1, centinela = 0;
	if(inic == NULL){
		cout<<"\n Cola vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(buscado == aux1->dato){
			cout<<"\n\n El caracter "<<buscado<< " se encuentra en la posicion "<<posicion;
			cout<<"\n Se encuentran "<<centinela<< " repetidos en la fila hasta el momento";
			centinela += 1;	
		}
		aux1 = aux1->ptr;
		posicion++;
	}
	if(centinela == 0){
		cout<<" El caracter "<<buscado<< " NO se encuentra en la fila";
	}
	cout<<"\n\n Pulse tecla para continuar.";
	getch();
}
void primero(){
	nod *aux1 = inic;
	cout<<endl;
	if(inic == NULL){
		cout<<"\n Cola vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	if(aux1->dato != NULL){
		printf(" Caracter al principio de la fila: %c",aux1->dato);
		cout<<"\n\n Pulse tecla para continuar.";
		getch();
		return;
	}
}
void final(){
	nodo *aux1 = inic;
	if(inic == NULL){
		cout<<"\n Cola vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(aux1->ptr == NULL){
				printf("\n Caracter al final de la fila: %c",aux1->dato);
		}
		aux1 = aux1->ptr;
	}	
	cout<<"\n\n Pulse tecla para continuar.";
	getch();
}
void eliminarTodaFila(){
	if(inic == NULL){
		return;
	}
	while(inic != NULL){
		borrar();
	}
}
main(){
	int opc;
	char nvoChar, buscaChar;
	do{
		system("cls");
		printf("\n Cola de Caracteres");
		printf("\n\n [1] Insertar elemento");
		printf("\n [2] Imprimir fila");
		printf("\n [3] Borar elemento");
		printf("\n [4] Buscar elemento");
		printf("\n [5] Primer elemento");
		printf("\n [6] Elemento final");
		printf("\n [7] Salir");
		printf("\n\n Elija opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("\n Ingresa caracter en la fila: ");
				fflush(stdin);
				cin>> nvoChar;
				insertar(nvoChar);
				cout<<"\n Caracter "<<nvoChar<<" insertado con exito";
				getch();
				break;
			case 2:
				imprimir();
				break;
			case 3: 
				borrar();
				cout<<"\n\n Pulse tecla para continuar.";
				getch();
				break;
			case 4:	
				cout<<"\n Caracter a buscar: ";
				fflush(stdin);
				cin>>buscaChar;
				buscar(buscaChar);
				break;
			case 5:
				primero();
				break;
			case 6:
				final();
				break;
			case 7:
				eliminarTodaFila();
				cout<<"\n\n Pulse tecla para salir.";
				getch();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				getch();
		} 
	}while(opc != 7);
}
