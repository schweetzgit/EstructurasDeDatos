#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

typedef struct nodito{
	int ni;
	float nf;
	char nc;
}nodi;
main(){
	nodi *rt1, *pt, *q1, *q2;
	rt1 = new nodi;
	rt1->ni = 10;
	rt1->nf = 3.5;
	cout<<endl<<"[ "<<rt1->ni<<" | "<<rt1->nf<< "]"<<endl;
	getch();
	
	pt = new nodi;
	pt->nf = 3.5;
	pt->nc = 'A';
	cout << "[ " << pt->nf << " | " << pt->nc << " ]" << endl;	


	q1 = (nodi *)malloc(sizeof(nodi));
	q2 = (nodi *)malloc(sizeof(nodi));
	
	q1->ni = 10;
	q1->nf = 3.5;
	q1->nc = 'A';
	
	q2->ni = 20;
	q2->nf = 4.6;
	q2->nc = 'B';
	
	cout << "[ " << q1->ni <<" | "<< q1->nf << " | " << q1->nc << " ]" << endl;	
	cout << "[ " << q2->ni <<" | "<< q2->nf << " | " << q2->nc << " ]" << endl;	
	
	delete(rt1);
	delete(pt);
	free(q1);
	free(q2);
}
