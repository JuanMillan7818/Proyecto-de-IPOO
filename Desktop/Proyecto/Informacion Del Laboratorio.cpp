
#include <fstream>
#include <vector>
#include "Informacion Del Laboratorio.h"


// SETTERS
void InformacionPrinLaboratorio::setNombre(string NombreRegistrar_)  {
	NombreRegistrar = NombreRegistrar_ ;
}

void InformacionPrinLaboratorio::setContenido(string ContenidoRegistrar_) {
	ContenidoRegistrar = ContenidoRegistrar_ ;
}

// GETTERS
string InformacionPrinLaboratorio::getNombre() {
	return NombreRegistrar ;
} 

string InformacionPrinLaboratorio::getContenido() {
	return ContenidoRegistrar ;
}

// OTROS METODOS 

void InformacionPrinLaboratorio::CrearDatosEnCsv() {
	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	if (!Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::app) ;
		string Nombre1 = "Direccion" ;
		string Nombre2 = "Correo" ;
		string Nombre3 = "Telefono" ;
		string Nombre4 = "Numero de Identidicacion NIT" ;
		
		string direccion = "Carrera 13 #21-56 B/ Ruben Cruz" ;
		string correo = "correolaboratorio@gmail.com" ;
		string telefono = "3152265624" ;
		string nit = "3602978-5" ;
		
		// Cabezera
		Archivo << "Nombre o Tipo de Informacion" << ';' ;
		Archivo << "Contenido" << '\n' ;
		
		// Nombre y contenido
		Archivo << Nombre1 << ';' << direccion << '\n' ;
		Archivo << Nombre2 << ';' << correo << '\n' ;
		Archivo << Nombre3 << ';' << telefono << '\n' ;
		Archivo << Nombre4 << ';' << nit << '\n' ;
		
		Archivo.close() ;
	}
}


void InformacionPrinLaboratorio::ActualizarInformacion(vector <InformacionPrinLaboratorio> InformacionTotal) {
	ofstream Archivo ("Informacion-Laboratorio.csv", ios::out) ;
	
	for (int i=0 ; i<InformacionTotal.size() ; i++) {
		Archivo << InformacionTotal[i].getNombre() << ';' ;
		Archivo << InformacionTotal[i].getContenido() << '\n' ;
	} 
	Archivo.close() ;
}
