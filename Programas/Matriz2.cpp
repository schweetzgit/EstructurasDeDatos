#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define n 3
#define m 3

void leerMatrix(int Mat[n][m]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		   cout<<" ["<<i<<", "<<j<<"]: ";
		   cin>>Mat[i][j];
		}
	}
}

void imprimirMatrix(int Mat[n][m]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<Mat[i][j]<<" ";
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

void sumaMatrix(int Mat_A[n][m], int Mat_B[n][m], int Mat_C[n][m]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
	   		Mat_C[i][j] = Mat_A[i][j] + Mat_B[i][j];
	   }
	}  
}

void restaMatrix(int Mat_A[n][m], int Mat_B[n][m], int Mat_C[n][m]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
	   		Mat_C[i][j] = Mat_A[i][j] - Mat_B[i][j];
	   }
	}
}

void productoMatrix (int Mat_A[][m], int Mat_B[][m], int Mat_C[][m]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			Mat_C[i][j] = 0;
			for(int k = 0; k < n; k++){
				Mat_C[i][j] = Mat_C[i][j] + Mat_A[i][k]*Mat_B[k][j];
			}
			
		}
	}
}

void productoMatrixEscalar(int Mat_A[][m], int escalar, int Mat_C[][m]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			Mat_C[i][j] = Mat_A[i][j]*escalar;
		}
	}
}

void transpuestaMatrix(int Mat_A[n][m], int Mat_C[n][m]){
	for(int i = 0; i < n; i++){
	   for(int j = 0; j < m; j++){
	   	   Mat_C[i][j] = Mat_A[j][i];
	   }
	   cout<<"\n";
	}
}

void inversaMatrix(int ma[n][m], int mc[n][m]){
    int dim, i, j, z, h, k;
	dim = n;
	int matriz[dim][dim*2], dif, mult;
	//Construccion de una matriz del tipo Matriz = (A | I)
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim*2; j++){
			matriz[i][j] = 0;
		}
	}	
	j = dim;
	for (i = 0; i < dim; i++){
		matriz[i][j] = 1;
		j++;
	}
      for (i = 0; i < dim; i++){
		for (j = 0; j < dim; j++) {
			matriz[i][j] = ma[i][j];
		}
	}
	/*Obteniendo la inversa. NO valida si es invertible
	 Se utiliza el metodo Gauss para transformar la mitad izquierda, ma,
	 en la matriz identidad, y la matriz que resulte en el lado 
	 derecho sera la matriz inversa: A^(-1), que se asignara a la matriz mc*/
	for (z = 0; z < dim; z++){
		dif = matriz[z][z];
		//haciendo 1 los elemento de la diagonal A[z][z]
		for (h = 0; h < dim*2; h++){
			matriz[z][h] = matriz[z][h]/dif;
		}
		for (i = 0; i < dim; i++){
			if (i != z){
				mult = -matriz[i][z];
				for (j = 0; j < dim*2; j++){
					matriz[i][j] = matriz[z][j]*mult + matriz[i][j];
				}
			}
		}
	}
	for (i = 0; i < n; i++){
		k = m;
		for (j = 0; j < m; j++){
			mc[i][j] = matriz[i][k];
			k++;
		}
	}
}

void generaMatrixTriangularSuperior(int Mat_C[n][m]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){ 
			if(i > j){
				Mat_C[i][j] = 0;
			}
			else{
				cout<<" ["<<i<<" , "<<j<<"]: ";
				cin>>Mat_C[i][j];
			}
		}
	}
}

void generaMatrixTriangularInferior(int Mat_C[n][m]){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){ 
			if(i < j){
				Mat_C[i][j] = 0;	
			}
			else{
				cout<<" ["<<i<<" , "<<j<<"]: ";
			  	cin>>Mat_C[i][j];
			}
		}
	}
}


void guardaMatrixArchivo(int Mat_A[n][m]){
	FILE *archi;
	char nomArchivo[120];
	cout<<"\n Ingresar la ruta y nombre del archivo: ";
	fflush(stdin);
	gets(nomArchivo);
	archi = fopen(nomArchivo,"a");
	if(archi == NULL){
		cout<<"\n Error en apertura del archivo\n Pulse tecla para continuar";
		cin.get();
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			fprintf(archi,"%d%c",Mat_A[i][j],' ');
		}
		fputc('\n',archi);
	}

	cout<<"\n El arreglo ha sido almacenado exitosamente.\n Pulse tecla para continuar";
	cin.get();
	fclose(archi);
}

void leerMatrixArchivo(int Mat_A[n][m]){
	FILE *archi;
	char nomArchivo[120];
	cout<<"\n Ingresar la ruta y nombre del archivo: ";
	fflush(stdin);
	gets(nomArchivo);
	archi = fopen(nomArchivo,"r");
	if(archi == NULL){
		cout<<"\n Error en apertura del archivo.\n Pulse tecla para continuar.";
		cin.get();
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			fscanf(archi,"%d",&Mat_A[i][j]);
			fgetc(archi);
		}
		fgetc(archi);
	}
	fclose(archi);
}

main(){
	int A[n][m], B[n][m], C[n][m], escalar, eleccion;
	do{
		cout<<"\n 1. Lectura de arreglos";
		cout<<"\n 2. Imprimir arreglos";
		cout<<"\n 3. Sumar arreglos";
		cout<<"\n 4. Restar arreglos";
		cout<<"\n 5. Multiplicar arreglos";
		cout<<"\n 6. Multiplicar un arreglo por un escalar";
		cout<<"\n 7. Transpuesta arreglos";
		cout<<"\n 8. Inversa de arreglos";
		cout<<"\n 9. Lenar arreglos con pseudoaleatorios";
		cout<<"\n 10. Generar matriz triangular superior";
		cout<<"\n 11. Generar matriz triangular inferior";
		cout<<"\n 12. Guardar el arreglo matricial";
		cout<<"\n 13. Leer el arreglo de un archivo";
		cout<<"\n 14. Salir";
		cout<<"\n Elija opcion: ";
		cin>>eleccion;
		switch(eleccion){
			case 1:
				cout<<"\n Lectura del arreglo A\n";
				leerMatrix(A);
				cout<<"\n El numero de bytes que ocupa el arreglo A: "<< sizeof(A);
				printf("\n La posicion de memoria en donde se comienza a almacenar al arreglo A es: %d",&A);
				cout<<"\n";
				cin.get();
				cout<<"\n Lectura del arreglo B\n";
				leerMatrix(B);
				cout<<"\n El numero de bytes que ocupa el arreglo B: "<< sizeof(B);
				printf("\n La posicion de memoria en donde se comienza a almacenar al arreglo B es: %d",&B);
				cout<<"\n";
				cin.get();
				break;
			case 2:
				cout<<"\n Arreglo A:\n";
				imprimirMatrix(A);
				cout<<"\n Arreglo B:\n";
				imprimirMatrix(B);
				cin.get();
				break;
			case 3:	
				cout<<"\n A + B:\n";
				sumaMatrix(A, B, C);
				imprimirMatrix(C);
				cin.get();
				break;	
			case 4: 
				cout<<"\n A - B:\n";
				restaMatrix(A, B, C);
				imprimirMatrix(C);
				cin.get();
				break;
			case 5:
				cout<<"\n A * B:\n";
				productoMatrix(A, B, C);
				imprimirMatrix(C);
				cin.get();
				break;
			case 6: 
				cout<<"\n A * escalar";
				cout<<"\n Dar el valor del escalar: ";
				cin>>escalar;
				productoMatrixEscalar(A, escalar, C);
				imprimirMatrix(C);
				cin.get();
				break;
			case 7: 
				cout<<"\n Transpuesta de A";
				transpuestaMatrix(A, C);
				imprimirMatrix(C);
				cout<<"\n Transpuesta de B";
				transpuestaMatrix(B, C);
				imprimirMatrix(C);
				cin.get();
				break;
			case 8: 
				cout<<"\n Inversa de la matriz de A\n";
				inversaMatrix(A, C);
				imprimirMatrix(C);   
				cout<<"\n Inversa de la matriz de B\n";
				inversaMatrix(B, C);
				imprimirMatrix(C);
				cin.get();	
				break;
			case 9:
				cout<<"\n Llenar el arreglo A con pseudoaleatorios\n";
				llenarMatrix(A);
				imprimirMatrix(A);
				cout<<"\n Llenar el arreglo B con pseudoaleatorios\n";
				llenarMatrix(B);
				imprimirMatrix(B);
				cin.get();
				break;   
			case 10:
				cout<<"\n Llenar el arreglo A\n";
				generaMatrixTriangularSuperior(A);
				cout<<"\n Matriz A triangular superior\n";
				imprimirMatrix(A);
				cout<<"\n Llenar el arreglo B\n";
				generaMatrixTriangularSuperior(B);
				cout<<"\n Matriz B triangular superior\n";
				imprimirMatrix(B);
				cin.get();
				break;
			case 11:
				cout<<"\n Llenar el arreglo A\n";
				generaMatrixTriangularInferior(A);
				cout<<"\n Matriz A triangular inferior\n";
				imprimirMatrix(A);
				cout<<"\n Llenar el arreglo B\n";
				generaMatrixTriangularInferior(B);
				cout<<"\n Matriz B triangular inferior\n";
				imprimirMatrix(B);
				cin.get();
				break;
			case 12: 
				cout<<"\n Guardar el arreglo A\n";
				guardaMatrixArchivo(A);
				cout<<"\n Guardar el arreglo B\n";
				guardaMatrixArchivo(B);
				cout<<"\n Datos de  la Matriz A y B almacenados con exito.\n";
				cin.get();
				break;
			case 13:
				cout<<"\n Leer arreglo A de un archivo\n";
				leerMatrixArchivo(A);
				cout<<"\n Leer arreglo B de un archivo\n";
				leerMatrixArchivo(B);
				cout<<"\n Datos leidos de archivo para la Matriz A y B.\n";
				cin.get();
				break;
			case 14:
				cout<<"\n Fin de ejecucion.\n Pulse tecla para terminar.";
				cin.get();
			default:
				cout<<"\n Opcion incorrecta vuelva a elegir.\nPulse tecla para continuar";
				cin.get();
		}
	}while(eleccion != 14);	
}
