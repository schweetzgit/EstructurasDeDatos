#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodo{
	int dato;
	struct nodo *pt;
}nodi;

typedef struct nodo2{
	int ne2;
	char cadena2[5];
}nod2;

main(){
	nodi *rt;
	rt = new nodi;
	rt->dato = 67;
	rt->pt = NULL;
	cout<<"\n *rt -> [ "<<rt->dato<<" ] -> NULL"<<endl;
	getch();
	
	rt->pt = new nodi;
	rt->pt->dato = 68;
	rt->pt->pt = NULL;
	cout<<"\n *rt -> [ "<<rt->dato<<" ] -> [ "<<rt->pt->dato<<" ] -> NULL"<<endl;
	getch();
	
	rt->pt->pt = new nodi;
	rt->pt->pt->dato = 69;
	rt->pt->pt->pt = NULL;
	cout<<"\n *rt -> [ "<<rt->dato<<" ] -> [ "<<rt->pt->dato<<" ] -> [ "<<rt->pt->pt->dato<<" ] -> NULL"<<endl;
	getch();
	
	delete(rt->pt->pt);
	delete(rt->pt);
	delete(rt); 	
}
