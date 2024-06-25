#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;
typedef struct nodo{
	struct nodo *izq;
	int dato;
	struct nodo *der;
}nod;

nod *inic=NULL;

void insertarLDLO(int nvoDato){
	nod *nvo, *aux=inic;
	
	nvo=(nod *) malloc(sizeof(nod));
	nvo->dato=nvoDato;
	
	if(inic==NULL){
		//Inserta el primer elemento
		nvo->izq=NULL;
		nvo->der=NULL;
		inic= nvo;
		return;
	}
	while(nvoDato > aux->dato && aux->der!=NULL){
		//Busca la posición correcta donde se debe insertar
		aux=aux->der;
	}
	if(nvoDato<aux->dato && inic==aux){
		//inserta al inicio de la LLO
		nvo->der=inic;
		nvo->izq=NULL;
		inic=nvo;
		aux->izq=nvo;
	}
	else if(nvoDato<aux->dato && inic!=aux){
		//inserta en la parte intermedia
		nvo->der=aux;
		nvo->izq=aux->izq;
		aux->izq=nvo;
		nvo->izq->der=nvo;
	}else if(nvoDato > aux->dato && aux->der==NULL){
		//inserta al final LLO
		aux->der=nvo;
		nvo->izq= aux;
		nvo->der=NULL;
	}
	
	cout<<"\nEl elemento "<<nvoDato<<" se inserto con exito.";	
}
//////////////////////////////////////////////

void eliminaUnElementoLDLO(int datoEliminar){
	nod *aux=inic;
	if(inic==NULL){
		cout<<"\nLista Doblemente Ligada Ordenada esta vacia.\nPulse tecla para terminar.";
		getch();
		return;
	}
	
	while(datoEliminar > aux->dato && aux->der!=NULL){
		//Busca la posición correcta donde se debe insertar
		aux=aux->der;
	}
	if(datoEliminar == aux->dato && inic==aux){
		//Elimina nodo al inicio
		if(aux->der!=NULL){
			//elimina el primer nodo, pero hay mas
			inic=aux->der;
			inic->izq=NULL;
		}else{
			//elimina el primer y último nodo nodo
			inic=NULL;
		}
		
	}else if(datoEliminar == aux->dato && aux->der!=NULL){
		//Elimina nodos intermedios
		aux->izq->der=aux->der;
		aux->der->izq=aux->izq;
	}else if(datoEliminar == aux->dato && aux->der==NULL){
		//Elimina nodos finales
		aux->izq->der=NULL;
	}else{
		cout<<"\n El dato no se encuentra en la lista";
		cout<<"\n\nPulse Tecla para continuar";
		getch();
		return;
	}
	cout<<"\n\nSale: "<<aux->dato;
	free(aux);
}
/////////////////////////////////////////////////////
void imprimeLDLO(){
	nod *aux= inic;
	if(inic==NULL){
		cout<<"\nLista Doblemente Ligada Ordenada esta vacia.\nPulse tecla para terminar.";
		getch();
		return;
	}
	while(aux!=NULL){
		cout<<"<--["<<aux->dato<<"] -->";
		aux=aux->der;
	}
	cout<<"\n\nPulse Tecla para continuar";
	getch();
}
/////////////////////////////////////////////
void eliminaTodaLDLO(){
	
	if(inic==NULL){
		cout<<"\nLista Doblemente Ligada Ordenada esta vacia.\nPulse tecla para terminar.";
		getch();
		return;
	}
	while(inic!=NULL){
		eliminaUnElementoLDLO(inic->dato);
	}
	
}

main()
{
	int nPaleat, numTotal;
    time_t tinic, tfinal;
    srand(time(NULL));
    
	tinic=time(NULL);
	int opc, nvonum;
	
	do{
		system("cls");
		
		printf("\n[1] Insertar en la Lista Doblemente Ligada Ordenada.");
		printf("\n[2] Sacar de la LDLO.");
		printf("\n[3] Imprimir la LDLO.");
		printf("\n[4] Buscar elemento en la LDLO.");
		printf("\n[5] Elimina toda la LDLO.");
		printf("\n[6] guardar LDLO");
		printf("\n[7] Cargar LDLO desde archivo");
		printf("\n[8] LlenaR LDLO con numeros pseudoaleatorios");
		printf("\n[9] Salir.");
		printf("\nElija opcion [1, 2, 3, 4, 5, 6, 7, 8, 9]");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nIngresa valor en la LDLO: ");
				scanf("%d",&nvonum);
				insertarLDLO(nvonum);
				break;
			case 2:
				cout<<"\n ingresar el dato que quieres eliminar: ";
				cin>>nvonum;
				eliminaUnElementoLDLO(nvonum);
				break;
			case 3: 
				imprimeLDLO();
				break;
			case 4:	
				cout<<"\n ingresar el dato que quieres buscar: ";
				cin>>nvonum;
				//buscarEnFila(nvonum);
				break;
			case 5:
				eliminaTodaLDLO();
				break;
			case 6:
				//guardaNodosFormados();
				break;	
			case 7:
				//LeerNodosDeArchivo();
				break;
			case 8:
				cout<<"\n Numero de datos a insertar: ";
				cin>>numTotal;
			    for(int i=1;i<=numTotal;i++)
				{
					//insertaFila(rand()%500);
				}
				break;				
			case 9:
				
				tfinal=time(NULL);
				printf("\nTiempo de entrada. %s segundos", asctime(localtime(&tinic)));
				printf("\nTiempo de salida. %s segundos", asctime(localtime(&tfinal)));
				printf("\nTiempo de permanencia. %.2f", difftime(tfinal,tinic));
				printf("\nFin del sistema. Pulse tecla para terminar.");
				eliminaTodaLDLO();
				break;
			default:
			printf("\nOpcion incorrecta.\nPulse tecla para continuar.");
			break;
		} 
	}while(opc!=9);
	
}
