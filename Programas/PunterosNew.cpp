// New--Tomar memoria del montículo
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

main(){
	float *q1, *q2, *aux;
	
	q1 = new float;
	q2 = new float;
	aux = new float;
	*q1 = 9.5;
	*q2 = 20.0;; 

	cout<<"\n *q1 = "<<*q1;
	cout<<"\n *q2 = "<<*q2;
	getch();
	
	cout<<"\n\n Intercambio de valores a traves de punteros";
	*aux = *q1;
	*q1 = *q2;
	*q2 = *aux; 
	cout<<"\n *q1 = "<<*q1;
	cout<<"\n *q2 = "<<*q2;
	cout<<"\n *aux = "<<*aux;
	
	//Liberar la memoria
	delete(q1);
	delete(q2);	
	delete(aux);
}
