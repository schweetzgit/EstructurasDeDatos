#include<iostream>
#include<conio.h>
using namespace std;

typedef union Varios{
	int agno;
	float promedio;
	char genero;
}UV;

main(){
	UV x;
	UV *y;
	
	x.agno = 2021;
	cout<<" x.agno: "<<x.agno;
	y = &x;
	cout<<"\n y->agno: "<<y->agno;
	x.promedio = 9.5;
	cout<<"\n\n x.promedio: "<<x.promedio;
	cout<<"\n y->promedio: "<<y->promedio;
	cout<<"\n\n x.agno: "<<x.agno;
	
	x.genero ='H';
	cout<<"\n x.genero: "<<x.genero;
	cout<<"\n x.agno: "<<x.agno;
	cout<<"\n x.promedio: "<<x.promedio;
	
	x.agno = 2021;
	cout<<"\n\n x.agno: "<<x.agno;
	cout<<"\n x.genero: "<<x.genero;
	cout<<"\n x.promedio: "<<x.promedio;
	
	cout<<"\n\n El numero de bytes que ocupa una union Varios es: "<<sizeof(x);
}
