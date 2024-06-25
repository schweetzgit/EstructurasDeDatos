#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodo1{
	int dat;
	struct nodo1 *pt;
}nd1;
typedef struct nodo2{
	float dat2;
	struct nodo2 *pt2;
}nd2;
typedef struct nodo{
	nd1 *p1;
	nd2 *p2;
}nod;

main(){
	nod *q;
	q = (nod *)malloc(sizeof(nod));
	
	q->p1 = (nd1 *)malloc(sizeof(nd1));
	q->p2 = (nd2 *)malloc(sizeof(nd2));
	
	q->p1->dat = 90;
	q->p2->dat2 = 9.8;
	q->p1->pt = NULL;
	q->p2->pt2 = NULL;
	
	cout<<"\n *q --> *p1 --> [ "<<q->p1->dat<<" ] --> NULL"<<endl;
	cout<<"\n    --> *p2 --> [ "<<q->p2->dat2<<" ] --> NULL"<<endl;
	getch();

	delete(q->p1,q->p2);
	delete(q); 	
}
