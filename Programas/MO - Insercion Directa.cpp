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

void insercionDirecta(int vector[]){
     int i, j, temp; //temp -> numero activo
     for(i = 1; i < totalItems; i++){ //Desde 1, la posicion 1
        temp = vector[i];
        j = i-1;
        
       while((j >= 0) && (vector[j] > temp)){
           vector[j+1] = vector[j];
           j = j-1;
        }
        vector[j+1] = temp;
        imprimeVect(vector);
     }
}

main(){
	int vect[totalItems] = {44,55,12,42,94,18,06,67};
	cout<<"\n  Secuencia original\n\n";
	insercionDirecta(vect);
	cout<<"\n  Secuencia ordenada\n\n";
	imprimeVect(vect);
}
