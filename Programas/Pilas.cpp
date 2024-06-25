#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef struct nodo{
	int dat;
	struct nodo *pt;
}nod;
nod *tope = NULL;
void sacarPila();
//Nuevas funciones
void buscar(){
	nod *aux = tope;
	int pos = 1;
	int buscaDato;
	cout<<"\n Dato a buscar: ";
	cin>>buscaDato;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	while(aux != NULL){
		if(aux->dat == buscaDato){
			printf("\n Dato en posicion %d de la pila \n",pos);
			return;
		}
		else{
			aux = aux->pt;
			pos++;	
		}
	}	
	cout<<"\n El dato no se encuentra\n";
}
void top(){
	nod *aux = tope;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	if(aux->dat != NULL){
		printf("\n Dato en el tope de la pila: %d",aux->dat);
		return;
	}
}
void bottom(){
	nod *aux = tope;
	int pos = 0;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	tope = aux->pt;
	while(aux != NULL){
		if(aux == tope){
			printf("\n Dato en el fondo de la pila: %d",aux->dat);
			return;
		}
		else{
			aux = aux->pt;
			pos++;
		}
}
}


void insertarPila(int nvodato){
	nod *nvo = NULL;
	nvo = (nod *)malloc(sizeof(nod));
	nvo->dat = nvodato;
	if(tope == NULL){
		nvo->pt = NULL;
	}else{
		nvo->pt = tope;
	}
	tope = nvo;
}
void sacarPila(){
	nod *aux = tope;
	if(tope == NULL){
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	tope = aux->pt;
	cout<<"\n Sale: "<<aux->dat;
	free(aux);
}
void imprimirPila(){
	nod *aux = tope;
	if(tope == NULL){// la pila esta vacia si es cierto
		cout<<"\n Pila vacia";
		cin.get();
		return;
	}
	while(aux != NULL){
		cout<<"\n "<<aux->dat;
		aux = aux->pt; 
	}
}
main(){
	int opc, nuevoDato, buscaDato;
	do{
		cout<<"\n\n 1. Insertar elemento";
		cout<<"\n 2. Imprimir pila";
		cout<<"\n 3. Sacar de la pila";
		cout<<"\n 4. Buscar en la pila";
		cout<<"\n 5. Elemento tope";
		cout<<"\n 6. Elemento fondo";
		cout<<"\n 7. Salir";
		cout<<"\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\n Dato a insertar: ";
				cin>>nuevoDato;
				insertarPila(nuevoDato);
				break;
			case 2:
				imprimirPila();
				break;
			case 3:
				sacarPila();
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
				cout<<"\n Hasta la vista";
				cin.get();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				cin.get();
		}
	}while(opc!=7);
}
