#include<iostream>
#define totalItems 8
using namespace std;

void imprimeVect(int vector[]){
	cout<<" ";
	for(int i = 0; i < totalItems; i++){
		cout<<" "<<vector[i]<< "  ";
	}
	cout<<"\n";
}

void seleccion(int vector[]){
     int i, j, min, temp;
     for(i = 0; i < totalItems; i++){
        min = i;
        //Busca el elemento mas pequeño
        for (j = i+1; j < totalItems; j++){
            if(vector[j] < vector[min])
               min = j;
        }
        temp = vector[i];
        vector[i] = vector[min];
        vector[min] = temp; 
        imprimeVect(vector);
     }
}

main(){
	int vect[totalItems] = {44,55,12,42,94,18,06,67};
	cout<<"\n Secuencia original\n\n";
	imprimeVect(vect);
	cout<<"\n Proceso de ordenacion por metodo de selecion\n\n";
	seleccion(vect);
	cout<<"\n Secuencia ordenada por metodo de selecion\n\n";
	imprimeVect(vect);
}
