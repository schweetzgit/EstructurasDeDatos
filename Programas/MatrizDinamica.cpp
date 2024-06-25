#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
using namespace std;
float **Mat;

void creaMatriz(int nr, int nc){
	Mat = (float **) calloc (nr,sizeof(float));
	for(int i = 0; i < nr; i++){
		Mat[i] = (float *) calloc (nc,sizeof(float));
	}	
}
void eliminarMatriz(int nr){
	for(int i = 0; i < nr; i++){
		free(Mat[i]);	
    }
    free (Mat);
}

void leerMatriz(int nr, int nc){
	for(int i = 0; i < nr; i++){
		for(int j = 0; j < nc; j++){
		   cout<<" ["<<i<<", "<<j<<"]: ";
		   cin>>Mat[i][j];
		}
	}
}

void imprimirMatriz(int nr, int nc){
	for(int i = 0; i < nr; i++){
		for(int j = 0; j < nc; j++){
			cout<<Mat[i][j]<<" ";
		}
		cout<<endl;
    }
}

main(){
	int numRen, numCol;
	char resp;
	do{
		cout<<"\n Dar numero de renglones: ";
		cin>>numRen;
		cout<<" Dar numero de columnas: ";
		cin>>numCol;
	
		cout<<"\n Creacion del arreglo bidimensional dinamico";
		creaMatriz(numRen, numCol);
		cout<<"\n Lectura del arreglo\n";
		leerMatriz(numRen, numCol);
		cout<<"\n Impresion del arreglo\n";
		imprimirMatriz(numRen, numCol);
		cout<<"\n Eliminar arreglo\n";
		eliminarMatriz(numRen);
		
		cout<<"\n Desea continuar ejecutando el sistema [s->Si]: ";
		fflush(stdin);
		cin>>resp;
		system("cls");
	}while(tolower(resp) == 's');
}
