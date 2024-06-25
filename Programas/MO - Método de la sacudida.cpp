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

void sacudida(int vector[]){
     int j, k, arriba=1,abajo,temp;
     k = abajo = totalItems-1;
     do{
        for(j = abajo; j >= arriba ;j--)
            if(vector[j-1]> vector[j]){
               temp = vector[j-1];
               vector[j-1] = vector[j];
               vector[j] = temp; 
               k = j;
               imprimeVect(vector);
               cin.get();
             }
        for(j = arriba; j <= abajo ;j++)
            if(vector[j-1] > vector[j]){
               temp=vector[j-1];
               vector[j-1] = vector[j];
               vector[j] = temp; 
               k = j;
               imprimeVect(vector);
               cin.get();
            }
        arriba ++;
        abajo = k;
        imprimeVect(vector);
        getch();
     }while(arriba < abajo);
} 

main(){
	int vect[totalItems] = {44,55,12,42,94,18,06,67};
	cout<<"\n Secuencia original\n";
	imprimeVect(vect);
	cout<<"\n Proceso de ordenacion por metodo de la Sacudida\n\n";
	sacudida(vect);
	cout<<"\n Secuencia ordenada por metodo de la Sacudida\n\n";
	imprimeVect(vect);
}
