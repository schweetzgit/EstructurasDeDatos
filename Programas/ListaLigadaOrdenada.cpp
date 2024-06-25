#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

typedef struct nodo{
	int dato;
	struct nodo *pt;
}nod;

nod *inic = NULL;

void insertarLLO(int nvoDato){
	nod *nvo, *aux2 = NULL;
	nod *aux = inic;
	nvo = (nod *) malloc(sizeof(nod));
	nvo->dato = nvoDato;
	
	if(inic == NULL){
		//Inserta el primer elemento
		nvo->pt = NULL;
		inic = nvo;
		return;
	}
	while(nvoDato > aux->dato && aux->pt != NULL){
		//Busca la posición correcta donde se debe insertar
		aux2 = aux;
		aux = aux->pt;
	}
	if(nvoDato < aux->dato && inic == aux){
		//inserta al inicio de la LLO
		nvo->pt = inic;
		inic = nvo;
	}
	else if(nvoDato < aux->dato && inic != aux){
		//inserta en la parte intermedia
		nvo->pt = aux;
		aux2->pt = nvo;
	}else if(nvoDato > aux->dato && aux->pt == NULL){
		//inserta al final LLO
		nvo->pt = NULL;
		aux->pt = nvo;
	}
	cout<<"\n El elemento "<<nvoDato<<" se inserto con exito.";
	cout<<"\n Pulse Tecla para continuar...";
	getch();
}
void eliminaUnElementoLLO(int datoEliminar){
	nod *aux2 = NULL;
	nod *aux1 = inic;
	if(inic == NULL){
		cout<<"\n Lista Ligada Ordenada esta vacia.\n Pulse tecla para terminar...";
		getch();
		return;
	}
	
	while(datoEliminar > aux1->dato && aux1->pt != NULL){
		//Busca la posición correcta donde se debe insertar
		aux2 = aux1;
		aux1 = aux2->pt;
	}
	if(datoEliminar == aux1->dato && inic == aux1){
		//Elimina nodo al inicio
		inic = aux1->pt;
	}else if(datoEliminar == aux1->dato && aux1->pt != NULL){
		//Elimina nodos intermedios
		aux2->pt = aux1->pt;
	}else if(datoEliminar == aux1->dato && aux1->pt == NULL){
		//Elimina nodos finales
		aux2->pt = NULL;
	}else{
		cout<<"\n El dato no se encuentra en la lista";
		cout<<"\n Pulse Tecla para continuar...";
		getch();
		return;
	}
	cout<<"\n\n Sale: "<<aux1->dato;
	free(aux1);
}
void imprimeLLO(){
	nod *aux1 = inic;
	if(inic == NULL){
		cout<<"\n Lista Ligada Ordenada esta vacia.\n Pulse tecla para terminar...";
		getch();
		return;
	}
	cout<<"\n";
	while(aux1 != NULL){
		cout<<" ["<<aux1->dato<<"] -->";
		aux1 = aux1->pt;
	}
	cout<<"\n Pulse Tecla para continuar...";
	getch();
}
void eliminaTodaLLO(){
	nod *aux1 = inic;
	if(inic == NULL){
		cout<<"\n Lista Ligada Ordenada esta vacia.\n Pulse tecla para terminar...";
		getch();
		return;
	}
	while(aux1 != NULL){
		eliminaUnElementoLLO(aux1->dato);
		aux1 = inic;
	}
}
main(){
	int nPaleat, numTotal;
    time_t tinic, tfinal;
    srand(time(NULL));
    
	tinic=time(NULL);
	int opc, nvonum;
	
	do{
		system("cls");
		printf("\n [1] Insertar en la LLO.");
		printf("\n [2] Sacar de la LLO.");
		printf("\n [3] Imprimir la LLO.");
		printf("\n [4] Buscar elemento en la LLO.");
		printf("\n [5] Elimina toda la LLO.");
		printf("\n [6] Salir.");
		printf("\n Elija opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\n Ingresa valor en la fila: ");
				scanf("%d",&nvonum);
				insertarLLO(nvonum);
				break;
			case 2:
				cout<<"\n Ingresar el dato que quieres eliminar: ";
				cin>>nvonum;
				eliminaUnElementoLLO(nvonum);
				break;
			case 3: 
				imprimeLLO();
				break;
			case 4:	
				cout<<"\n Ingresar el dato que quieres buscar: ";
				cin>>nvonum;
				//buscarEnFila(nvonum);
				break;
			case 5:
				eliminaTodaLLO();
				break;				
			case 6:
				tfinal=time(NULL);
				printf("\n Tiempo de entrada. %s segundos", asctime(localtime(&tinic)));
				printf("\n Tiempo de salida. %s segundos", asctime(localtime(&tfinal)));
				printf("\n Tiempo de permanencia. %.2f", difftime(tfinal,tinic));
				printf("\n Fin del sistema. Pulse tecla para terminar.");
				eliminaTodaLLO();
				break;
			default:
			printf("\n Opcion incorrecta.\nPulse tecla para continuar.");
			break;
		} 
	}while(opc != 6);
}
