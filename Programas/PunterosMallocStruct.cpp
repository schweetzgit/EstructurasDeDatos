#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodo1{
	int ne;
	float nf;
	char caracter;
	char cadena[4];
}nod1;

typedef struct nodo2{
	int ne2;
	char cadena2[5];
}nod2;

main(){
	nod1 *x;
	nod2 *y;
	x = (nod1 *)malloc(sizeof(nod1));
	y = (nod2 *)malloc(sizeof(nod2));
	
	strcpy(x->cadena,"MAC");
	x->nf = 3.1416;
	x->ne = 600;
	x->caracter = 'Z';
	
	strcpy(y->cadena2,"HOLA");
	y->ne2 = 800;
	
	printf("\n *x -> [ %s | %f | %d | %c ]\n",x->cadena, x->nf, x->ne, x->caracter);
	printf(" *y -> [ %s | %d ]",y->cadena2, y->ne2);
		
	free(x);
	free(y);
}
