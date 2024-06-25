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

void IncrementosDecrecienteShell(int vector[]){
     int i, j, k, s ,temp, m, t = 4, h[t];
     h[0] = 8; h[1] = 4; h[2] = 2; h[3] = 1;
     for(m = 0; m < t ;m++){
        k = h[m];
        s = k;
        for(i = k; i < totalItems ;i++){
           temp = vector[i];
           j =i-k;
           if(s == 0){
               s=-k;
               s++;
               vector[s] = temp;
           }
           while(j >= 0 && temp < vector[j]){
               vector[j+k] = vector[j];
               j = j-k;
           }
           vector[j+k] = temp;
           imprimeVect(vector);
           cin.get();
        }
        getch();
     }
}

main(){
	int vect[totalItems] ={ 44,55,12,42,94,18,06,67};
	cout<<"\n Secuencia original\n";
	imprimeVect(vect);
	cout<<"\n Proceso de ordenacion por metodo de Shell\n\n";
	IncrementosDecrecienteShell(vect);
	cout<<"\n Secuencia ordenada por metodo de de Shell\n\n";
	imprimeVect(vect);
}
