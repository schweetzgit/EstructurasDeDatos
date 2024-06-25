#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef struct nodo{
	double dato;
	struct nodo *ptr;
}nod;

nod *tope = NULL;

void insertar(double nvoDouble){
	nod *nvo = NULL;
	nvo = (nod *)malloc(sizeof(nod));
	nvo->dato = nvoDouble;
	if(tope == NULL){
		nvo->ptr = NULL;
	}else{
		nvo->ptr = tope;
	}
	tope = nvo;
}
void borrar(){
	nod *aux = tope;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	tope = aux->ptr;
	printf("\n Elemento: %lf borrado.",aux->dato);
	free(aux);
}
void imprimir(){
	nod *aux = tope;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	while(aux != NULL){
		printf("\n %lf",aux->dato);
		aux = aux->ptr; 
	}
	cout<<"\n\n Pulse tecla para continuar.";
	getch();
}
void buscar(){
	nod *aux = tope;
	int centinela = 0;
	double buscaDato;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	cout<<"\n Dato a buscar: ";
	cin>>buscaDato;
	while(aux != NULL){
		if(aux->dato == buscaDato){
			printf("\n Dato encontrado: %lf.",aux->dato);
			cout<<"\n Se encuentran "<<centinela<< " repetidos en la pila hasta el momento.\n";
			centinela += 1;
		}
		aux = aux->ptr;
	}	
	
	if(centinela == 0){
		cout<<"\n El dato no se encuentra\n";
	}
	cout<<"\n Pulse tecla para continuar.";
	getch();
}
void top(){
	nod *aux = tope;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	if(aux->dato != NULL){
		printf("\n Dato en el tope de la pila: %lf",aux->dato);
		cout<<"\n\n Pulse tecla para continuar.";
		getch();
		return;
	}
}
void bottom(){
	nod *aux = tope;
	int pos = 0;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cout<<"\n Pulse tecla para continuar.";
		getch();
		return;
	}
	while(aux != NULL){
		if(aux->ptr == NULL){
			printf("\n Dato en el fondo de la pila: %lf",aux->dato);
			//printf("\n Dato en posicion %d de la pila. ",++pos);
		}
		aux = aux->ptr;
	}	
	cout<<"\n\n Pulse tecla para continuar.";
	getch();
}
void eliminarTodaPila(){
	if(tope == NULL){
		return;
	}
	while(tope != NULL){
		borrar();
	}
}
main(){
	int opc;
	double nuevoDouble;
	do{
		system("cls");
		cout<<"\n Pila de Double";
		cout<<"\n\n 1. Insertar elemento";
		cout<<"\n 2. Imprimir pila";
		cout<<"\n 3. Sacar elemento";
		cout<<"\n 4. Buscar elemento";
		cout<<"\n 5. Elemento tope";
		cout<<"\n 6. Elemento fondo";
		cout<<"\n 7. Salir";
		cout<<"\n\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\n Elemento a insertar: ";
				cin>>nuevoDouble;
				insertar(nuevoDouble);
				cout<<"\n Double "<<nuevoDouble<<" insertado con exito";
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
				buscar();
				break;
			case 5:
				top();
				break;
			case 6:
				bottom();
				break;
			case 7:
				eliminarTodaPila();
				cout<<"\n\n Pulse tecla para salir.";
				getch();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				getch();
		}
	}while(opc != 7);
}
