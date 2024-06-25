#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

typedef struct nodo{
	int dato;
	struct nodo *ptr;
}nod;

nod *inic = NULL;

void insertaFilaCircular(int nvoDato){
	nod *aux = inic;
	nod *nvo;
	nvo = (nod *) malloc(sizeof(nod));
	nvo->ptr = NULL;
	nvo->dato = nvoDato;
	//Se inserta el primer nodo
	if(inic == NULL){
		inic = nvo;
		nvo->ptr = inic;
		return;
	}
	//Se busca el último nodo formado
	while(aux->ptr != inic){
		aux = aux->ptr;
	}
	//Liga el último elemento a la fila o cola
	nvo->ptr = inic;
	aux->ptr = nvo;
}
void eliminarElementoFilaCircular(){
	nodo *aux = inic;
	nodo *aux1 = inic;
	if(inic == NULL){
		cout<<"\n Fila o Cola vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	//Se busca el último nodo formado
	while(aux1->ptr != inic){
		aux1 = aux1->ptr;
	}
	if(aux->ptr == inic){
		inic = NULL;
	}
	else{
		inic = aux->ptr;
	    aux1->ptr = inic;
	}
	cout<<"\n Sale de la fila: "<<aux->dato;
	free(aux);
}
void imprimirNodosFilaCircular(){
	nod *aux1 = inic;
	cout<<endl;
	if(inic == NULL){
		cout<<"\n Fila o Cola vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	do{
		cout<<" ["<<aux1->dato<<"] <--";
		aux1 = aux1->ptr;
	}while(aux1!=inic);
	cout<<"\n Pulse tecla para continuar";
	getch();
}
void eliminaTodaFilaCircular(){
	if(inic == NULL){
		cout<<"\n Fila o Cola vacia";
		cout<<"\n Pulse tecla para continuar";
		return;
	}
	while(inic != NULL){
		eliminarElementoFilaCircular();
	}
}
void buscarEnFilaCircular(int buscado){
	nod *aux1 = inic;
	int posicion = 1, centinela = 0;
	cout<<endl;
	if(inic == NULL){
		cout<<"\n Fila o Cola vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	do{
		if(buscado == aux1->dato){
			cout<<"\n El dato "<<buscado<< " se encuentra en la posicion "<<posicion;
			cout<<"\n Se encuentran "<<centinela<< " repetidos en la fila hasta el momento.";
			cout<<"\n Pulse tecla para continuar";
			getch();
			centinela += 1;	
		}
		aux1 = aux1->ptr;
		posicion++;
	}while(aux1 != inic);
	if(centinela == 0){
		cout<<"\n El dato "<<buscado<< " NO se encuentra en la FILA";
	}
	cout<<"\n Pulse tecla para continuar";
	getch();
}

void guardaNodosFormados(){
	FILE *arch;
	nod *aux1 = inic;
	char rutaArchi[100];
	if(inic == NULL){
		cout<<"\n Fila o Cola vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	cout<<"\n Dar ruta y nombre del archivo: ";
	fflush(stdin);
	gets(rutaArchi);
	arch = fopen(rutaArchi,"w");
	if(arch == NULL){
		cout<<"\n Error en apertura de archivo.";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	do{
		fprintf(arch, "%d\n", aux1->dato);
		aux1 = aux1->ptr;
	}while(aux1 != inic);
	fclose(arch);
	cout<<"\n Los datos de la fila fueron guardados con exito.";
	cout<<"\n Pulse tecla para continuar";
	getch();
}
void LeerNodosDeArchivo(){
	FILE *arch;
	char rutaArchi[100];
	int undato;
	cout<<"\n Dar ruta y nombre del archivo: ";
	fflush(stdin);
	gets(rutaArchi);
	arch = fopen(rutaArchi,"r");
	if(arch == NULL){
		cout<<"\n Error en apertura de archivo.";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(!feof(arch)){
		fscanf(arch, "%d\n", &undato);
		insertaFilaCircular(undato);
	}
	fclose(arch);
	cout<<"\n Los datos del archivo fueron ingresados a la fila con exito.";
	cout<<"\n Pulse tecla para continuar";
	getch();
}

main(){
	int nPaleat, numTotal;
    time_t tinic, tfinal;
    srand(time(NULL));
    
	tinic = time(NULL);
	int opc, nvonum;
	
	do{
		system("cls");
		printf("\n\n FILA CIRCULAR");
		printf("\n [1] Insertar.");
		printf("\n [2] Sacar.");
		printf("\n [3] Imprimir");
		printf("\n [4] Buscar elemento.");
		printf("\n [5] Elimina toda la fila.");
		printf("\n [6] Guardar fila");
		printf("\n [7] Cargar fila desde archivo");
		printf("\n [8] Llena fila con numeros pseudoaleatorios");
		printf("\n [9] Salir.");
		printf("\n Elija opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("\n Ingresa valor en la fila: ");
				scanf("%d",&nvonum);
				insertaFilaCircular(nvonum);
				break;
			case 2:
				eliminarElementoFilaCircular();
				break;
			case 3: 
				imprimirNodosFilaCircular();
				break;
			case 4:	
				cout<<"\n Ingresar el dato que quieres buscar: ";
				cin>>nvonum;
				buscarEnFilaCircular(nvonum);
				break;
			case 5:
				eliminaTodaFilaCircular();
				break;
			case 6:
				guardaNodosFormados();
				break;	
			case 7:
				LeerNodosDeArchivo();
				break;
			case 8:
				cout<<"\n Numero de datos a insertar: ";
				cin>>numTotal;
			    for(int i = 1; i <= numTotal; i++){
					insertaFilaCircular(rand()%500);
				}
				break;				
			case 9:
				tfinal = time(NULL);
				printf("\n Tiempo de entrada. %s segundos", asctime(localtime(&tinic)));
				printf("\n Tiempo de salida. %s segundos", asctime(localtime(&tfinal)));
				printf("\n Tiempo de permanencia. %.2f", difftime(tfinal,tinic));
				printf("\n Fin del sistema. Pulse tecla para terminar.");
				eliminaTodaFilaCircular();
				break;
			default:
				printf("\n Opcion incorrecta.\nPulse tecla para continuar.");
				break;
		} 
	}while(opc!=9);
}
