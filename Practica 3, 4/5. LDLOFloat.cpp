#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

typedef struct nodo{
	struct nodo *izq;
	float dato;
	struct nodo *der;
}nod;

nod *inicio = NULL;

void insertar(float nvoFloat){
	nod *nvo, *aux = inicio;
	nvo = (nod *) malloc(sizeof(nod));
	nvo->dato = nvoFloat;
	
	if(inicio == NULL){
		//Inserta el primer elemento
		nvo->izq = NULL;
		nvo->der = NULL;
		inicio = nvo;
		return;
	}
	while(nvoFloat > aux->dato && aux->der != NULL){
		//Busca la posición correcta donde se debe insertar
		aux = aux->der;
	}
	if(nvoFloat < aux->dato && inicio == aux){
		//inserta al inicio de la LLO
		nvo->der = inicio;
		nvo->izq = NULL;
		inicio = nvo;
		aux->izq = nvo;
	}
	else if(nvoFloat < aux->dato && inicio != aux){
		//inserta en la parte intermedia
		nvo->der = aux;
		nvo->izq = aux->izq;
		aux->izq = nvo;
		nvo->izq->der = nvo;
	}else if(nvoFloat > aux->dato && aux->der == NULL){
		//inserta al final LLO
		aux->der = nvo;
		nvo->izq = aux;
		nvo->der = NULL;
	}
}

void borrar(float datoEliminar){
	nod *aux = inicio;
	if(inicio == NULL){
		cout<<"\n Lista Doblemente Ligada Ordenada vacia";
		return;
	}
	while(datoEliminar > aux->dato && aux->der != NULL){
		//Busca la posición correcta donde se debe insertar
		aux=aux->der;
	}
	if(datoEliminar == aux->dato && inicio == aux){
		//Elimina nodo al inicio
		if(aux->der != NULL){
			//elimina el primer nodo, pero hay mas
			inicio = aux->der;
			inicio->izq = NULL;
		}
		else{
			//elimina el primer y último nodo nodo
			 inicio = NULL;
		}
	}else if(datoEliminar == aux->dato && aux->der != NULL){
		//Elimina nodos intermedios
		aux->izq->der = aux->der;
		aux->der->izq = aux->izq;
	}else if(datoEliminar == aux->dato && aux->der == NULL){
		//Elimina nodos finales
		aux->izq->der = NULL;
	}else{
		cout<<"\n El dato no se encuentra en la lista";
		return;
	}
	cout<<"\n Float borrado: "<<aux->dato;
	free(aux);
}
void imprimir(){
	nod *aux = inicio;
	if(inicio == NULL){
		cout<<"\n Lista Doblemente Ligada Ordenada vacia.\n Pulse tecla para continuar.";
		getch();
		return;
	}
	cout<<endl;
	while(aux != NULL){
		cout<<" <-- ["<<aux->dato<<"] -->";
		aux = aux->der;
	}
	cout<<"\n\n Pulse Tecla para continuar.";
	getch();
}
void buscar(){
	nod *aux = inicio;
	float buscado;
	int posicion = 1, centinela = 0;
	;
	if(inicio == NULL){
		cout<<"\n Lista Doblemente Ligada Ordenada vacia.\n Pulse tecla para continuar.";
		getch();
		return;
	}
	cout<<"\n Float a buscar: ";
	cin>>buscado;
	while(aux != NULL){
		if(buscado == aux->dato){
			cout<<"\n El numero float "<<buscado<< " se encuentra en la posicion "<<posicion;
			centinela += 1;	
		}
		aux = aux->der;
		posicion++;
	}
	if(centinela == 0){
		cout<<"\n El numero float "<<buscado<< " NO se encuentra en la lista";
	}
	cout<<"\n Pulse tecla para continuar.";
	getch();
}
void eliminarTodaLDLO(){
	if(inicio == NULL){
		cout<<"\n Lista Doblemente Ligada Ordenada vacia.";
		return;
	}
	while(inicio != NULL){
		borrar(inicio->dato);
	}
}

main(){
	int opc;
	float nvoFloat;
	do{
		system("cls");
		cout<<"\n Lista Doblemente ligada Ordenada de Float";
		printf("\n\n 1) Insertar elemento");
		printf("\n 2) Imprimir lista");
		printf("\n 3) Borar elemento");
		printf("\n 4) Buscar elemento");
		printf("\n 5) Salir");
		printf("\n\n Elija opcion: ");
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\n Elemento a insertar: ";
				cin>>nvoFloat;
				insertar(nvoFloat);
				cout<<"\n Float "<<nvoFloat<<" insertado con exito.";	
				getch();
				break;
			case 2:
				imprimir();
				break;
			case 3:
				cout<<"\n Dato Float a borrar: ";
				cin>>nvoFloat;
				borrar(nvoFloat);
				cout<<"\n\n Pulse Tecla para continuar.";
				getch();
				break;
			case 4:
				buscar();
				break;
			case 5:
				eliminarTodaLDLO();
				cout<<"\n\n Pulse tecla para salir.";
				getch();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				getch();
		}
	}while(opc != 5);
}
