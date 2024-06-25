#include<iostream>
using namespace std;

unsigned suma_n_naturales(unsigned n){
	cout<<"\n "<<n;
	if(n>1){
		
		return (n+suma_n_naturales(n-1));
	}
	else{
		return 1;
	}
}

main(){
	unsigned numNatural;
	cout<<"\n Dar un numero natural: ";
	cin>>numNatural;
	cout<<"\n La suma de numeros de 1 a "<<numNatural<<" es: "<<suma_n_naturales(numNatural);
}
