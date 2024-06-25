#include<iostream>
#include<stdlib.h>
using namespace std;
char nombre[80];

void nombrefun(int n){
	if(n<1){
		return;
	}
	else{
		cout<<"\n "<<nombre;
		nombrefun(n-1);
	}
}

main(){
	int edad;
	cout<<"\n Escribe tu nombre: ";
	gets(nombre);
	cout<<" Escribe tu edad: ";
	cin>>edad;
	nombrefun(edad);
}
