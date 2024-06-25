#include<iostream>
#include<conio.h>
using namespace std;
typedef struct Persona{
	private:
		int idPersona;
		char nombre[60];
		char apellido1[60];
		char apellido2[60];
		char direccion[80];
		char nombreArchivo[120];
		int edad;
		float talla;
	public:
		void leeRutaNombre(){
			cout<<"\n Ingresar la ruta y nombre del archivo: ";
			// Al dar la ruta es: c:/.../NombreArchivo.extension
			fflush(stdin);
			gets(nombreArchivo);
		}
		void leerPersona(){
			cout<<"\n Lectura de un registro Persona\n";
			cout<<" Identificador: ";
			cin>>idPersona;
			cout<<" Nombre: ";
			fflush(stdin);
			gets(nombre);
			cout<<" Primer apellido: ";
			fflush(stdin);
			gets(apellido1);
			cout<<" Segundo apellido: ";
			fflush(stdin);
			gets(apellido2);
			cout<<" Direccion: ";
			fflush(stdin);
			gets(direccion);
			cout<<" Edad: ";
			cin>>edad;
			cout<<" Talla: ";
			cin>>talla;
		}
		void imprimePersona(){
			cout<<"\n\n Identificador: "<<idPersona;
			cout<<"\n Nombre: "<<nombre;
			cout<<" Primer apellido: "<<apellido1;
			cout<<" Segundo apellido: "<<apellido2;
			cout<<" Direccion: "<<direccion;
			cout<<" Edad: "<<edad;
			cout<<"\n Talla: "<<talla;
		}
		void guardarRegistro(){
			FILE *archivo;
			archivo = fopen(nombreArchivo,"a");
			if(archivo == NULL){
				cout<<"\n Error en apertura de archivo";
				cin.get();
				return;
			}
			fprintf(archivo,"\n %d", idPersona);
			fprintf(archivo,"\n %s", nombre);
			fprintf(archivo,"\n %s", apellido1);
			fprintf(archivo,"\n %s", apellido2);
			fprintf(archivo,"\n %s", direccion);
			fprintf(archivo,"\n %d", edad);
			fprintf(archivo,"\n %f", talla);
			
			cout<<"\n Registro almacenado con exito.\n";
			fclose(archivo);
		}
		void listarPersonasAlmacenadas(){
			FILE *archivo;
			Persona aux;
			archivo = fopen(nombreArchivo,"r");
			if(archivo == NULL){
				cout<<"\n Error en apertura de archivo";
				cin.get();
				return;
			}
			while(!feof(archivo)){
				// fendofile. Verifica si se alcanzo el fin de archivo.
				fscanf(archivo,"%d\n",&aux.idPersona);
				fflush(stdin);
				fgets(aux.nombre,60,archivo);//admiten espacios en blanco
				fgets(aux.apellido1,60,archivo);
				fgets(aux.apellido2,60,archivo);
				fgets(aux.direccion,80,archivo);
				fscanf(archivo,"%d\n",&aux.edad);
				fscanf(archivo,"%f\n",&aux.talla);
				aux.imprimePersona();
			}
			fclose(archivo);
		}
		void buscarRegistro(){
			FILE *archivo;
			int idBuscado;
			struct Persona aux;
			archivo = fopen(nombreArchivo,"r");
			if(archivo == NULL){
				cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
				cin.get();
				return;
			}
			
			cout<<"\n Ingresar el identificador de la persona a buscar: ";
		    cin>>idBuscado;
		    
			while(!feof(archivo)){
				fscanf(archivo,"%d\n",&aux.idPersona);
				fflush(stdin);
				fgets(aux.nombre,60,archivo);
				fgets(aux.apellido1,60,archivo);
				fgets(aux.apellido2,60,archivo);
				fgets(aux.direccion,80,archivo);
				fscanf(archivo,"%d\n",&aux.edad);
				fscanf(archivo,"%f\n",&aux.talla);
			
				if(idBuscado == aux.idPersona){
					cout<<"\n El registro con identificador "<<aux.idPersona<<" se ha encontrado.";
				 	aux.imprimePersona();
				    cin.get();
				    fclose(archivo);
					return;
			    }
			}
			cout<<"\n El registro no se encuentra almacenado.";	
			cin.get();
		    fclose(archivo);
			return;
		}
		void borrarRegistro(){
			FILE *original;
			FILE *auxiliar;
			struct Persona aux;
			int idBorrar;
			int centinela = 0;
		
			cout<<"\n Borrado del registro persona por identificador.";
			original = fopen(nombreArchivo,"r");
			if(original == NULL){
				cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
				cin.get();
				return;
			}
		
			auxiliar = fopen("c:/borrame/auxiliarPersona.txt","w");
			if(auxiliar == NULL){
				cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
				cin.get();
				fclose(original);
				return;
			}
		
			cout<<"\n Ingresar el identificador del registro persona que desea borrar: ";
			cin>>idBorrar;
		
			while(!feof(original)){
				fscanf(original,"%d\n",&aux.idPersona);
				fflush(stdin);
				fgets(aux.nombre,60,original);
				fgets(aux.apellido1,60,original);
				fgets(aux.apellido2,60,original);
				fgets(aux.direccion,80,original);
				fscanf(original,"%d\n",&aux.edad);
				fscanf(original,"%f\n",&aux.talla);
			
				if(idBorrar == aux.idPersona){
					centinela = 1;
					cout<<"\n El registro con identificador "<<aux.idPersona<<" fue eliminado con exito.";
				}
				else{
					fprintf(auxiliar,"%d\n",aux.idPersona);
					fprintf(auxiliar,"%s",aux.nombre);
					fprintf(auxiliar,"%s",aux.apellido1);
					fprintf(auxiliar,"%s",aux.apellido2);
					fprintf(auxiliar,"%s",aux.direccion);
					fprintf(auxiliar,"%d\n",aux.edad);
					fprintf(auxiliar,"%f\n",aux.talla);
				}
			}
			
			fclose(original);
			fclose(auxiliar);
			
			if(centinela == 0){
				cout<<"\n El registro con identificador "<<idBorrar<<" no se encuentra en la base de datos.";
				remove("c:/borrame/auxiliarPersona.txt");
				return;
			}
			//cout<<"\n Revisar los archivos";
			cin.get();
			//elimina el archivo origen
	    	remove(nombreArchivo);
			//Renombrando el archivo auxiliar por el nombre del archivo Origen 
			rename("c:/borrame/auxiliarPersona.txt", nombreArchivo);
		}
		void modificarPersona(){
			FILE *original;
			FILE *auxiliar;
			struct Persona aux;
			int idModificar;
			int centinela = 0;
			char respModifica;
			
			cout<<"\n Modificar registros persona por identificador.";
			       
			original = fopen(nombreArchivo,"r");
			if(original == NULL){
				cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
				cin.get();
				return;
			}
			
			auxiliar = fopen("c:/borrame/auxiliarPersona.txt","w");
			if(auxiliar == NULL){
				cout<<"\n Error en apertura de archivo. \nPulse tecla para continuar";
				cin.get();
				fclose(original);
				return;
			}
			
			printf("\n\n Ingresar el identificador del registro Persona que desea modificar: ");
			cin>>idModificar;
			
			while(!feof(original)){
				fscanf(original,"%d\n",&aux.idPersona);
				fflush(stdin);
				fgets(aux.nombre,60, original);
				fgets(aux.apellido1,60, original);
				fgets(aux.apellido2,60, original);
				fgets(aux.direccion,80, original);
				fscanf(original ,"%d\n",&aux.edad);
				fscanf(original,"%f\n",&aux.talla);
					
				if(idModificar == aux.idPersona){
					centinela = 1;
					cout<<" Desea modificar el identificador actual "<<aux.idPersona<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						cin>>aux.idPersona;
					}
					//cout<<" El registro con identificador "<<aux.idPersona<<" fue modificado con exito.";
				
					cout<<"\n Desea modificar el nombre actual "<<aux.nombre<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						fflush(stdin);
						gets(aux.nombre);
					}
					
					cout<<"\n Desea modificar el primer apellido actual: "<<aux.apellido1<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						fflush(stdin);
						gets(aux.apellido1);
					}
					
					cout<<"\n Desea modificar el segundo apellido actual: "<<aux.apellido2<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						fflush(stdin);
						gets(aux.apellido2);
					}
					
					cout<<"\n Desea modificar la direccion actual: "<<aux.direccion<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						fflush(stdin);
						gets(aux.direccion);
					}
					
					cout<<"\n Desea modificar la edad actual "<<aux.edad<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						cin>>aux.edad;
					}
					
					cout<<"\n Desea modificar la talla actual "<<aux.talla<<" [s->Si]: ";
					cin>>respModifica;
					if(tolower(respModifica) == 's'){
						cout<<" Captura el nuevo dato: ";
						cin>>aux.talla;
					}
					fprintf(auxiliar,"%d\n",aux.idPersona);
					fprintf(auxiliar,"%s",aux.nombre);
					fprintf(auxiliar,"%s",aux.apellido1);
					fprintf(auxiliar,"\n%s",aux.apellido2);
					fprintf(auxiliar,"\n%s",aux.direccion);
					fprintf(auxiliar,"\n%d\n",aux.edad);
					fprintf(auxiliar,"%f\n",aux.talla);
				}
				else{
					fprintf(auxiliar,"%d\n",aux.idPersona);
					fprintf(auxiliar,"%s",aux.nombre);
					fprintf(auxiliar,"%s",aux.apellido1);
					fprintf(auxiliar,"%s",aux.apellido2);
					fprintf(auxiliar,"%s",aux.direccion);
					fprintf(auxiliar,"%d\n",aux.edad);
					fprintf(auxiliar,"%f\n",aux.talla);
				}
			}
			fclose(original);
			fclose(auxiliar);
			
			if(centinela == 0){
				cout<<"\n El registro con identificador "<<idModificar<<" no se encuentra en la base de datos.";
				remove("c:/borrame/auxiliarPersona.txt");
				return;
			}
			//cout<<"\n Revisar los Archivos";
			cin.get();
			//elimina el archivo origen
		    remove(nombreArchivo);
		
			//Renombrando el archivo auxiliar por el nombre del archivo Origen 
			rename("c:/borrame/auxiliarPersona.txt", nombreArchivo);
			cin.get();
		}
}person;

main(){
	int opc;
	person personaX;
	personaX.leeRutaNombre();
	do{
		cout<<"\n\n 1. Leer un registro";
		cout<<"\n 2. Imprimir un registro";
		cout<<"\n 3. Guardar registro";
		cout<<"\n 4. Listar personas almacenadas";
		cout<<"\n 5. Buscar registro";
		cout<<"\n 6. Eliminar registro";
		cout<<"\n 7. Modificar un registro";
		cout<<"\n 8. Salir";
		cout<<"\n Elija una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				personaX.leerPersona();
				break;
			case 2:
				personaX.imprimePersona();
				break;
			case 3:
				personaX.guardarRegistro();
				break;
			case 4:
				personaX.listarPersonasAlmacenadas();
				break;
			case 5:
				personaX.buscarRegistro();
				break;
			case 6:
				personaX.borrarRegistro();
				break;
			case 7: 
				personaX.modificarPersona();
			    break;   
			case 8: 
				cout<<"\n Hasta la vista";
				getch();
				break;
			default: 
				cout<<"\n Opcion incorrecta. Vuelva a elegir";			
				getch();
		}
	}while(opc!=8);
	cout<<"\n El espacio de memoria que ocupa una variable de tipo estructura persona es: "<<sizeof(person)<<endl;
	getch();
}
