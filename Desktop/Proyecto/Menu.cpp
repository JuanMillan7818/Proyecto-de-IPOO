
#include "Menu.h" 
#include <stdlib.h>

using namespace std ;

// SETTERS
void Menu::setOpcionElegida(int OpcionElegida_) {
	OpcionElegida = OpcionElegida_ ;
}

// GETTERS
int Menu::getOpcionElegida() {
	return OpcionElegida ;
}

// OTROS METODOS
void Menu::MenuIngreso() {
	int Opcion ;
	cout << "  1. Si desea conocer nuestras funcionalidades lo invitameos a \n" ;
	cout << "     elegir esta opcion. \n\n" ;
	cout << "  2. Si desea Salir del programa por favor seleccione esta opcion. \n\n" ;
		
	cout << "Por favor seleccione una opcion: " ;
	cin  >> Opcion ;
	OpcionElegida = Opcion ;	
}

void Menu::MenuPrincipal() {
	int Opcion ;
	cout << "\t\tMenu Principal \n\n" ;
	cout << " 1. Informacion del Laboratorio y Funciones \n" ;
	cout << " 2. Mostrar elementos del laboratorio, profesores o estudiantes \n" ;
	cout << " 3. Modificar elementos del laboratorio, profesores o estudiantes \n" ;
	cout << " 4. Registrar elementos del laboratorio, profesores o estudiantes \n" ;
	cout << " 5. Eliminar registro de elementos del laboratorio, profesores o estudiantes \n" ; 
	cout << " 6. Registrar un prestamo de algun elemento del laboratorio \n" ;
	cout << " 7. Registrar una devolucion de algun articulo del laboratorio (Solo estudiantes) \n" ;
	cout << " 8. Salir \n\n" ;
				
	cout << "Por favor seleccione una opcion: " ;
	cin  >> Opcion ;
	OpcionElegida = Opcion ;			
}

void Menu::SubMenuInformacion() {
	system ("cls") ;	
	int Opcion ;
	cout << "\tFunciones Que puede realizar \n\n" ;
	cout << " 1. Ver la Informacion del laboratorio \n" ;
	cout << " 2. Agregar informacion personal al laboratorio \n" ;
	cout << " 3. Modificar informacion personal al laboratorio \n" ;
	cout << " 4. Atras \n\n" ;
								
	cout << "Por favor ingrese su opcion: " ;
	cin  >> Opcion ;	
	OpcionElegida = Opcion ;
}

void Menu::SubMenuMostrarTodo() {
	system("cls") ;
	int Opcion ;
	cout << "\tFunciones que puedes realizar \n\n" ;
	cout << " 1. Mostra elementos del Laboratorio \n" ;
	cout << " 2. Mostrar la informacion del profesor \n" ;
	cout << " 3. Mostrar la informacion del estudiante \n" ;
	cout << " 4. Atras \n\n" ;
					
	cout << "Por ingrese su opcion:" ;
	cin  >> Opcion ;
	OpcionElegida = Opcion ;
}

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

