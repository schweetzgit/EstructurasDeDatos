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

void insercion_binaria(int vector[]){
     int i, j, iz, der, m, temp;
     for(i = 1; i < totalItems; i++){
        temp = vector[i];
        iz = 0;
        der = i-1;
        //cout<<"\n temp = "<<temp<<"\n";
        
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
    insercion_binaria(datos);
    tiempoFin = time(NULL);
    
    //imprimeVect(datos);
    cout<<"\n Metodo de Insercion con busqueda binaria";
    cout<<"\n\n Tiempo de inicio de ordenacion de 100000: "<<asctime(localtime(&tiempoInic));
    cout<<"\n Tiempo de terminacion de ordenacion de 100000: "<<asctime(localtime(&tiempoFin));
    cout<<"\n Tiempo total de ordenacion: "<<(int)difftime(tiempoFin,tiempoInic)<<" segundos";
	getch();
}
