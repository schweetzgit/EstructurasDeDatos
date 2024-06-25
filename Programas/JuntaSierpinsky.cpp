#include<graphics.h>
#include<iostream>
#include<dos.h>
using namespace std;

int vect[8];

typedef struct vertice{
	int x;
	int y;
}vertice;

vertice Mitad(vertice P1, vertice P2 ){
	vertice Resultado;
	Resultado.x = (P1.x + P2.x) / 2;
	Resultado.y = (P1.y + P2.y) / 2;
	return(Resultado);
}

void Dibujar_Triangulo_Relleno(vertice A, vertice B, vertice C ){
	vect[0]=A.x;
	vect[1]=A.y;
	vect[2]=B.x;
	vect[3]=B.y;
	vect[4]=C.x;
	vect[5]=C.y;
	vect[6]=vect[0];
	vect[7]=vect[1];
	
	setfillstyle(1,CYAN);
	fillpoly(3, vect);
}

void Dibujar_Sierpinski(vertice A, vertice B, vertice C, int N ){
	vertice AB, BC, CA;
	if(N==0){	// Triángulo Mínimo
	    Dibujar_Triangulo_Relleno( A, B, C );
		return;
    }
    else{
    	// Dividir en 3 triángulos
		AB = Mitad( A, B );
		BC = Mitad( B, C );
		CA = Mitad( C, A );
		Dibujar_Sierpinski( A, AB, CA, N-1 );
		Dibujar_Sierpinski( AB, B, BC, N-1 );
		Dibujar_Sierpinski( CA, BC, C, N-1 );
	}
}

main(){
   int gd = DETECT, gm;
   int nivelesDeRecursividad=7;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   
   vertice a,b,c;
   a.x=250;
   a.y=150;
   b.x=150;
   b.y=350;
   c.x=350;
   c.y=350;
   
   for(int i=0; i<nivelesDeRecursividad; i++){
   	 Dibujar_Sierpinski(a, b, c, i);
   	 getch();
   	 cleardevice();
   }
   
    //Dibujar_Sierpinski(a, b, c, nivelesDeRecursividad);
    getch();
   closegraph();
}
