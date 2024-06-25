#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodo1{
	int ne;
	float nf;
	char caracter;
	char cadena[15];
}nod1;

typedef struct nodo2{
	int ne2;
	float nf2;
	char caracter2;
	char cadena2[15];
}nod2;

main(){
	nod1 *ptx;
	nod2 *pty;
	ptx = (nod1 *)malloc(sizeof(nod1));
	pty = (nod2 *)malloc(sizeof(nod2));
	
	ptx->ne = 3416;
	ptx->nf = 60.5;
	ptx->caracter = 'W';
	strcpy(ptx->cadena,"Programacion 2");
	
	pty->ne2 = ptx->ne;
	pty->nf2 = ptx->nf;
	pty->caracter2 = ptx->caracter;
	strcpy(pty->cadena2,ptx->cadena);
	
	printf("\n *ptx -> [ %s | %f | %d | %c ]\n",ptx->cadena, ptx->nf, ptx->ne, ptx->caracter);
	printf(" *pty -> [ %s | %f | %d | %c ]\n",pty->cadena2, pty->nf2, pty->ne2, pty->caracter2);
		
	free(ptx);
	free(pty);
}
