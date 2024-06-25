#include<iostream>
#include<conio.h>
#define totalItems 8
using namespace std;

void imprimeVect(int vector[]){
	cout<<" ";
	for(int i = 0; i < totalItems; i++){
		cout<<" "<<vector[i]<< "  ";
	}
	cout<<"\n";
}

void IntercambioBurbuja(int vector[]){
     int superior, bandera, i, temp;
     superior = totalItems;
     do{
        bandera = 0;
        superior--;
        for (i = 0;i<superior;i++){
            if(vector[i] > vector[i+1]){
               temp = vector[i];
               vector[i] = vector[i+1];
               vector[i+1] = temp; 
            }
            bandera++;
        }
        imprimeVect(vector);
        getch();
     }while(bandera>0);
}

main(){
	int vect[totalItems] = {44,55,12,42,94,18,06,67};
	cout<<"\n Secuencia original\n";
	imprimeVect(vect);
	cout<<"\n Proceso de ordenacion por metodo de Intercambio Directo (burbuja)\n\n";
	IntercambioBurbuja(vect);
	cout<<"\n Secuencia ordenada por metodo de Intercambio Directo (burbuja)\n\n";
	imprimeVect(vect);
}
