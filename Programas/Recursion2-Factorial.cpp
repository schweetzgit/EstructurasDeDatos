#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

long long int factorial(long long int n){
	return (n>1? n*factorial(n-1) : 1);
}

main(){
  	long long int x;
  	puts("\n Introduce un entero");
	cin>>x;
	cout<<"El factorial de "<< x <<" es: "<<factorial(x)<<endl;
	cout<<"long long ocupa: "<< sizeof(x);
	getch();
}
