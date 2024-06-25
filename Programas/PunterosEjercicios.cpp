#include<iostream>
using namespace std;

main(){
	/*Programa 2
	float *ptr;
	float x;
	
	ptr = &x; //liga
	*ptr = 9.5;
	cout<<"\n x = "<<x;
	cout<<"\n *ptr = "<<*ptr;
	printf("\n & obtiene la direccion de x, que se ubica en: %d",&x);
	printf("\n La direccion a la que apunta ptr es: %d",ptr);
	printf("\n La direccion del puntero ptr es: %d",ptr);*/
	
	/*Programa 3
	float *pt1, *pt2;
	float x, y;
	pt1 = &x;
	pt2 = &y;
	*pt1 = 9.5;
	*pt2 = 20.0;
	cout<<"\n *pt1 = "<<*pt1;
	cout<<"\n *pt2 = "<<*pt2;*/
	
	/*Programa 4
	float *q1, *q2, *aux;
	float w1, w2, w3;
	q1 = &w1;
	q2 = &w2;
	aux = &w3;
	*q1 = 9.5;
	*q2 = 20.0;
	cout<<"\n *q1 = "<<*q1;
	cout<<"\n *q2 = "<<*q2;
	cout<<"\n *aux = "<<*aux;
	
	cout<<"\n\n Intercambio de valores a traves de punteros";
	*aux = *q1;
	*q1 = *q2;
	*q2 = *aux;
	cout<<"\n *q1 = "<<*q1;
	cout<<"\n *q2 = "<<*q2;
	cout<<"\n *aux = "<<*aux;*/
	
	/*Programa 5*/
	float *qt1, v1;
	int *qt2, v2;
	char *qt3, v3;
	qt1 = &v1;
	qt2 = &v2;
	qt3 = &v3;
	*qt1 = 3.1416;
	*qt2 = 10;
	*qt3 = 'M';
	cout<<"\n *qt1 = "<<*qt1;
	cout<<"\n *qt2 = "<<*qt2;
	cout<<"\n *qt3 = "<<*qt3;
}















