#include<iostream>
#define n 8
using namespace std;

void imprimeVect(int vector[]){
	cout<<" ";
	for(int i = 0; i < n; i++){
		cout<<" "<<vector[i]<< "  ";
	}
	cout<<"\n";
}

void quicksort(int vector[], int iz, int de){
    int i, j, k, x,w;
    i = iz;
    j = de;
    x = vector[(iz+de)/2]; 
    do{
        while(vector[i]< x)
        i++;
        while(x < vector[j])
        j = j-1;
        if(i <= j){
           w = vector[i];
           vector[i] = vector[j];
           vector[j] = w;
           i++;
           j--;
           
        }
        imprimeVect(vector);
     }while(i < j);
     if(iz < j)quicksort(vector, iz, j);
     if(i < de)quicksort(vector, i, de);
}
main(){
	int vect[n] = {44,55,12,42,94,18,06,67};
	cout<<"\n Secuencia original\n\n";
	imprimeVect(vect);
	cin.get();
	cout<<"\n Ordenadno por metodo Quicksort\n\n";
	quicksort(vect,0, 7);
	cout<<"\n Secuencia ordenada por metodo Quicksort\n\n";
	imprimeVect(vect);
}
