Algoritmo AccesoUsuarios
	// Validar el acceso a usuarios
	Definir nom_usuario, usuario, contra_usuario, contraseña Como Caracter
	Definir acceso Como Entero
	acceso = 0
	Escribir "CREAR UNA CUENTA"
	Escribir "Defina un nombre de usuario: "
	Leer nom_usuario
	Escribir "Defina una contraseña: "
	Leer contra_usuario
	Limpiar Pantalla
	Mientras acceso <> 1 Hacer
		Escribir "Acceso a Cuenta"
		Escribir "Nombre de ususario"
		Leer usuario
		Escribir "Contraseña"
		Leer contraseña
		Si nom_usuario = usuario Entonces
			Si contra_usuario == contraseña Entonces
				acceso = 1
				Escribir "Acceso permitido"
			SiNo
				Escribir "Contraseña incorrecta. Acceso denegado"
				Escribir "Intente nuevamente"
			FinSi
		SiNo
			Si contra_usuario == contraseña Entonces
				Escribir "Usuario incorrecto. Acceso denegado"
				Escribir "Intente nuevamente"
			SiNo
				Escribir "Datos incorrectos. Acceso denegado"
				Escribir "Intente nuevamente"
			FinSi
		FinSi
	Fin Mientras
FinAlgoritmo
