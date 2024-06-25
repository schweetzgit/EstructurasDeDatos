#include<iostream>
#include<time.h>
#include<conio.h>
#define totalItems 100000
using namespace std;

void imprimeVect(int vector[]){
	cout<<" ";
	for(int i = 0; i < totalItems; i++){
		cout<<" "<<vector[i]<< "  ";
	}
	cout<<"\n";
}

void insercion_directa(int vector[]){
     int i, j, temp;
     for(i = 1; i < totalItems; i++){
        temp=vector[i];
        j = i-1;
        
       while((j >= 0) && (vector[j] > temp)){
           vector[j+1] = vector[j];
           j = j-1;
        }
        vector[j + 1] = temp;
        //imprimeVect(vector);
     }
}

main(){
	FILE *arch;
    time_t tiempoInic,tiempoFin;
	int datos[totalItems];
	
	arch = fopen("c:/borrame/datos100000.txt", "r");
    for(int i = 0; i < totalItems; i++) 
		fscanf(arch,"%d",&datos[i]);
	fclose(arch);
	
	tiempoInic = time(NULL);
    insercion_directa(datos);
    tiempoFin =time(NULL);
    
    //imprimeVect(datos);
    cout<<"\n Metodo de Insercion Directa";
    cout<<"\n\n Tiempo de inicio de ordenacion de 100000: "<<asctime(localtime(&tiempoInic));
    cout<<"\n Tiempo de terminacion de ordenacion de 100000: "<<asctime(localtime(&tiempoFin));
    cout<<"\n Tiempo total de ordenacion: "<<(int)difftime(tiempoFin,tiempoInic)<<" segundos";
	getch();
}
