#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodo{
	int dat1;
	float dat2;
	struct nodo *pt;
}nodi;

main(){
	nodi *q1;
	q1 = new nodi;
	q1->dat1 = 10;
	q1->dat2 = 3.5;
	q1->pt = NULL;
	cout<<"\n *q1 -> [ "<<q1->dat1<<" | "<<q1->dat2<<" ]"<<endl;
	getch();
	
	q1->pt = new nodi;
	q1->pt->dat1 = 20;
	q1->pt->dat2 = 4.5;
	q1->pt->pt = NULL;
	cout<<"\n *q1 -> [ "<<q1->dat1<<" | "<<q1->dat2<<" ] -> [ "<<q1->pt->dat1<<" | "<<q1->pt->dat2<<" ] "<<endl;
	getch();
	
	q1->pt->pt = new nodi;
	q1->pt->pt->dat1 = 30;
	q1->pt->pt->dat2 = 5.5;
	q1->pt->pt->pt = NULL;
	cout<<"\n *q1 -> [ "<<q1->dat1<<" | "<<q1->dat2<<" ] -> [ "<<q1->pt->dat1<<" | "<<q1->pt->dat2<<" ] -> [ "<<q1->pt->pt->dat1<<" | "<<q1->pt->pt->dat2<<"] -> NULL"<<endl;
	getch();
	
	delete(q1->pt->pt);
	delete(q1->pt);
	delete(q1); 	
}
