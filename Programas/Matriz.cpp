#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#define n 3 //renglones
#define m 3 //columnas
using namespace std;


void leerMatrix(int Mat[n][m]){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			cout<<" ["<<i<<","<<j<<"]: ";
			cin>>Mat[i][j];
		}
	}
}

void imprimirMatrix(int Mat[n][m]){
	for(int i = 0; i < n; i++){
		for(int j =0; j < m; j++){
			cout<<Mat[i][j]<<"  ";
		}
		cout<<endl;
    }
}

void llenarMatrix(int Mat[n][m]){
	srand((unsigned)time(NULL));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			Mat[i][j]=rand()%100;
		}
	}
}

main(){
	int A[n][m];
	int B[n][m];
	
	cout<<"\n Lectura del arreglo A: ";
	cout<<endl;
	leerMatrix(A);
	cout<<"\n\n Arreglo A:\n";
	cout<<endl;
	imprimirMatrix(A);
		
	cout<<"\n Lectura del arreglo B: ";
	cout<<endl;
	leerMatrix(B);
	cout<<"\n\n Arreglo B: ";
	cout<<endl;
	imprimirMatrix(B);

	/*llenarMatrix(A);
	imprimirMatrix(A);*/
	
	cout<<"\n\n El numero de bytes que ocupa el arreglo A : "<< sizeof(A)<<" bytes";
	//cout<<"\n\n El numero de bytes que ocupa el arreglo B : "<< sizeof(B)<<" bytes";
	
	printf("\n\n La posicion de memoria en donde se comienza a almacenar al arreglo A es: %d", &A);
	//printf("\n\n La posicion de memoria en donde se comienza a almacenar al arreglo B es: %d", &B);	
}
