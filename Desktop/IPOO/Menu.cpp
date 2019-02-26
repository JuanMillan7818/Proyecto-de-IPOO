
#include "Menu.h" 
#include <stdlib.h>
#include <vector>
#include "Informacion del laboratorio.h"
#include "Elementos del laboratorio.h"

using namespace std ;

// SETTERS
void Menu::setOpcionElegida(int OpcionElegida_) {
	OpcionElegida = OpcionElegida_ ;
}


// GETTERS
int Menu::getOpcionElegida() {
	return OpcionElegida ;
}

// Estructura 
struct Fecha {
	int Anio, Mes, Dia ;
	int Hora ;
		
}FechaActual ;

	
// OTROS METODOS

void Menu::MenuDeInformacionIngreso () {
	cout << "\n\tBienvenido al Laboratorio de Sistemas \n" ;
	cout << "\t\t Universidad de Valle \n\n" ;
	/*
	FechaActual.Anio = 2019 ;
	FechaActual.Dia = 01 ;
	FechaActual.Mes = 01 ;
	FechaActual.Hora = 1300 ;*/
}
// Menu de ingreso
void Menu::MenuIngreso() {
	int Opcion ;
	MenuDeInformacionIngreso () ;
	cout << "  1. Si desea conocer nuestras funcionalidades lo invitameos a \n" ;
	cout << "     elegir esta opcion. \n\n" ;
	cout << "  2. Si desea Salir del programa por favor seleccione esta opcion. \n\n" ;
		
	cout << "Por favor seleccione una opcion: " ;
	cin  >> Opcion ;
	
	if (Opcion == 1) {
		MenuPrincipal() ;
	}else {
		system("cls") ;
		cout << "\n\nGracias por usar nuestro servicio \n\n" ;
	}
}

// Menu Principal del laboratorio
void Menu::MenuPrincipal() {
	system ("cls") ;
	int Opcion ;
	MenuDeInformacionIngreso () ;
	cout << "\t\tMenu Principal \n\n" ;
	cout << " 1. Informacion del Laboratorio y Funciones \n" ;
	cout << " 2. Mostrar, modificar, registrar o eliminar elementos del laboratorio \n" ;
	cout << " 3. Mostrar, modificar, registrar o eliminar datos de profesores \n" ;
	cout << " 4. Mostrar, modificar, registrar o eliminar datos de estudiantes \n" ;
	cout << " 5. Eliminar registro de elementos del laboratorio, profesores o estudiantes \n" ; 
	cout << " 6. Registrar un prestamo de algun elemento del laboratorio \n" ;
	cout << " 7. Registrar una devolucion de algun articulo del laboratorio (Solo estudiantes) \n" ;
	cout << " 8. Salir \n\n" ;
					
	cout << "Por favor seleccione una opcion: " ;
	cin  >> Opcion ;
	switch (Opcion) {
		case 1 : {
			SubMenuInformacion () ;
			break;
		}
			
		case 2 : {
			SubMenuFuncionesParaElementos () ;
			break;
		}
			
		case 3 :{
			break;
		}
			
		case 4 : {
			break;
		}
			
		case 5 : {
			break;
		}
			
		case 6 : {
			break;
		}
			
		case 7 : {
			break;
		}
			
		case 8 : {
			system("cls") ;
			cout << "\n\nGracias por usar nuestro servicio \n\n" ;
			break;
		}
			
		default : {
			cout << "\n\nOpcion Incorrecta \n\n" ;
			system("pause") ;
			break;
		}
	}	
}

// Menu de las opcione que tiene acerca del manejo de la informacion
void Menu::SubMenuInformacion() {
	bool Salir = false ;
	InformacionDelLaboratorio InfoActual ;
	InfoActual.CargarContenido() ; 
	do {
		system ("cls") ;	
		int Opcion ;
		cout << "\tFunciones Que puede realizar \n\n" ;
		cout << " 1. Ver la Informacion del laboratorio \n" ;
		cout << " 2. Agregar informacion personal al laboratorio \n" ;
		cout << " 3. Modificar informacion personal al laboratorio \n" ;
		cout << " 4. Atras \n\n" ;
									
		cout << "Por favor ingrese su opcion: " ;
		cin  >> Opcion ;	
		
		switch (Opcion) {
			case 1 : { // Mostrar Informacion del laboratorio
				system("cls") ;
				InfoActual.MostrarDatos() ;		
				system("pause");
				break;
			}
			
			case 2 : { // Agregar Informacion del laboratorio
				system("cls") ;	
				InfoActual.AgregarDatos() ; 
				cout << "\nSe Agrego la informacion Exitosamente \n\n" ;																										
				system("pause") ;
				system("cls") ;
				break;
			}
			
			case 3 : { // Modificar Informacion del laboratorio
				InfoActual.MostrarDatos() ;		
				cout << "Ingrese el numero de la informacion que dea modificar: \n" ;
				cin  >> Opcion ;
				InfoActual.ModificarDatos(Opcion) ;
				InfoActual.ActualizarInformacion() ;
				cout << "\nSe Agrego la informacion Exitosamente \n\n" ;																										
				system("pause") ;
				system("cls") ;
				break;
			}
			
			case 4 : { // Atras
				MenuPrincipal () ;
				Salir = true ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\n\nOpcion Incorrecta \n\n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}
	}while (!Salir) ;
}

// Menu de las opciones que tiene acerca del manejo de los elementos del laboratorio
void Menu::SubMenuFuncionesParaElementos() {
	bool Salir = false ;
	ElementosDelLaboratorio ElementosActuales ;
	ElementosActuales.CargarCVSDeElementos() ;
	do {
		system("cls") ;
		int Opcion ;
		cout << "\tFunciones que puedes realizar \n\n" ;
		cout << " 1. Mostra elementos del Laboratorio \n" ;
		cout << " 2. Modificar algun elemento del Laboratorio \n" ;
		cout << " 3. Registrar elementos del Laboratorio \n" ;
		cout << " 4. Eliminar algun elemento del Laboratorio \n" ;
		cout << " 5. Atras \n\n" ;
						
		cout << "Por ingrese su opcion:" ;
		cin  >> Opcion ;
		OpcionElegida = Opcion ;
		
	
		switch (Opcion) {
			case 1 : {
				system ("cls");
				ElementosActuales.MostrarElementos() ;
				system ("pause") ;
				break;
			}
			
			case 2 : {
				ElementosActuales.MostrarElementos() ;
				cout << "Ingrese el numero de Elementos que desea modificar: \n" ;
				cin  >> Opcion ;
				ElementosActuales.ModificarElementos(Opcion) ;
				ElementosActuales.ActualizarDatosElementos() ;
				
				break;
			}
			
			case 3 : {
				ElementosActuales.CrearElementos() ;
				ElementosActuales.ActualizarDatosElementos() ;
				cout << "\nRegistro Exitoso \n\n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
			
			case 4 : {
				break;
			}
			
			case 5 : {
				MenuPrincipal () ;
				Salir = true ;
				break;
			}
			
			default : {
				cout << "\n\nOpcion Incorrecta \n\n" ;
				system("pause") ;
				break;
			}
		}
	}while (!Salir) ;
}

// 
void Menu::SubMenuModificarTodo() {
	system("cls") ;
	int Opcion ;
	cout << "\tFunciones que puedes realizar \n\n" ;
	cout << " 1. Modificar los elementos del Laboratorio \n" ;
	cout << " 2. Modificar la informacion del profesor \n" ;
	cout << " 3. Modificar la informacion del estudiante \n" ;
	cout << " 4. Atras \n\n" ;
								
	cout << "Por ingrese su opcion:" ;
	cin  >> Opcion ;
	OpcionElegida = Opcion ;
}

void Menu::SubMenuRegistrarTodo() {
	system("cls") ;
	int Opcion ;
	cout << "\tFunciones que puedes realizar \n\n" ;
	cout << " 1. Registar nuevos elementos del Laboratorio \n" ;
	cout << " 2. Registar nuevos profesores \n" ;
	cout << " 3. Registrar nuevos estudiantes \n" ;
	cout << " 4. Atras \n\n" ;
									
	cout << "Por ingrese su opcion:" ;
	cin  >> Opcion ;
	OpcionElegida = Opcion ;
}

void Menu::SubMenuEliminarTodo() {
	system("cls") ;
	int Opcion ;
	cout << "\tFunciones que puedes realizar \n\n" ;
	cout << " 1. Eliminar elementos del Laboratorio \n" ;
	cout << " 2. Eliminar datos de profesores \n" ;
	cout << " 3. Eliminar datos de estudiantes \n" ;
	cout << " 4. Atras \n\n" ;
									
	cout << "Por ingrese su opcion:" ;
	cin  >> Opcion ;
	OpcionElegida = Opcion ;
}

