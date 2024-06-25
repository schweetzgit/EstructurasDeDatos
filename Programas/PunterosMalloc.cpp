// Malloc--Tomar memoria del montículo
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

main(){
	float *pt1, *pt2, *pt3;
	
	pt1 = (float *)malloc(sizeof(float));
	pt2 = (float *)malloc(sizeof(float));
	*pt1 = 19.85;
	*pt2 = 15.67;
	pt3 = NULL; 

	cout<<"\n *pt1 = "<<*pt1;
	cout<<"\n *pt2 = "<<*pt2;
	getch();
	
	cout<<"\n\n Intercambio de valores a traves de punteros";
	pt3 = pt1;
	pt1 = pt2;
	pt2 = pt3; 
	cout<<"\n *pt1 = "<<*pt1;
	cout<<"\n *pt2 = "<<*pt2;
	cout<<"\n *pt3 = "<<*pt3;
	
	//Liberar la memoria
	free(pt1);
	free(pt2);	
}
