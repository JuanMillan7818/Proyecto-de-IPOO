
#include <fstream>
#include <vector>
#include "Elementos del laboratorio.h"

using namespace std ;

vector <ElementosDelLaboratorio> ElementosAgregados ;


// Constructor
ElementosDelLaboratorio::ElementosDelLaboratorio () {	

}


// SETTERS
void ElementosDelLaboratorio::set_nombre(string nombre) {
	this->Nombre = nombre ;
}

void ElementosDelLaboratorio::set_marca(string marca) {
	this->Marca = marca ;
}

void ElementosDelLaboratorio::set_codigo(string codigo) {
	this->Codigo = codigo ;
}

void ElementosDelLaboratorio::set_anio(string anio) {
	this->Anio = anio ;
}

void ElementosDelLaboratorio::set_estado(string estado) {
	this->Estado = estado ;
}

void ElementosDelLaboratorio::set_asignadoA(string asignadoA) {
	this->AsignadoA = asignadoA ;
}

// GETTERS 
string ElementosDelLaboratorio::getNombre() {
	return Nombre ;
}

string ElementosDelLaboratorio::getMarca() {
	return Marca ;
}

string ElementosDelLaboratorio::getCodigo() {
	return Codigo ;
}

string ElementosDelLaboratorio::getAnio() {
	return Anio ;
}

string ElementosDelLaboratorio::getEstado() {
	return Estado ;
}

string ElementosDelLaboratorio::getAsignadoA() {
	return AsignadoA ;
}

// OTROS METODOS
// Crear CVS de los elementos del Laboratorio
void ElementosDelLaboratorio::CrearCVS() {
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Elementos-Laboratorio.csv", ios::app) ;
		ElementosDelLaboratorio Elemento1 ;
		Nombre = "Portatil" ;
		Marca = "Lenovo" ;
		Anio = "2018" ;
		Codigo = "2178" ;
		AsignadoA = "Efrain" ;
		Estado = "1" ;
		Elemento1.set_nombre(Nombre) ;
		Elemento1.set_marca(Marca) ;
		Elemento1.set_anio(Anio) ;
		Elemento1.set_codigo(Codigo) ;
		Elemento1.set_estado(Estado) ;
		Elemento1.set_asignadoA(AsignadoA) ;
		
		ElementosAgregados.push_back(Elemento1) ;
		 
		ElementosDelLaboratorio Elemento2 ;
		Nombre = "Portatil" ;
		Marca = "Acer" ;
		Anio = "2018" ;
		Codigo = "2851" ;
		AsignadoA = "Roosvelt" ;
		Estado = "1" ;
		Elemento2.set_nombre(Nombre) ;
		Elemento2.set_marca(Marca) ;
		Elemento2.set_anio(Anio) ;
		Elemento2.set_codigo(Codigo) ;
		Elemento2.set_asignadoA(AsignadoA) ;
		Elemento2.set_estado(Estado) ;
		
		ElementosAgregados.push_back(Elemento2) ; 
		
		Archivo << "Nombre"   << ';' ;
		Archivo << "Marca"    << ';' ;	
		Archivo << "Codigo"   << ';' ;
		Archivo << "Anio"     << ';' ;
		Archivo << "Asigna A" << ';' ;
		Archivo << "Estado"   << '\n' ;
		for (int i=0 ; i<ElementosAgregados.size() ; i++) {
			Archivo << ElementosAgregados[i].Nombre    << ';' ;
			Archivo << ElementosAgregados[i].Marca     << ';' ;
			Archivo << ElementosAgregados[i].Codigo    << ';' ;
			Archivo << ElementosAgregados[i].Anio      << ';' ;
			Archivo << ElementosAgregados[i].AsignadoA << ';' ;
			Archivo << ElementosAgregados[i].Estado    << '\n' ;
		}
		Archivo.close() ;
	}
	Archivo.close() ;
}

// Cargar CVS de los elementos del Laboratorio
void ElementosDelLaboratorio::CargarCVSDeElementos() {
	ElementosAgregados.clear() ;
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	if (!Archivo.is_open()) {
		cout << "Error" ;
		system ("pause") ;
	}
	
	while (!Archivo.eof()) {
		getline (Archivo, Nombre, ';') ;
		getline (Archivo, Marca, ';') ;
		getline (Archivo, Codigo, ';') ;
		getline (Archivo, Anio, ';') ;
		getline (Archivo, AsignadoA, ';') ;
		getline (Archivo, Estado, '\n') ;
		
		ElementosDelLaboratorio ElementoTemporal ;
		ElementoTemporal.set_nombre(Nombre) ;
		ElementoTemporal.set_marca(Marca) ;
		ElementoTemporal.set_codigo(Codigo) ;
		ElementoTemporal.set_anio(Anio) ;
		ElementoTemporal.set_estado(Estado) ;
		ElementoTemporal.set_asignadoA(AsignadoA) ;
		
		ElementosAgregados.push_back(ElementoTemporal) ;
	}

	ElementosAgregados.pop_back() ;
	Archivo.close() ;
}

// Mostrar todos los elementos del Laboratorio
void ElementosDelLaboratorio::MostrarElementos() {
	for(int i=1; i<ElementosAgregados.size(); i++){
		cout << "\tElemento " << i << "\n" ;
		cout << ". Nombre: " << ElementosAgregados[i].Nombre << "\n";
		cout << ". Marca: " << ElementosAgregados[i].Marca   << "\n" ;
		cout << ". Codigo: " << ElementosAgregados[i].Codigo << "\n" ;
		cout << ". Anio: " << ElementosAgregados[i].Anio      << "\n" ;
		cout << ". Asiganado A:" << ElementosAgregados[i].AsignadoA  << "\n" ;
		cout << ". Estado: " << ElementosAgregados[i].Estado << "\n\n" ;
	}
}

// Modificar algun elemento
void ElementosDelLaboratorio::ModificarElementos(int opcion) {
	system ("cls") ;
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	if (Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Elementos-Laboratorio.csv", ios::app) ; 
		
		for (int i=1 ; i<ElementosAgregados.size() ; i++) {
			if (opcion == i) {
				cout << "\tQue informacion del elemento desea modificar? \n\n" ;
				cout << " 1. Nombre: " << ElementosAgregados[i].Nombre << "\n" ;
				cout << " 2. Marca: " << ElementosAgregados[i].Marca << "\n" ;
				cout << " 3. Codigo: " << ElementosAgregados[i].Codigo << "\n" ;
				cout << " 4. Año: " << ElementosAgregados[i].Anio << "\n" ;
				cout << " 5. Nombre del asignado: " << ElementosAgregados[i].AsignadoA << "\n" ;
				cout << " 6. Estado: " << ElementosAgregados[i].Estado << "\n" ;
				
				int opcionAux ;
				cout << "Ingrese cual desea modificar: " ;
				cin  >> opcionAux ;
				
				switch (opcionAux) {
					case 1 : {
						system("cls") ;
						cout << "Ingrese el nuevo nombre: \n" ;
						cin  >> Nombre ;
						ElementosAgregados[i].set_nombre(Nombre) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 2 : {
						system("cls") ;
						cout << "Ingrese la nueva marca: \n" ;
						cin  >> Marca ;
						ElementosAgregados[i].set_marca(Marca) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 3 : {
						system("cls") ;
						cout << "Ingrese el nuevo codigo: \n" ;
						cin  >> Codigo ;
						ElementosAgregados[i].set_codigo(Codigo) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 4 : {
						system("cls") ;
						cout << "Ingrese el nuevo Año: \n" ;
						cin  >> Anio ;
						ElementosAgregados[i].set_anio(Anio) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 5 : {
						system("cls") ;
						cout << "Ingrese la persona a quien va a asignar: \n" ;
						cin  >> AsignadoA ;
						ElementosAgregados[i].set_asignadoA(AsignadoA) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 6 : {
						system("cls") ;
						cout << "Ingrese el nuevo estado: \n" ;
						cin  >> Estado ;
						ElementosAgregados[i].set_estado(Estado) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					default : {
						system("cls") ;
						cout << "\nOpcion Incorrecta \n" ;
						system("pause") ;
					} break ;
				}
			}
		}
	}else {
			cout << "\nError Al abrir el documento \n\n" ;
		system("pause") ;
		system("cls") ;
	}
	Archivo.close() ;
}



// Crear Un elemento del Laboratorio
void ElementosDelLaboratorio::CrearElementos() {
	ElementosDelLaboratorio Temporal ;
	cout << "Ingrese el nombre del articulo: \n" ;
	cin  >> this->Nombre ; 
	
	cout << "Ingrese el marca del articulo: \n" ;
	cin  >> this->Marca ; 
	
	cout << "Ingrese el codigo del articulo: \n" ;
	cin  >> this->Codigo ; 
	
	cout << "Ingrese el anio del articulo: \n" ;
	cin  >> this->Anio ; 
	
	cout << "Ingrese el nombre del profesor asiganado: \n" ;
	cin  >> this->AsignadoA ;
	
	cout << "Ingrese el estado del articulo: \n" ;
	cout << " (0=inactivo / 1=activo) \n" ; 
	fflush (stdin) ;
	cin  >> this->Estado ;
	
	Temporal.set_nombre(Nombre) ;
	Temporal.set_marca(Marca) ;
	Temporal.set_codigo(Codigo) ;
	Temporal.set_anio(Anio) ;
	Temporal.set_asignadoA(AsignadoA) ;
	Temporal.set_estado(Estado) ;
	
	ElementosAgregados.push_back(Temporal) ;
} 

// Actualizar todos los elementos que hay en el Laboratorio
void ElementosDelLaboratorio::ActualizarDatosElementos() {
	ofstream Archivo ("Elementos-Laboratorio.csv", ios::out) ;
		
	for (int i=0 ; i<ElementosAgregados.size() ; i++) {
		Archivo << ElementosAgregados[i].Nombre << ';' ;
		Archivo << ElementosAgregados[i].Marca << ';' ;
		Archivo << ElementosAgregados[i].Codigo << ';' ;
		Archivo << ElementosAgregados[i].Anio << ';' ;
		Archivo << ElementosAgregados[i].AsignadoA << ';' ;
		Archivo << ElementosAgregados[i].Estado << '\n' ;
	}
}


/*
void ElementosDelLaboratorio::Eliminar(vector <ElementosDelLaboratorio> ElementosActuales, int i) {
	ElementosActuales.erase(ElementosActuales.begin()+i, ElementosActuales.end()+i+1) ;
}*/
