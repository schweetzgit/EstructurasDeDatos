#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

typedef struct punto{
	int x;
	int y;
}punto;

typedef struct punto_angulo{
	struct punto punto;
	float angulo;
}punto_angulo;

void dibujar_linea(punto_angulo cursor, punto P){
	line(cursor.punto.x, cursor.punto.y, P.x, P.y);	
}
punto avanzar(punto_angulo &cursor, float D){
	punto P;
	P.x = cursor.punto.x + (int) (D*cos(cursor.angulo));
	P.y = cursor.punto.y + (int) (D*sin(cursor.angulo));
	dibujar_linea(cursor, P);
	cursor.punto.x = P.x;
	cursor.punto.y = P.y;
	return P;
}

void dibujar_Koch(punto_angulo &cursor, float dist, int n){
	if(n == 0){
		cursor.punto = avanzar(cursor, dist);
		return;
	}
	else{ //recursividad anidada
		dibujar_Koch(cursor,dist/3,n-1);
		cursor.angulo = cursor.angulo - 120;
		dibujar_Koch(cursor,dist/3,n-1);
		cursor.angulo = cursor.angulo + 240;
		dibujar_Koch(cursor,dist/3,n-1);
		cursor.angulo = cursor.angulo - 120;
		dibujar_Koch(cursor,dist/3,n-1);
	}
}
main(){
	int gd = DETECT, gm;
	int nivelesDeRecursividad;
	punto_angulo cursor;
	float longitud;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setcolor(YELLOW);
	
	for(nivelesDeRecursividad = 0; nivelesDeRecursividad <= 4; nivelesDeRecursividad++){
		cursor.punto.x = 250;
		cursor.punto.y = 200;
		cursor.angulo = 0;
		longitud = 300.0;
		dibujar_Koch(cursor, longitud, nivelesDeRecursividad);
		delay(1600);
		cleardevice();
	}
	getch();
	closegraph();
}










