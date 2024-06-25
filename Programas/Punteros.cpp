//Definición de punteros
#include<iostream>
using namespace std;

main(){
	int *cont_dir;
	int cot;
	
	cont_dir = &cot; //liga
	//cont_dir = &cot, dirección que tiene cot
	*cont_dir = 250; 
	//contenido de donde apunta cont_dir, apunta a cot
	
	cout<<"\n cot = "<<cot;
	cout<<"\n *cot_dir = "<<*cont_dir;
	printf("\n & obtiene la direccion de cot, que se ubica en: %d",&cot);
	printf("\n La direccion almacenada en cot_dir = %d",cont_dir);
}
