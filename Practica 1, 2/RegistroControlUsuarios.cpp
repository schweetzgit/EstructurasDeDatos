/*6. Programar un sistema de control de usuarios, considerar la estructura de datos interna compuesta: 
Usuario, que considere registros conformados por idUsuario, login, Password, nombre, primer apellido, 
segundo apellido, e-mail, teléfono, sexo e implementar las funciones que:
	a. Guarde registro (utilizar la estructura externa archivo) (Puntaje: 0.3)
	b. Busque un usuario (Puntaje: 0.3)
	c. Borrar un usuario del archivo (Puntaje: 0.5)
	d. Liste a todos los usuarios almacenado. (Puntaje: 0.3)
	e. Modifique el registro usuario que desee. (Puntaje: 0.5)
	f. Incluir una función main() que muestre menú de opciones que incluya a todas las funciones implementadas en la estructura. (Puntaje: 0.3)
	g. Para entrar al sistema de administración de usuarios validar el acceso solicitando login y password, el cual debe estar 
		almacenado en el archivo entre los registros como root y mac1351 respectivamente.*/
		
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
typedef struct Usuario{
	private:
		int idUsuario; 
		char login[10]; 
		char password[10];
		char nombre[60];
		char apellido1[60];
		char apellido2[60];
		char email[80];
		char telefono[13];
		char sexo;
		char nombreArchivo[120];
	public:
		void validarAcceso(){
			char log[10], pass[10];
			strcpy(login,"root");
			strcpy(password,"mac1351");
			do{
				cout<<"\n Inicio de sesion\n";
				cout<<"\n Login: ";
				fflush(stdin);
				gets(log);
				cout<<" Password: ";
				fflush(stdin);
				gets(pass);
				if(strcmp(log,login) != 0 || strcmp(pass,password) != 0){
					cout<<"\n Login y/o contrasena incorrecta.\n Tecla para continuar...";
					cin.get();
					system("cls");
				}
			}while(strcmp(log,login) != 0 || strcmp(pass,password) != 0);
			cout<<"\n Bienvenido al sistema";
		}
		void leeRutaNombre(){
			cout<<"\n Asegurate de tener una carpeta con ruta c:/borrame";
			cout<<"\n Ingresa: c:/borrame/nombre_del_archivo.txt\n";;
			cout<<"\n Ingresar la ruta y nombre del archivo: ";
			fflush(stdin);
			gets(nombreArchivo);
		}
		void leerUsuario(){
			cout<<"\n Identificador: ";
			cin>>idUsuario;
			cout<<" Nombre: ";
			fflush(stdin);
			gets(nombre);
			cout<<" Primer apellido: ";
			fflush(stdin);
			gets(apellido1);
			cout<<" Segundo apellido: ";
			fflush(stdin);
			gets(apellido2);
			cout<<" E-mail: ";
			fflush(stdin);
			gets(email);
			cout<<" Telefono: ";
			fflush(stdin);
			gets(telefono);
			cout<<" Sexo [M][H]: ";
			fflush(stdin);
			cin>>sexo;
		}
		void imprimeUsuario(){
			cout<<"\n\n Identificador: "<<idUsuario;
			cout<<"\n Nombre: "<<nombre;
			cout<<" Primer apellido: "<<apellido1;
			cout<<" Segundo apellido: "<<apellido2;
			cout<<" E-mail: "<<email;
			cout<<" Telefono: "<<telefono;
			cout<<" Sexo: "<<sexo;
		}
		void guardarRegistro(){
			FILE *archivo;
			archivo = fopen(nombreArchivo,"a");
			system("cls");
			if(archivo == NULL){
				cout<<"\n Error en apertura de archivo\n";
				cin.get();
				return;
			}
			fprintf(archivo,"\n%d", idUsuario);
			fprintf(archivo,"\n%s", nombre);
			fprintf(archivo,"\n%s", apellido1);
			fprintf(archivo,"\n%s", apellido2);
			fprintf(archivo,"\n%s", email);
			fprintf(archivo,"\n%s", telefono);
			fprintf(archivo,"\n%c", sexo);
			cout<<"\n Registro almacenado con exito.\n Tecla para continuar...";
			cin.get();
			fclose(archivo);
		}
		void listarUsuariosAlmacenados(){
			FILE *archivo;
			Usuario aux;
			system("cls");
			archivo = fopen(nombreArchivo,"r");
			if(archivo == NULL){
				cout<<"\n Error en apertura de archivo\n";
				cin.get();
				return;
			}
			cin.get();
			cout<<"\n Usuarios Almacenados";
			while(!feof(archivo)){ 
				fscanf(archivo,"%d\n",&aux.idUsuario);
				fflush(stdin);
				fgets(aux.nombre,60,archivo);
				fgets(aux.apellido1,60,archivo);
				fgets(aux.apellido2,60,archivo);
				fgets(aux.email,80,archivo);
				fgets(aux.telefono,13,archivo);
				fscanf(archivo,"\n%c\n",&aux.sexo);
				aux.imprimeUsuario();
			}
			fclose(archivo);
			cout<<"\n\n Tecla para continuar...";
			cin.get();
		}
		void buscarRegistro(){
			FILE *archivo;
			int idBuscado;
			char resp;
			Usuario aux;
			
			archivo = fopen(nombreArchivo,"r");
			if(archivo == NULL){
				cout<<"\n Error en apertura de archivo.\n";
				cin.get();
				return;
			}
			
			cout<<"\n Ingresar el identificador del usuario a buscar: ";
			cin>>idBuscado;
				
			while(!feof(archivo)){
				fscanf(archivo,"%d\n",&aux.idUsuario);
				fflush(stdin);
				fgets(aux.nombre,60,archivo);
				fgets(aux.apellido1,60,archivo);
				fgets(aux.apellido2,60,archivo);
				fgets(aux.email,80,archivo);
				fgets(aux.telefono,13,archivo);
				fscanf(archivo,"\n%c",&aux.sexo);
					
				if(idBuscado == aux.idUsuario){
					cout<<"\n El registro con identificador "<<aux.idUsuario<<" se ha encontrado.";
					aux.imprimeUsuario();
					cout<<"\n\n Tecla para continuar...";
					cin.get();
					fclose(archivo);
					return;
				}
			}
			cout<<"\n El identificador no se encuentra almacenado.\n Tecla para continuar...";
			cin.get();	
			fclose(archivo);
			return;
		}
		void borrarRegistro(){
			FILE *original;
			FILE *auxiliar;
			Usuario aux;
			int idBorrar;
			int centinela = 0;
		
			original = fopen(nombreArchivo,"r");
			if(original == NULL){
				cout<<"\n Error en apertura de archivo.\n";
				cin.get();
				return;
			}
				
			auxiliar = fopen("c:/borrame/auxiliarUsuario.txt","w");
			if(auxiliar == NULL){
				cout<<"\n Error en apertura de archivo.\n";
				cin.get();
				fclose(original);
				return;
			}
			
			cout<<"\n Borrado registro usuario por identificador.\n";	
			cout<<"\n Ingresar el identificador del registro usuario que desea borrar: ";
			cin>>idBorrar;
				
			while(!feof(original)){
				fscanf(original,"%d\n",&aux.idUsuario);
				fflush(stdin);
				fgets(aux.nombre,60,original);
				fgets(aux.apellido1,60,original);
				fgets(aux.apellido2,60,original);
				fgets(aux.email,80,original);
				fgets(aux.telefono,13,original);
				fscanf(original,"\n%c",&aux.sexo);
				
				if(idBorrar == aux.idUsuario){
					centinela = 1;
					cout<<"\n El registro con identificador "<<aux.idUsuario<<" fue eliminado con exito.\n";
				}
				else{
					fprintf(auxiliar,"%d\n",aux.idUsuario);
					fprintf(auxiliar,"%s",aux.nombre);
					fprintf(auxiliar,"%s",aux.apellido1);
					fprintf(auxiliar,"%s",aux.apellido2);
					fprintf(auxiliar,"%s",aux.email);
					fprintf(auxiliar,"%s",aux.telefono);
					fprintf(auxiliar,"%c",aux.sexo);
				}
			}
		
			fclose(original);
			fclose(auxiliar);
			if(centinela == 0){
				cout<<"\n El registro con identificador "<<idBorrar<<" no se encuentra en la base de datos.\n";
				remove("c:/borrame/auxiliarUsuario.txt");
				return;
			}
			cin.get();
		    remove(nombreArchivo);
			rename("c:/borrame/auxiliarUsuario.txt",nombreArchivo);
		}
		void modificarUsuario(){
			FILE *original;
			FILE *auxiliar;
			Usuario aux;
			int idModificar;
			int centinela = 0;
			char respModifica;
			
			cout<<"\n Modificar registros de usuario.";
			       
			original = fopen(nombreArchivo,"r");
			if(original == NULL){
				cout<<"\n Error en apertura de archivo.\n";
				cin.get();
				return;
			}
			auxiliar = fopen("c:/borrame/auxiliarUsuario.txt","w");
			if(auxiliar == NULL){
				cout<<"\n Error en apertura de archivo.\n";
				cin.get();
				fclose(original);
				return;
			}
			
			printf("\n\n Ingresar el identificador del usuario que desea modificar: ");
			cin>>idModificar;
			
			while(!feof(original)){
				fscanf(original,"%d\n",&aux.idUsuario);
				fflush(stdin);
				fgets(aux.nombre,60,original);
				fgets(aux.apellido1,60,original);
				fgets(aux.apellido2,60,original);
				fgets(aux.email,80,original);
				fgets(aux.telefono,13,original);
				fscanf(original,"\n%c",&aux.sexo);
					
				if(idModificar == aux.idUsuario){
					centinela = 1;
					cout<<"\n Datos actuales";
					aux.imprimeUsuario();
					cout<<"\n\n Ingrese datos";
					aux.leerUsuario();
					fprintf(auxiliar,"\n%d", aux.idUsuario);
					fprintf(auxiliar,"\n%s", aux.nombre);
					fprintf(auxiliar,"\n%s", aux.apellido1);
					fprintf(auxiliar,"\n%s", aux.apellido2);
					fprintf(auxiliar,"\n%s", aux.email);
					fprintf(auxiliar,"\n%s", aux.telefono);
					fprintf(auxiliar,"\n%c", aux.sexo);
					cout<<"\n El registro con identificador "<<aux.idUsuario<<" fue modificado con exito.\n Tecla para continuar...";
					cin.get();  	
				}
				else{
					fprintf(auxiliar,"%d", aux.idUsuario);
					fprintf(auxiliar,"\n%s", aux.nombre);
					fprintf(auxiliar,"\n%s", aux.apellido1);
					fprintf(auxiliar,"\n%s", aux.apellido2);
					fprintf(auxiliar,"\n%s", aux.email);
					fprintf(auxiliar,"\n%s", aux.telefono);
					fprintf(auxiliar,"\n%c", aux.sexo);
				}
			}
			fclose(original);
			fclose(auxiliar);
			
			if(centinela == 0){
				cout<<"\n El registro con identificador "<<idModificar<<" no se encuentra en la base de datos.\n Tecla para continuar...\n";
				remove("c:/borrame/auxiliarUsuario.txt");
				return;
			}	
		    remove(nombreArchivo);
			rename("c:/borrame/auxiliarUsuario.txt",nombreArchivo);
			cin.get();
		}
}user;
main(){
	Usuario us;
	int opc;
	us.validarAcceso();	
	us.leeRutaNombre();
	do{
		cout<<"\n Control de usuarios";
		cout<<"\n 1. Leer un registro de usuario";
		cout<<"\n 2. Guardar registro";
		cout<<"\n 3. Listar usuarios almacenados";
		cout<<"\n 4. Buscar registro";
		cout<<"\n 5. Eliminar registro";
		cout<<"\n 6. Modificar un usuario";
		cout<<"\n 7. Salir";
		cout<<"\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				system("cls");
				cout<<"\n Registro de Usuario\n";
				us.leerUsuario();
				break;
			case 2:
				us.guardarRegistro();
				cin.get();
				break;
			case 3:
				us.listarUsuariosAlmacenados();
				break;
			case 4:
				system("cls");
				us.buscarRegistro();
				break;
			case 5:
				system("cls");
				us.borrarRegistro();
				break;
			case 6: 
				system("cls");
				us.modificarUsuario();
			    break;   
			case 7: 
				cout<<"\n Gracias por usar el programa";
				cin.get();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				cin.get();
		}
	}while(opc!=7);
}
