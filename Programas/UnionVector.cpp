#include<iostream>
#include<conio.h>
#include<ctype.h>
#define n 3
using namespace std;

typedef union miTipo{
	int e;
	float f;
	char c;
}uniTipo;

void leeArreglo(uniTipo vect[n], int num){
	if(num == 1){
		for(int i = 0; i < n; i++){
			cout<<"\n ["<<i<<"]: ";
			cin>>vect[i].e;
		}
	}
	else if (num == 2){
		for(int i = 0; i < n; i++){
			cout<<"\n ["<<i<<"]: ";
			cin>>vect[i].f;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			cout<<"\n ["<<i<<"]: ";
			cin>>vect[i].c;
		}
	}
}

void imprimeArreglo(uniTipo vect[n], int num){
	if(num == 1){
		cout<<" [";
		for(int i = 0; i < n; i++){
			cout<<vect[i].e<<" ";
		}
		cout<<"]\n";
	}
	else if (num == 2){
		cout<<" [";
		for(int i = 0; i < n; i++){
			cout<<vect[i].f<<" ";
		}
		cout<<"]\n";
	}
	else{
		cout<<" [";
		for(int i = 0; i < n; i++){
			cout<<vect[i].c<<" ";
		}
		cout<<"]\n";
	}
}

main(){
	uniTipo A[n];
	char respEx;
	int respTipo;
	do{
		cout<<"\n Tipo de dato";
		cout<<"\n 1. Enteros";
		cout<<"\n 2. Flotantes";
		cout<<"\n 3. Caracateres";
		cout<<"\n Elija una opcion: ";
		cin>>respTipo;
		leeArreglo(A,respTipo);
		imprimeArreglo(A,respTipo);
		getch();
		cout<<"\n Desea continuar [s->Si]: ";
		cin>>respEx;
	}while(tolower(respEx) == 's');	
}
