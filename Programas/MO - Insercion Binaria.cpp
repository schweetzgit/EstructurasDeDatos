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

void insercion_binaria(int vector[]){
     int i, j, iz, der, m, temp;
     for(i = 1; i < totalItems; i++){
        temp = vector[i];
        iz = 0;
        der = i-1;
        cout<<"\n temp = "<<temp<<"\n";
        
        //	Busca la parte intermedia
        while(iz <= der){
           m = (iz + der)/2;
           if(temp < vector[m])
              der = m-1;
           else
              iz = m+1;
        }      
        for(j = i-1; j >= iz; j--){
           vector[j+1] = vector[j];   
        }
        vector[iz] = temp;
        imprimeVect(vector);
     }
}

main(){
	int vect[totalItems] = {44,55,12,42,94,18,06,67};
	cout<<"\n  Secuencia original\n";
	insercion_binaria(vect);
	cout<<"\n  Secuencia ordenada por metodo de insercion binaria\n\n";
	imprimeVect(vect);
}
