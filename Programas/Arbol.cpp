#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

typedef struct nodo{
	struct nodo *iz; //definicion recursiva
	int dat;
	struct nodo *de;
}nod;

nod *raiz = NULL;

void insertarArbol(nod *aux, int ndat){
	if(raiz == NULL){
		//Se inserta el primer nodo (raiz) del árbol
		aux = new nod; 
		aux->dat = ndat;
		aux->de = NULL;
		aux->iz = NULL;
		raiz = aux;
	}
	else if(ndat < aux->dat){
	    //	Inserta a la izquierda
		if(aux->iz == NULL){
			aux->iz = new nod;
			aux->iz->iz = NULL;
			aux->iz->de = NULL;
			aux->iz->dat = ndat;
		}
		else{
			insertarArbol(aux->iz, ndat); //Recursividad
		}
	}
	else if(ndat > aux->dat){
	    //	Inserta a la derecha
		if(aux->de == NULL){
			aux->de = new nod;
			aux->de->dat = ndat;
			aux->de->iz = NULL;
			aux->de->de = NULL;
		}
		else{
			insertarArbol(aux->iz, ndat);
		}
	}
	else if(ndat == aux->dat)	{
	    cout<<"\n El dato ya existe\n";
    }
} 

void imprimeArbol(nod *aux, int n){
	if(aux == NULL) return;
	imprimeArbol(aux->de, n+1); // n+1 -> espacios a dejar
	for(int i = 1; i <= n; i++) cout<<"  ";
	cout<<aux->dat<<endl;
	imprimeArbol(aux->iz, n+1);
}

// Funcion prefijo
void recorridoPrefijo(nod *aux){
	if(aux != NULL){
		cout<<aux->dat<<"-";
		recorridoPrefijo(aux->iz);
		recorridoPrefijo(aux->de);
	}
}

// Funcion infijo
void recorridoInfijo(nod *aux){
	if(aux != NULL){
		recorridoInfijo(aux->iz);
		cout<<aux->dat<<"-";
		recorridoInfijo(aux->de);
	}
}

// Funcion posfijo
void recorridoPosfijo(nod *aux){
	if(aux != NULL){
		recorridoPosfijo(aux->iz);
		recorridoPosfijo(aux->de);
		cout<<aux->dat<<"-";	
	}
}

// Elimina punteros
void eliminaArbol(nod *aux){
	if(aux != NULL){
		eliminaArbol(aux->iz);
		eliminaArbol(aux->de);
		cout<<"\n Sale: "<<aux->dat<<"\n";
		delete(aux);
	}
}

main(){
	nod *auxMain;
	int numNodos = 0, x;
	cout<<"\n Numero de nodos deseado: ";
	cin>>numNodos;
	for(int i = 1; i <= numNodos; i++){
		cout<<"\n Ingresa dato: ";
		cin>>x;
		auxMain = raiz;
		insertarArbol(auxMain, x);
	}
	auxMain = raiz;
	cout<<endl;
	imprimeArbol(auxMain, 0);
	cin.get();
	auxMain = raiz;
	
	cout<<"\n Recorrido en prefijo ";
	recorridoPrefijo(auxMain);
	auxMain = raiz;
	
	cout<<"\n Recorrido en infijo ";
	recorridoInfijo(auxMain);
	auxMain = raiz;
	
	cout<<"\n Recorrido en posfijo ";
	recorridoPosfijo(auxMain);
	auxMain = raiz;
	
	cout<<"\n\n Elimina arbol\n";
	eliminaArbol(auxMain);
	cin.get();
}
