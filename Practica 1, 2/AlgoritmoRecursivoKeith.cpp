/*8. Implementar un algoritmo recursivo que tenga al menos 
    dos llamadas así mismo, no visto en clase ni apuntes.*/
#include<iostream>
#include<ctype.h>
#include<conio.h>
using namespace std;

int lenCont(int num){  
	int dig = 0;
    while(num > 0){
        num /= 10;
        dig++;
    }
     return dig; 
}

main(){
    int num1 = 0, num2 = 0, serieKeith[10], aux = 0, i = 0, suma = 0, numKeith;

	cout<<"\n Decir si un numero es numero Keith\n";
	cout<<" Ejemplo de numeros Keith: 197, 742, 1104, 1537...\n";
	cout<<" ---------------------------------------------------\n";	
	cout<<" Introduce un numero: ";
    cin>>num1;
    cout<<"\n";
    num2 = num1;
    for(i = lenCont(num2)-1; i >= 0; i--) {
        serieKeith[i] = num1 % 10;
        num1 /= 10;
    }
    
    while(aux == 0){
        for(i = 0; i < lenCont(num2); i++){
        	suma += serieKeith[i];
		}
        if(suma == num2){
            aux = 1;
        	numKeith = 1;
        }
		else if(suma > num2){
            aux = 1;
            numKeith = 0;
        }
        for(i = 0; i < lenCont(num2); i++){
        	cout<<"  "<<serieKeith[i];
            if(i != lenCont(num2)-1){
				serieKeith[i] = serieKeith[i+1];
				cout<<" +";
			}
            else{
            	serieKeith[i] = suma;
            	cout<<" = "<< serieKeith[i];
			}   
        }
        suma = 0;
        cout<<"\n";
    }
    
    if(numKeith == 1){
    	cout<<"\n Es un numero de Keith.\n";
    }
	else{
        cout<<"\n No es un numero de Keith.\n";
    }
    getch();
}
