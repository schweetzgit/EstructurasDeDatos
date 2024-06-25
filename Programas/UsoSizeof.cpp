#include<stdio.h>

main(){
	int entero;
	float flotantePS;
	char caracter, cadena[20];
	double flotanteDP;
	
	entero = 100;
	flotantePS = 3.1416;
	caracter = 'M';
	flotanteDP = 5.3;
	
	printf("\n Cual es tu nombre?: ");
	gets(cadena);
	printf(" Bienvenido %s",cadena);
	printf("\n El numero de bytes que ocupa la cadena en esta computadora (64 bits) es: %d",sizeof(cadena));
	
	printf("\n\n El dato entero es: %d",entero);
	printf("\n El numero de bytes que ocupa el entero en esta computadora (64 bits) es: %d",sizeof(entero));
	
	printf("\n\n El dato de punto flotante es: %f",flotantePS);
	printf("\n El numero de bytes que ocupa el flotante de presicion simple en esta computadora (64 bits) es: %d",sizeof(flotantePS));
	
	printf("\n\n El dato de punto flotante de doble presicion es: %f",flotanteDP);
	printf("\n El numero de bytes que ocupa el flotante de presicion doble en esta computadora (64 bits) es: %d",sizeof(flotanteDP));
	
	printf("\n\n El caracter es: %c",caracter);
	printf("\n El numero de bytes que ocupa el caracter en esta computadora (64 bits) es: %d",sizeof(caracter));
}
