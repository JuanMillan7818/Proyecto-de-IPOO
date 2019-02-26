
#include <fstream>
#include <vector>
#include "Informacion del laboratorio.h"
#include "Menu.h"


vector <InformacionDelLaboratorio> Informacion ;

// SETTERS
void InformacionDelLaboratorio::setNombre(string NombreRegistrar_)  {
	NombreRegistrar = NombreRegistrar_ ;
}

void InformacionDelLaboratorio::setContenido(string ContenidoRegistrar_) {
	ContenidoRegistrar = ContenidoRegistrar_ ;
}

// GETTERS
string InformacionDelLaboratorio::getNombre() {
	return NombreRegistrar ;
} 

string InformacionDelLaboratorio::getContenido() {
	return ContenidoRegistrar ;
}

// OTROS METODOS 

// Crear el CVS de la Informacion del laboratorio por defecto 
void InformacionDelLaboratorio::CrearDatosEnCsv() {
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
	Archivo.close() ;
}

// Cargar todo lo del CVS al vector de informacion
void InformacionDelLaboratorio::CargarContenido() {
	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	Informacion.clear() ;
	while (!Archivo.eof()) {
		InformacionDelLaboratorio DatosGuardados ;
		getline (Archivo, NombreRegistrar, ';') ;
		DatosGuardados.setNombre(NombreRegistrar) ;
		getline (Archivo, ContenidoRegistrar, '\n') ;
		DatosGuardados.setContenido(ContenidoRegistrar) ;
		Informacion.push_back(DatosGuardados) ;
	}
	Informacion.pop_back() ;
	Archivo.close() ;	
}

// Mostrar Datos del vector donde esta toda la informacion
void InformacionDelLaboratorio::MostrarDatos() {
	for (int i=1 ; i<Informacion.size() ; i++) {
		cout << i << ". " << Informacion[i].NombreRegistrar <<  ": \n" ;
		cout << "   " << Informacion[i].ContenidoRegistrar << "\n\n" ;
	}
}


// Modificar alguna infomormacion del laboratorio
void InformacionDelLaboratorio::ModificarDatos(int opcion) {
	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	string Nombre, Contenido ;
	if (Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::app) ;
		
		for (int i=1 ; i<=Informacion.size() ; i++) {
			if (opcion == i) {
				system("cls") ;
				cout << "La informacion que existe es la siguiente: \n" ; 
				cout << opcion << ". " << Informacion[i].NombreRegistrar << "\n" ;
				cout << "   " << Informacion[i].ContenidoRegistrar << "\n" ;
				
				char OpcionYN ;
				cout << "Esta Seguro de Modicar La informacion? (y=yes /n=no)\n" ;
				fflush(stdin) ;
				cin  >> OpcionYN ; 				
				if (OpcionYN == 'y') {
					system("cls") ;
					cout << "\nQue informacion desea modifcar? \n" ;
					cout << "1. " << Informacion[i].NombreRegistrar << "\n" ;
					cout << "2. " << Informacion[i].ContenidoRegistrar << "\n" ;
					cout << "Ingrese la opcion :" ;
					cin  >> opcion ;
					
					switch (opcion) {
						case 1 : {
							cout << "\nIngrese la nueva informacion: \n" ;
							cin  >> Nombre ;
							Informacion[i].setNombre(Nombre) ;							
							cout << "\nModificacion Exitosa \n" ;
						} break ;
						
						case 2 : {
							cout << "\nIngrese la nueva informacion: \n" ;
							cin  >> Contenido ;
							Informacion[i].setContenido(Contenido) ;
							cout << "\nModificacion Exitosa \n" ;
						} break ;
						
						default : {
							cout << "Opcion Incorrecta \n\n" ;
							system("pause") ;							
						}break ;   
					}
				}
			}
		}
		Archivo.close() ;
	} else {
		cout << "\nError al abrir el documento \n" ;
		cout << "Por favor intente mas tarde \n" ;
		system("cls") ;
	}
	Archivo.close() ;
}

// Agregar datos a la informacion del laboratorio
void InformacionDelLaboratorio::AgregarDatos() {
	int Cantidad ;
	string NombreTemporal , ContenidoTemporal ;
	InformacionDelLaboratorio AgregadoTemporal ;
	cout << "Cuantos datos desea agregar? \n" ;
	cout << "Digite la cantidad: " ;
	cin  >> Cantidad ;
	
	for (int i=0 ; i<Cantidad ; i++) {
		cout << "Por favor Ingrese el nombre del campo " << i+1 << " que desea agregar: \n" ;
		fflush (stdin) ;
		getline (cin, NombreTemporal) ;
		AgregadoTemporal.setNombre(NombreTemporal) ;
			
		cout << "Por favor Ingrese el contenido del campo " << i+1 << ": \n" ;
		fflush (stdin) ;
		getline (cin, ContenidoTemporal) ;
		AgregadoTemporal.setContenido(ContenidoTemporal) ;
		Informacion.push_back(AgregadoTemporal) ;
	}
	AgregadoTemporal.ActualizarInformacion() ;
}


// Actualizar los dato del laboratorio
void InformacionDelLaboratorio::ActualizarInformacion() {
	ofstream Archivo ("Informacion-Laboratorio.csv", ios::out) ;
	
	for (int i=0 ; i<Informacion.size() ; i++) {
		Archivo << Informacion[i].NombreRegistrar << ';' ;
		Archivo << Informacion[i].ContenidoRegistrar << '\n' ;
	} 
	Archivo.close() ;
}

