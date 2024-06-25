#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodo1{
	char dato;
	struct nodo1 *pt;
}nd1;
typedef struct nodo2{
	float dat2;
	struct nodo2 *pt2;
}nd2;
typedef struct nodo{
	nd1 *s1;
	nd2 *s2;
}nod;

main(){
	nod *pt;
	pt = (nod *)malloc(sizeof(nod));
	
	pt->s1 = (nd1 *)malloc(sizeof(nd1));
	pt->s2 = (nd2 *)malloc(sizeof(nd2));
	
	pt->s1->dato = 'A';
	pt->s2->dat2 = 9.8;
	pt->s2->pt2 = NULL;
	
	pt->s1->pt = (nd1 *)malloc(sizeof(nd1));
	pt->s1->pt->dato = 'B';
	
	pt->s1->pt->pt = (nd1 *)malloc(sizeof(nd1));
	pt->s1->pt->pt->dato = 'C';
	pt->s1->pt->pt->pt = NULL;
	
	cout<<"\n *pt --> *s1 --> [ "<<pt->s1->dato<<" ] --> [ "<<pt->s1->pt->dato<<" ] --> [ "<<pt->s1->pt->pt->dato<<" ] --> NULL"<<endl;
	cout<<"\n     --> *s2 --> [ "<<pt->s2->dat2<<" ] --> NULL"<<endl;
	getch();
	
	delete(pt->s1->pt->pt);
	delete(pt->s1->pt);	
	delete(pt->s1, pt->s2);
	delete(pt);
}
