#include<iostream>
using namespace std;

unsigned fibonacci(unsigned n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else{
		return(fibonacci(n-1)+fibonacci(n-2));
	}
}

main(){
	int resp;
	do{
		unsigned numero;
		cout<<"\n Dar un numero entero positivo: ";
		cin>>numero;
		cout<<"\n El Fibonacci de "<<numero<<" es "<<fibonacci(numero);
		cout<<"\n Desea continuar obteniendo el Fibonacci de otro número [1->Si]: ";
		cin>> resp;
	}while(resp==1);	
}


