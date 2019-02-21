
#include <fstream>
#include <vector>
#include "Elementos del laboratorio.h"

using namespace std ;
/*
ElementosDelLaboratorio::ElementosDelLaboratorio (string nombre, string marca, string anio, string codigo, string estado, string asignadoA, vector <ElementosDelLaboratorio> ElementosTotales) {
	
}*/


// SETTERS
void ElementosDelLaboratorio::set_nombre(string nombre_) {
	nombre = nombre_ ;
}

void ElementosDelLaboratorio::set_marca(string marca_) {
	marca = marca_ ;
}

void ElementosDelLaboratorio::set_codigo(string codigo_) {
	codigo = codigo_ ;
}

void ElementosDelLaboratorio::set_anio(string anio_) {
	anio = anio_ ;
}

void ElementosDelLaboratorio::set_estado(string estado_) {
	estado = estado_ ;
}

void ElementosDelLaboratorio::set_asignadoA(string asignadoA_) {
	asignadoA = asignadoA_ ;
}

// GETTERS 
string ElementosDelLaboratorio::get_nombre() {
	return nombre ;
}

string ElementosDelLaboratorio::get_marca() {
	return marca ;
}

string ElementosDelLaboratorio::get_codigo() {
	return codigo ;
}

string ElementosDelLaboratorio::get_anio() {
	return anio ;
}

string ElementosDelLaboratorio::get_estado() {
	return estado ;
}

string ElementosDelLaboratorio::get_asignadoA() {
	return asignadoA ;
}

// OTROS METODOS

void ElementosDelLaboratorio::CrearCVS() {
	vector <ElementosDelLaboratorio> ElementosAgregados ;
	string Nombre, Marca, Estado, Anio, Codigo, AsignadoA ;
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
		Archivo << "Anio"     << ';' ;
		Archivo << "Codigo"   << ';' ;
		Archivo << "Asigna A" << ';' ;
		Archivo << "Estado"   << '\n' ;
		for (int i=0 ; i<ElementosAgregados.size() ; i++) {
			Archivo << ElementosAgregados[i].get_nombre() << ';' ;
			Archivo << ElementosAgregados[i].get_marca() << ';' ;
			Archivo << ElementosAgregados[i].get_anio() << ';' ;
			Archivo << ElementosAgregados[i].get_codigo() << ';' ;
			Archivo << ElementosAgregados[i].get_asignadoA() << ';' ;
			Archivo << ElementosAgregados[i].get_estado() << '\n' ;
		}
		Archivo.close() ;
	}
	Archivo.close() ;
}


void ElementosDelLaboratorio::CrearElementos() {
	cout << "Ingrese el nombre del articulo: \n" ;
	cin  >> nombre ; 
	
	cout << "Ingrese el marca del articulo: \n" ;
	cin  >> marca ; 
	
	cout << "Ingrese el codigo del articulo: \n" ;
	cin  >> codigo ; 
	
	cout << "Ingrese el anio del articulo: \n" ;
	cin  >> anio ; 
	
	cout << "Ingrese el nombre del profesor asiganado: \n" ;
	cin  >> asignadoA ;
	
	cout << "Ingrese el estado del articulo: \n" ;
	cout << " (0=inactivo / 1=activo) \n" ; 
	cin  >> estado ;
} 

void ElementosDelLaboratorio::ActualizarDatosElementos(vector <ElementosDelLaboratorio> ElementosRegistrados) {
	ofstream Archivo ("Elementos-Laboratorio.csv", ios::out) ;
		
	for (int i=0 ; i<ElementosRegistrados.size() ; i++) {
		Archivo << ElementosRegistrados[i].get_nombre() << ';' ;
		Archivo << ElementosRegistrados[i].get_marca() << ';' ;
		Archivo << ElementosRegistrados[i].get_codigo() << ';' ;
		Archivo << ElementosRegistrados[i].get_anio() << ';' ;
		Archivo << ElementosRegistrados[i].get_asignadoA() << ';' ;
		Archivo << ElementosRegistrados[i].get_estado() << '\n' ;
	}
	
}

void ElementosDelLaboratorio::Eliminar(vector <ElementosDelLaboratorio> ElementosActuales, int i) {
	ElementosActuales.erase(ElementosActuales.begin()+i, ElementosActuales.end()+i+1) ;
}
