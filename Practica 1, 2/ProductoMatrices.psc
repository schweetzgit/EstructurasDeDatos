Funcion leerMatriz(Mat Por Referencia,filas,columnas)
	Para i<-1 Hasta filas Hacer
		Para j<-1 Hasta columnas Hacer
			Escribir '[',i,',',j,']: '
			Leer Mat[i,j]
		FinPara
	FinPara
FinFuncion

Funcion imprimirMatriz(Mat Por Referencia,filas,columnas)
	Para i<-1 Hasta filas Hacer
		Para j<-1 Hasta columnas Hacer
			Escribir Mat[i,j],' '
		FinPara
		Escribir ' '
	FinPara
FinFuncion

Funcion productoMatriz(C Por Referencia A,B,n1,m2,n2)
	Para i<-1 Hasta n1 Hacer
		Para j<-1 Hasta m2 Hacer
			C[i,j]<-0
			Para k<-1 Hasta n2 Hacer
				C[i,j]<-C[i,j]+(A[i,k]*B[k,j])
			FinPara
		FinPara
	FinPara
FinFuncion

Algoritmo ProductoMatrices
	Definir n1,m1,n2,m2 Como Entero
	Definir resp Como Caracter
	Repetir
		Escribir 'Filas de la matriz A: '
		Leer n1
		Escribir 'Columnas de la matriz A: '
		Leer m1
		Escribir 'Filas de la matriz B: '
		Leer n2
		Escribir 'Columnas de la matriz B: '
		Leer m2
		Dimension A[n1,m1],B[n2,m2],C[n1,m2]
		Si n1<1 O m1<1 O n2<1 O m2<1 O m1<>n2 Entonces
			Escribir 'Las matrices no se pueden multiplicar.'
		SiNo
			Escribir 'Matriz A'
			leerMatriz(A,n1,m1)
			Escribir 'Matriz B'
			leerMatriz(B,n2,m2)
			Escribir 'Matriz A'
			imprimirMatriz(A,n1,m1)
			Escribir 'Matriz B'
			imprimirMatriz(B,n2,m2)
			Escribir 'Multiplicación:'
			productoMatriz(C,A,B,n1,m2,n2)
			imprimirMatriz(C,n1,m2)
		FinSi
		Escribir '¿Desea repetir el proceso? [s->Si]: '
		Leer resp
		Borrar Pantalla
	Hasta Que resp<>'s' O resp<>'S'
FinAlgoritmo
