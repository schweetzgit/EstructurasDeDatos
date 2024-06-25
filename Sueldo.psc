Proceso EMPRESAtal
	Escribir 'Calcular sueldo de un trabajador';
	Escribir 'Que tipo de trabajador desea saber su sueldo';
	Escribir '1...GERENTE';
	Escribir '4...SECRETARIO';
	Escribir '2...OBRERO';
	Escribir '5...TECNICO';
	Escribir '6...CONSERGUE';
	Escribir '7...PASANTE';
	Escribir '8...JEFE REGIONAL';
	Leer A;
	Segun A  Hacer
		1:
			Escribir 'Eligio GERENTE';
			Escribir 'GERENTE gana 125xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A1;
			sueldo1 <- 125*A1;
			Si A1>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Si sueldo1>20770.30 Entonces
					Escribir 'El trabajador gana: ',sueldo1*(1-0.2352);
				SiNo
					Escribir 'El trabajador gana: ',sueldo1;
				FinSi
			FinSi
		2:
			Escribir 'Eligio OBRERO';
			Escribir 'OBRERO gana 35xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A2;
			sueldo3 <- 40*A1;
			Si A2>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Escribir 'El trabajador gana: ',sueldo2;
			FinSi
		3:
			Escribir 'Eligio SECRETARIO';
			Escribir 'SECRETARIO  gana 90xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A3;
			sueldo3 <- 90*A3;
			Si A3>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Escribir 'El trabajador gana: ',sueldo3;
			FinSi
		5:
			Escribir 'Eligio TECNICO';
			Escribir 'TECNICO  gana 90xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A4;
			sueldo4 <- 100*A4;
			Si A4>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Escribir 'El trabajador gana: ',sueldo4;
			FinSi
		6:
			Escribir 'Eligio CONSERGUE';
			Escribir 'TECNICO  gana 23xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A5;
			sueldo5 <- 23*A5;
			Si A4>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Escribir 'El trabajador gana: ',sueldo5;
			FinSi
		7:
			Escribir 'Eligio PASANTE';
			Escribir 'TECNICO  gana 30xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A6;
			sueldo6 <- 30*A5;
			Si A6>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Escribir 'El trabajador gana: ',sueldo6;
			FinSi
		8:
			Escribir 'Eligio JEFE REGIONAL';
			Escribir 'GERENTE gana 170xhora';
			Escribir 'igrese el numero de horas que trabaja';
			Leer A7;
			sueldo7 <- 170*A1;
			Si A7>192 Entonces
				Escribir 'No puede trabajar mas de 192 por mes el trabajador';
			SiNo
				Si sueldo1>20770.30 Entonces
					Escribir 'El trabajador gana: ',sueldo1*(1-0.2352);
				SiNo
					Escribir 'El trabajador gana: ',sueldo1;
				FinSi
			FinSi
		De Otro Modo:
			Escribir 'OPCION INVALIDA';
	FinSegun
FinProceso