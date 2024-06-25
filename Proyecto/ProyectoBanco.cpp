/*Proyecto final: simular las acciones y movimientos que suceden en las cajas
de una banco, o casetas (1 a 5 cajas), utilizando el concepto de cola o fila.
~Colunga Aguilar Alma Carolina~*/
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

void tiempoAtencion(int);
void delay(int);

typedef struct fila1{
	int turn;
	struct fila1 *ptr;
}f1;
typedef struct fila2{
	int turn;
	struct fila2 *ptr;
}f2;
typedef struct fila3{
	int turn;
	struct fila3 *ptr;
}f3;
typedef struct fila4{
	int turn;
	struct fila4 *ptr;
}f4;
typedef struct fila5{
	int turn;
	struct fila5 *ptr;
}f5;

f1 *in1 = NULL;
f2 *in2 = NULL;
f3 *in3 = NULL;
f4 *in4 = NULL;
f5 *in5 = NULL;

void insertaFila1(int turno){
	f1 *aux = in1;
	f1 *nvo;
	nvo = (f1 *) malloc(sizeof(f1));
	nvo->ptr = NULL;
	nvo->turn = turno;
	if(in1 == NULL){
		in1 = nvo;
		return;
	}
	while(aux->ptr != NULL){
		aux = aux->ptr;
	}
	 aux->ptr = nvo;
}
void insertaFila2(int turno){
	f2 *aux = in2;
	f2 *nvo;
	nvo = (f2 *) malloc(sizeof(f2));
	nvo->ptr = NULL;
	nvo->turn = turno;
	if(in2 == NULL){
		in2 = nvo;
		return;
	}
	while(aux->ptr != NULL){
		aux = aux->ptr;
	}
	 aux->ptr = nvo;
}
void insertaFila3(int turno){
	f3 *aux = in3;
	f3 *nvo;
	nvo = (f3 *) malloc(sizeof(f3));
	nvo->ptr = NULL;
	nvo->turn = turno;
	if(in3 == NULL){
		in3 = nvo;
		return;
	}
	while(aux->ptr != NULL){
		aux = aux->ptr;
	}
	 aux->ptr = nvo;
}
void insertaFila4(int turno){
	f4 *aux = in4;
	f4 *nvo;
	nvo = (f4 *) malloc(sizeof(f4));
	nvo->ptr = NULL;
	nvo->turn = turno;
	if(in4 == NULL){
		in4 = nvo;
		return;
	}
	while(aux->ptr != NULL){
		aux = aux->ptr;
	}
	 aux->ptr = nvo;
}
void insertaFila5(int turno){
	f5 *aux = in5;
	f5 *nvo;
	nvo = (f5 *) malloc(sizeof(f5));
	nvo->ptr = NULL;
	nvo->turn = turno;
	if(in5 == NULL){
		in5 = nvo;
		return;
	}
	while(aux->ptr != NULL){
		aux = aux->ptr;
	}
	 aux->ptr = nvo;
}

void imprimirNodosF1(){
	f1 *aux1 = in1;
	cout<<"\n\n Caja 1 | ";
	if(in1 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		cout<<" ["<<aux1->turn<<"] <--";
		aux1 = aux1->ptr;
	}
	cout<<"\n\n Pulse tecla para continuar";
	//getch();
}
void imprimirNodosF2(){
	f2 *aux1 = in2;
	cout<<"\n\n Caja 2 | ";
	if(in2 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		cout<<" ["<<aux1->turn<<"] <--";
		aux1 = aux1->ptr;
	}
	cout<<"\n\n Pulse tecla para continuar";
	//getch();
}
void imprimirNodosF3(){
	f3 *aux1 = in3;
	cout<<"\n\n Caja 3 | ";
	if(in3 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		cout<<" ["<<aux1->turn<<"] <--";
		aux1 = aux1->ptr;
	}
	cout<<"\n\n Pulse tecla para continuar";
	//getch();
}
void imprimirNodosF4(){
	f4 *aux1 = in4;
	cout<<"\n\n Caja 4 | ";
	if(in4 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		cout<<" ["<<aux1->turn<<"] <--";
		aux1 = aux1->ptr;
	}
	cout<<"\n\n Pulse tecla para continuar";
	//getch();
}
void imprimirNodosF5(){
	f5 *aux1 = in5;
	cout<<"\n\n Caja 5 | ";
	if(in5 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		cout<<" ["<<aux1->turn<<"] <--";
		aux1 = aux1->ptr;
	}
	cout<<"\n\n Pulse tecla para continuar";
	//getch();
}

void eliminarElementoF1(int numTurno){
	f1 *aux1 = in1;
	if(in1 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in1 = aux1->ptr;
	cout<<"\n Turno "<<aux1->turn<<" ha salido de la fila 1.";
	free(aux1);
}
void eliminarElementoF2(int numTurno){
	f2 *aux1 = in2;
	if(in2 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in2 = aux1->ptr;
	cout<<"\n Turno "<<aux1->turn<<" ha salido de la fila 2.";
	free(aux1);
}
void eliminarElementoF3(int numTurno){
	f3 *aux1 = in3;
	if(in3 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in3 = aux1->ptr;
	cout<<"\n Turno "<<aux1->turn<<" ha salido de la fila 3.";
	free(aux1);
}
void eliminarElementoF4(int numTurno){
	f4 *aux1 = in4;
	if(in4 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in4 = aux1->ptr;
	cout<<"\n Turno "<<aux1->turn<<" ha salido de la fila 4.";
	free(aux1);
}
void eliminarElementoF5(int numTurno){
	f5 *aux1 = in5;
	if(in5 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in5 = aux1->ptr;
	cout<<"\n Turno "<<aux1->turn<<" ha salido de la fila 5.";
	free(aux1);
}

void atenderF1(){
	f1 *aux1 = in1;
	if(in1 == NULL){
		cout<<"\n Fila 1 vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in1 = aux1->ptr;
	cout<<"\n Pase a la caja 1\n Cliente "<<aux1->turn<<" es su turno\n\n En atencion...";
	delay(5);
	tiempoAtencion(aux1->turn);
	free(aux1);
}
void atenderF2(){
	f2 *aux1 = in2;
	if(in2 == NULL){
		cout<<"\n Fila 2 vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in2 = aux1->ptr;
	cout<<"\n Pase a la caja 2\n Cliente "<<aux1->turn<<" es su turno\n\n En atencion...";
	delay(5);
	tiempoAtencion(aux1->turn);
	free(aux1);
}
void atenderF3(){
	f3 *aux1 = in3;
	if(in3 == NULL){
		cout<<"\n Fila 3 vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in3 = aux1->ptr;
	cout<<"\n Pase a la caja 3\n Cliente "<<aux1->turn<<" es su turno\n\n En atencion...";
	delay(5);
	tiempoAtencion(aux1->turn);
	free(aux1);
}
void atenderF4(){
	f4 *aux1 = in4;
	if(in4 == NULL){
		cout<<"\n Fila 4 vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in4 = aux1->ptr;
	cout<<"\n Pase a la caja 4\n Cliente "<<aux1->turn<<" es su turno\n\n En atencion...";
	delay(5);
	tiempoAtencion(aux1->turn);
	free(aux1);
}
void atenderF5(){
	f5 *aux1 = in5;
	if(in5 == NULL){
		cout<<"\n Fila 5 vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	in5 = aux1->ptr;
	cout<<"\n Pase a la caja 5\n Cliente "<<aux1->turn<<" es su turno\n\n En atencion...";
	delay(5);
	tiempoAtencion(aux1->turn);
	free(aux1);
}

void eliminaTodaF1(){
	f1 *aux1 = in1;
	if(in1 == NULL){
		cout<<"\n Fila 1 vacia";
		return;
	}
	in1 = aux1->ptr;
	cout<<"\n Fila 1 cerrada. Se han eliminado los turnos existentes";	
	free(aux1);
}
void eliminaTodaF2(){
	f2 *aux1 = in2;
	if(in2 == NULL){
		cout<<"\n Fila 2 vacia";
		return;
	}
	in2 = aux1->ptr;
	cout<<"\n Fila 2 cerrada. Se han eliminado los turnos existentes";	
	free(aux1);
}
void eliminaTodaF3(){
	f3 *aux1 = in3;
	if(in3 == NULL){
		cout<<"\n Fila 3 vacia";
		return;
	}
	in3 = aux1->ptr;
	cout<<"\n Fila 3 cerrada. Se han eliminado los turnos existentes";	
	free(aux1);
}
void eliminaTodaF4(){
	f4 *aux1 = in4;
	if(in2 == NULL){
		cout<<"\n Fila 4 vacia";
		return;
	}
	in4 = aux1->ptr;
	cout<<"\n Fila 4 cerrada. Se han eliminado los turnos existentes";	
	free(aux1);
}
void eliminaTodaF5(){
	f5 *aux1 = in5;
	if(in5 == NULL){
		cout<<"\n Fila 5 vacia";
		return;
	}
	in5 = aux1->ptr;
	cout<<"\n Fila 5 cerrada. Se han eliminado los turnos existentes";	
	free(aux1);
}
void borraFilas(){
	eliminaTodaF1();		
	eliminaTodaF2();
	eliminaTodaF3();
	eliminaTodaF4();
	eliminaTodaF5();
}

void buscarEnF1(int buscado){
	f1 *aux1 = in1;
	int posicion = 1, centinela = 0;
	cout<<endl;
	if(in1 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(buscado == aux1->turn){
			cout<<" El Turno "<<buscado<< " se encuentra en la posicion "<<posicion<<" de la fila 1";
			cout<<"\n Pulse tecla para continuar";
			centinela = 1;		
		}
		aux1 = aux1->ptr;
		posicion++;
	}
	if(centinela == 0){
		cout<<" El turno "<<buscado<< " NO se encuentra en la fila 1\n Pulse tecla para continuar";
	}
	getch();
}
void buscarEnF2(int buscado){
	f2 *aux1 = in2;
	int posicion = 1, centinela = 0;
	cout<<endl;
	if(in2 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(buscado == aux1->turn){
			cout<<" El Turno "<<buscado<< " se encuentra en la posicion "<<posicion<<" de la fila 2";
			cout<<"\n Pulse tecla para continuar";
			centinela = 1;		
		}
		aux1 = aux1->ptr;
		posicion++;
	}
	if(centinela == 0){
		cout<<" El turno "<<buscado<< " NO se encuentra en la fila 2\n Pulse tecla para continuar";
	}
	getch();
}
void buscarEnF3(int buscado){
	f3 *aux1 = in3;
	int posicion = 1, centinela = 0;
	cout<<endl;
	if(in3 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(buscado == aux1->turn){
			cout<<" El Turno "<<buscado<< " se encuentra en la posicion "<<posicion<<" de la fila 3";
			cout<<"\n Pulse tecla para continuar\n.";
			centinela = 1;		
		}
		aux1 = aux1->ptr;
		posicion++;
	}
	if(centinela == 0){
		cout<<" El turno "<<buscado<< " NO se encuentra en la fila 3\n Pulse tecla para continuar";
	}
	getch();
}
void buscarEnF4(int buscado){
	f4 *aux1 = in4;
	int posicion = 1, centinela = 0;
	cout<<endl;
	if(in4 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(buscado == aux1->turn){
			cout<<" El Turno "<<buscado<< " se encuentra en la posicion "<<posicion<<" de la fila 4";
			cout<<"\n Pulse tecla para continuar";
			centinela = 1;		
		}
		aux1 = aux1->ptr;
		posicion++;
	}
	if(centinela == 0){
		cout<<" El turno "<<buscado<< " NO se encuentra en la fila 4\n Pulse tecla para continuar";
	}
	getch();
}
void buscarEnF5(int buscado){
	f5 *aux1 = in5;
	int posicion = 1, centinela = 0;
	cout<<endl;
	if(in5 == NULL){
		cout<<"\n Fila vacia";
		cout<<"\n Pulse tecla para continuar";
		getch();
		return;
	}
	while(aux1 != NULL){
		if(buscado == aux1->turn){
			cout<<" El Turno "<<buscado<< " se encuentra en la posicion "<<posicion<<" de la fila 5";
			cout<<"\n Pulse tecla para continuar";
			centinela = 1;		
		}
		aux1 = aux1->ptr;
		posicion++;
	}
	if(centinela == 0){
		cout<<" El turno "<<buscado<< " NO se encuentra en la fila 5\n Pulse tecla para continuar";
	}
	getch();
}

bool checkturno(int turno, int numeros[], int tam){
	bool detener = false;
    for(int i = 0; (i < tam && detener == false); i++)
        if (turno == numeros[i])
        	return true;
    return false;
}
int asignarTurno1(){
	int turno, min = 1, max = 25, tam = 25, numeros[25];
    for(int i = 0; i < 1; i++){
   		do{
   			srand(time(NULL));
		    turno = min+rand()%(max-min+1);
		}while(checkturno(turno,numeros,tam));
		numeros[i] = turno;
		return turno;
	}
}
int asignarTurno2(){
	int turno, min = 1, max = 20, tam = 20, numeros[20];
    for(int i = 0; i < 1; i++){
   		do{
   			srand(time(NULL));
		    turno = min+rand()%(max-min+1);
		}while(checkturno(turno,numeros,tam));
		numeros[i] = turno;
		return turno;
	}
}

void delay(int secs){
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
void tiempoAprox(int turno){
	int tiempo = 1 + rand()%10, tiempo2 = 1 + rand()%15, tiempo3 = 1 + rand()%25;
	if(turno <= 10) cout<<"\n Tiempo aproximado de espera: "<<tiempo<<" minutos";
	else if(turno > 10 && turno <= 20) cout<<"\n Tiempo aproximado de espera: "<<tiempo2<<" minutos";
	else if(turno > 20 && turno <= 25)cout<<"\n Tiempo aproximado de espera: "<<tiempo3<<" minutos";
}
void tiempoAtencion(int turno){
	int tiempo = 1 + rand()%20, tiempo2 = 1 + rand()%10;
	int tiempo3 = 1 + rand()%5, tiempo4 = 1 + rand()%15;
	if(turno <= 5)
		cout<<"\n Tiempo de atencion "<<tiempo<<" minutos";
	else if(turno > 6 && turno <= 10)
		cout<<"\n Tiempo de atencion: "<<tiempo2<<" minutos";
	else if(turno > 11 && turno <= 15)
		cout<<"\n Tiempo de atencion: "<<tiempo3<<" minutos";
	else if(turno > 16 && turno <= 25)
		cout<<"\n Tiempo de atencion: "<<tiempo4<<" minutos";
	cout<<"\n\n Gracias por visitar Banco Eunhaeng";
	delay(2);
}
		
typedef struct Empleado{
	private:
		char login1[10];
		char login2[10];
		char login3[10];
		char login4[10];
		char password1[10];
		char password2[10];
		char password3[10];
		char password4[10];
	public:
		void validarAcceso(){
			char log[10], pass[10];
			strcpy(login1,"Carolina");
			strcpy(login2,"Lina");
			strcpy(login3,"Banco2021");
			strcpy(login4,"login");
			strcpy(password1,"123");
			strcpy(password2,"annyeong");
			strcpy(password3,"ed1351");
			strcpy(password4,"password");
			do{
				cout<<"\n *** Bienvenido a Banco Eunhaeng ***";
				cout<<"\n\n Ingrese claves de acceso\n";	
				cout<<"\n Usuario: ";
				fflush(stdin);
				gets(log);
				fflush(stdin);
				cout<<" Password: ";
				fflush(stdin);
				gets(pass);
				fflush(stdin);
				if((strcmp(log,login1) != 0 || strcmp(pass,password1) != 0) && (strcmp(log,login2) != 0 || strcmp(pass,password2) != 0) && (strcmp(log,login3) != 0 || strcmp(pass,password3) != 0) && (strcmp(log,login4) != 0 || strcmp(pass,password4) != 0)){
					cout<<"\n Login y/o contrasena incorrecta.\n Pulse tecla para continuar.";
					cin.get();
					system("cls");
				}
			}while((strcmp(log,login1) != 0 || strcmp(pass,password1) != 0) && (strcmp(log,login2) != 0 || strcmp(pass,password2) != 0) && (strcmp(log,login3) != 0 || strcmp(pass,password3) != 0) && (strcmp(log,login4) != 0 || strcmp(pass,password4) != 0));
			cout<<"\n --> Acceso autorizado\n Pulse tecla para continuar --> ";
			cin.get();
		}
}worker;

class Cliente{
	private:
		float monto1, monto2;
		float monto3, monto4;
		char cuenta[12], cuenta1[12], cuenta2[12];
		char cuenta3[12], cuenta4[12];
		int pin, pin1, pin2, pin3, pin4;
	public:
		Cliente();
		void leerCuenta();
		void leerCuentaPin();
		void depositar();
		void retirar();
		void getSaldo();
		void datosBasicos();
};
Cliente::Cliente(){ 
	strcpy(cuenta1,"00123456789");
	strcpy(cuenta2,"00223456789");
	strcpy(cuenta3,"00323456789");
	strcpy(cuenta4,"00423456789");
	monto1 = 2000;
	monto2 = 3750;
	monto3 = 520;
	monto4 = 140;
	pin1 = 1234;
	pin2 = 2234;
	pin3 = 3324;
	pin4 = 4424; 
}
void Cliente::leerCuenta(){
	do{
		system("cls");
		printf("\n --- Depositar ---\n");
		printf("\n Cuenta: (11 digitos): ");
		fflush(stdin);
		gets(cuenta);
		if((strcmp(cuenta,cuenta1) != 0) && (strcmp(cuenta,cuenta2) != 0) && (strcmp(cuenta,cuenta3) != 0) && (strcmp(cuenta,cuenta4) != 0)){
			cout<<"\n La cuenta no existe";
			getch();
			system("cls");
		}
	}while((strcmp(cuenta,cuenta1) != 0) && (strcmp(cuenta,cuenta2) != 0) && (strcmp(cuenta,cuenta3) != 0) && (strcmp(cuenta,cuenta4) != 0));
}
void Cliente::leerCuentaPin(){
	do{
		printf("\n Cuenta (11 digitos): ");
		fflush(stdin);
		gets(cuenta);
		printf(" Ingrese su PIN: ");
		cin>>pin;
		if((strcmp(cuenta,cuenta1) != 0 || pin != pin1) && (strcmp(cuenta,cuenta2) != 0 || pin != pin2) && (strcmp(cuenta,cuenta3) != 0 || pin != pin3) && (strcmp(cuenta,cuenta4) != 0 || pin != pin4)){
			cout<<"\n PIN o cuenta invalidos";
			getch();
			system("cls");
		}
	}while((strcmp(cuenta,cuenta1) != 0 || pin != pin1) && (strcmp(cuenta,cuenta2) != 0 || pin != pin2) && (strcmp(cuenta,cuenta3) != 0 || pin != pin3) && (strcmp(cuenta,cuenta4) != 0 || pin != pin4));
}
void Cliente::depositar(){
	float monto = 0;
	float udi = 3000, udiFinal;
	leerCuenta();
	printf("\n Ingrese monto: ");
	cin>>monto;
	udiFinal = monto*7.02;
	if(udiFinal > udi){
		cout<<"\n El monto excede el limite de UDIS";
		cout<<"\n Limite: "<<udi<<" UDIS";
		getch();
	}
	else{
		if(strcmp(cuenta,cuenta1) == 0) monto1 += monto;
		else if(strcmp(cuenta,cuenta2) == 0) monto2 += monto;
		else if(strcmp(cuenta,cuenta3) == 0) monto3 += monto;
		else if(strcmp(cuenta,cuenta4) == 0) monto4 += monto;
		cout<<"\n Se han depositado $"<<monto<<" a la cuenta "<<cuenta;
		cout<<"\n\n Pulse tecla para continuar.";
		getch();
	}
}
void Cliente::retirar(){
	float monto = 0;
	system("cls");
	printf("\n --- Retirar ---\n");
	leerCuentaPin();
	printf("\n Ingrese monto a retirar: ");
	cin>>monto;
	if(strcmp(cuenta,cuenta1) == 0){
		if(monto1 < monto){
			cout<<"\n No cuenta con los suficientes fondos para retirar la cantidad deseada";
			cout<<"\n Cuenta con $ "<<monto1<<" en su cuenta";
		}
		else{
			monto1 -= monto;
			cout<<"\n Monto retirado\n Tiene $ "<<monto1<<" en su cuenta";
		}
	} 
	else if(strcmp(cuenta,cuenta2) == 0){
		if(monto > monto2){
			cout<<"\n No cuenta con los suficientes fondos para retirar la cantidad deseada";
			cout<<"\n Cuenta con $ "<<monto2<<" en su cuenta";
		}
		else{
			monto2 =- monto;
			cout<<"\n Monto retirado\n Tiene $ "<<monto2<<" en su cuenta";
		}
	}
	else if(strcmp(cuenta,cuenta3) == 0){
		if(monto > monto3){
			cout<<"\n No cuenta con los suficientes fondos para retirar la cantidad deseada";
			cout<<"\n Cuenta con $ "<<monto3<<" en su cuenta";
		}
		else{
			monto3 =- monto;
			cout<<"\n Monto retirado\n Tiene $ "<<monto3<<" en su cuenta";
		}
	}
	else if(strcmp(cuenta,cuenta4) == 0){
		if(monto > monto4){
			cout<<"\n No cuenta con los suficientes fondos para retirar la cantidad deseada";
			cout<<"\n Cuenta con $ "<<monto4<<" en su cuenta";
		}
		else{
			monto4 =- monto;
			cout<<"\n Monto retirado\n Tiene $ "<<monto4<<" en su cuenta";
		}
	}	
	cout<<"\n\n Pulse tecla para continuar.";
	getch();
}
void Cliente::getSaldo(){
	system("cls");
	printf("\n --- Consultar Fondos ---\n");
	leerCuentaPin();
	if(strcmp(cuenta,cuenta1) == 0) cout<<"\n Tiene $ "<<monto1<<" en su cuenta";	
	else if(strcmp(cuenta,cuenta2) == 0) cout<<"\n Tiene $ "<<monto2<<" en su cuenta";		
	else if(strcmp(cuenta,cuenta3) == 0) cout<<"\n Tiene $ "<<monto3<<" en su cuenta";		
	else if(strcmp(cuenta,cuenta4) == 0) cout<<"\n Tiene $ "<<monto4<<" en su cuenta";
	cout<<"\n\n Pulse tecla para continuar.";		
	getch();
}

main(){
	time_t timeIn, timeFn;
	srand(time(NULL));
	timeIn = time(NULL);
	worker empleado;
	Cliente persona;
	int opc1, opc2, opc3, nvoturno, fila, filaAtender, numFila, numTurno, resp;
	int turno1, turno2, turno;
	empleado.validarAcceso();
	
	do{
	    system("cls");
		printf("\n ~~~ Banco Eunhaeng ~~~\n");
		printf("\n 1. Atencion personal (filas)");
		printf("\n 2. Depositar");
		printf("\n 3. Retirar");
		printf("\n 4. Saldo");
		printf("\n 5. Salir");
		printf("\n\n Seleccione: ");
		scanf("%d",&opc1);
		switch(opc1){
			case 1:
	    		do{
		    		turno1 = asignarTurno1();
		    		turno2 = asignarTurno2();
		    		turno = 1 + rand() % 20;
		    		fila = 1 + rand() % 5;
					filaAtender = 1 + rand() % 5;
					system("cls");
					printf("\n ~~~ Filas. Banco Eunhaeng ~~~\n");
					printf("\n 1) Obtener turno y caja");
					printf("\n 2) Salir de la fila");
					printf("\n 3) Ver filas");
					printf("\n 4) Atender cliente");
					printf("\n 5) Buscar turno");
					printf("\n 6) Regresar");
					printf("\n 7) Salir");
					printf("\n\n Elija opcion: ");
					scanf("%d",&opc2);
					switch(opc2){
						case 1:
							printf("\n Su turno corresponde ");
							cout<<"\n Fila: "<<fila;
							if (fila == 1){
								cout<<"\n Turno: "<<turno1;
								insertaFila1(turno1);
								tiempoAprox(turno1);
								imprimirNodosF1();
							}
							else if (fila == 2){
								cout<<"\n Turno: "<<turno2;
								insertaFila2(turno2);
								tiempoAprox(turno2);
								imprimirNodosF2();
							} 
							else if (fila == 3){
								cout<<"\n Turno: "<<turno;
								insertaFila3(turno);
								tiempoAprox(turno);
								imprimirNodosF3();
							} 
							else if (fila == 4){
								cout<<"\n Turno: "<<turno;
								insertaFila4(turno);
								tiempoAprox(turno);
								imprimirNodosF4();
							} 
							else if (fila == 5){
								cout<<"\n Turno: "<<turno;
								insertaFila5(turno);	
								tiempoAprox(turno);
								imprimirNodosF5();
							} 
							getch();
							break;
						case 2:
							cout<<"\n Escriba su numero de fila: ";
							cin>>numFila;
							if (numFila == 1) eliminarElementoF1(numTurno);
							else if (numFila == 2) eliminarElementoF2(numTurno);
							else if (numFila == 3) eliminarElementoF3(numTurno);
							else if (numFila == 4) eliminarElementoF4(numTurno);
							else if (numFila == 5) eliminarElementoF5(numTurno);
							else{
								cout<<"\n La fila no existe.\n Pulse tecla para continuar";
								getch();
							}
							break;
						case 3: 
							imprimirNodosF1();
							imprimirNodosF2();
							imprimirNodosF3();
							imprimirNodosF4();
							imprimirNodosF5();
							break;
						case 4:
							system("cls");
							printf("\n ~~~ Atencion ~~~\n");
							if(filaAtender == 1) atenderF1();
							else if(filaAtender == 2) atenderF2();
							else if(filaAtender == 3) atenderF3();
							else if(filaAtender == 4) atenderF4();
							else if(filaAtender == 5) atenderF5();
							printf("\n\n 1) Regresar");
							printf("\n 2) Salir");
							printf("\n Seleccione: ");
							cin>>opc3;
							switch(opc3){
								case 1:
									break;
								case 2:
									timeFn = time(NULL);
									system("cls");
									printf("\n ~~~ Banco Eunhaeng ~~~\n");
									borraFilas();
									printf("\n\n Fecha de entrada. %s",asctime(localtime(&timeIn)));
									printf(" Fecha de salida. %s",asctime(localtime(&timeFn)));
									printf("\n Tiempo de permanencia. %.2f minutos\n",difftime(timeFn,timeIn)/60);
									exit(0);			
									break;
								default:
									printf("\n Opcion incorrecta.\n Pulse tecla para continuar.");
									getch();
									break;
							}
							break;
						case 5:	
							cout<<"\n Escriba su numero de fila: ";
							cin>>numFila;
							cout<<" Escriba turno a buscar: ";
							cin>>nvoturno;
							if (numFila == 1) buscarEnF1(nvoturno);
							else if (numFila == 2) buscarEnF2(nvoturno);
							else if (numFila == 3) buscarEnF3(nvoturno);
							else if (numFila == 4) buscarEnF4(nvoturno);
							else if (numFila == 5) buscarEnF5(nvoturno);
							else{
								cout<<"\n La fila no existe.\n Pulse tecla para continuar";
								getch();
							} 
							break;			
						case 6:
							
							break;
						case 7:
							timeFn = time(NULL);
							system("cls");
							printf("\n ~~~ Banco Eunhaeng ~~~\n");
							borraFilas();
							printf("\n\n Fecha de entrada. %s",asctime(localtime(&timeIn)));
							printf(" Fecha de salida. %s",asctime(localtime(&timeFn)));
							printf("\n Tiempo de permanencia. %.2f minutos\n",difftime(timeFn,timeIn)/60);
							exit(0);
							break;
						default:
							printf("\n Opcion incorrecta.\n Pulse tecla para continuar.");
							getch();
							break;
					} 
					if (opc2 == 2){
						printf("\n\n %cSalir del sistema? No->[0], Si->[1]: ",168);
						cin>>resp;
						if(resp == 1){
							timeFn = time(NULL);
							system("cls");
							printf("\n ~~~ Banco Eunhaeng ~~~\n");
							borraFilas();
							printf("\n\n Fecha de entrada. %s",asctime(localtime(&timeIn)));
							printf(" Fecha de salida. %s",asctime(localtime(&timeFn)));
							printf("\n Tiempo de permanencia. %.2f minutos\n",difftime(timeFn,timeIn)/60);
							exit(0);
						}
					}
				}while(opc2 != 6);
				break;
			case 2:
				persona.depositar();
				break;
			case 3:
				persona.retirar();
				break;
			case 4:
				persona.getSaldo();				
				break;
			case 5:
				timeFn = time(NULL);
				system("cls");
				printf("\n ~~~ Banco Eunhaeng ~~~\n");
				borraFilas();
				printf("\n\n Fecha de entrada. %s",asctime(localtime(&timeIn)));
				printf(" Fecha de salida. %s",asctime(localtime(&timeFn)));
				printf("\n Tiempo de permanencia. %.2f minutos\n",difftime(timeFn,timeIn)/60);
				exit(0);			
				break;
			default:
				printf("\n Opcion incorrecta.\n Pulse tecla para continuar.");
				getch();
				break;	
		}
	}while(opc1 != 6);
}
