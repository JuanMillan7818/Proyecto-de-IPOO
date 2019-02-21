
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include "Informacion Del Laboratorio.h"
#include "Elementos del laboratorio.h"
#include "Menu.h"

using namespace std ;


// Estructuras 
struct Dia {
	int Anio, Mes, Dia ;
	string Hora ;
		
}Dia1 ;


// Vectores 
vector <string> Agregados ;
vector <string> Contenidos ;

//////////////////////////////////////////////////////////////
// INFORMACION DEL LABORATORIO
// Vector de los objetos de informacion
vector <InformacionPrinLaboratorio> Informacion ;

// Crear CVS
void CrearCSVDelLaboratorio () {
	InformacionPrinLaboratorio InfoPrincipal ;
	InfoPrincipal.CrearDatosEnCsv() ;	
	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	if (!Archivo.is_open()) {
		cout << "\nError al abrir el documento de la informacion del Laboratorio \n" ;
		system("pause") ;
	}
}



// Cargr todo el contenido del cvs
void CargarDatosLaboratorio () {
	string stringNom, stringCont ;
	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	while (!Archivo.eof()) {
		InformacionPrinLaboratorio DatosGuardados ;
			getline (Archivo, stringNom, ';' ) ;
			DatosGuardados.setNombre(stringNom) ;
			getline (Archivo, stringCont, '\n') ;
			DatosGuardados.setContenido(stringCont) ;
			Informacion.push_back(DatosGuardados) ;		
	}
	Informacion.pop_back() ;
	Archivo.close() ;	
}


// Agregar informacion Del laboratorio
void AgregarDatosLaboratorio () {
	int Cantidad ;
	string NombreTemporal , ContenidoTemporal ;
	InformacionPrinLaboratorio AgregadoTemporal ;
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
	AgregadoTemporal.ActualizarInformacion(Informacion) ;
}


// Mostrar toda la informacion
void MostrarInformacionLaboratorio () {
	for (int i=1 ; i<Informacion.size() ; i++) {
		cout << i << ". " << Informacion[i].getNombre() <<  ": \n" ;
		cout << "   " << Informacion[i].getContenido() << "\n\n" ;
	}
}

// Modificar informacion del laboratorio
void ModificarInformacionLaboratorio (int opcion) {
	ifstream Archivo ("Informacion-Laboratorio.csv") ;
	string Nombre, Contenido ;
	
	if (Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Informacion-Laboratorio.csv", ios::app) ;
		
		for (int i=1 ; i<Informacion.size() ; i++) {
			if (opcion == i) {
				cout << "La informacion que existe es la siguiente: \n" ; 
				cout << opcion << ". " << Informacion[i].getNombre() << "\n" ;
				cout << "   " << Informacion[i].getContenido() << "\n" ;
				
				char OpcionYN ;
				cout << "Esta Seguro de Modicar La informacion? (y=yes /n=no)\n" ;
				fflush(stdin) ;
				cin  >> OpcionYN ; 				
				if (OpcionYN == 'y') {
					system("cls") ;
					cout << "Que informacion desea modifcar? \n" ;
					cout << "1. " << Informacion[i].getNombre() << "\n" ;
					cout << "2. " << Informacion[i].getContenido() << "\n" ;
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
							cin  >> Nombre ;
							Informacion[i].setContenido(Nombre) ;
							cout << "\nModificacion Exitosa \n" ;
						} break ;
						
						default : {
							cout << "Opcion Incorrecta \n\n" ;
							system("pause") ;							
						}break ;   
					}
				} else {
					break ;
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


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Elementos del laboratorio 
vector <ElementosDelLaboratorio> Elementos ;

// CREAR UN CVS SI NO LO HAY CON ALGUNOS DATOS 
void CrearElementosEnCVs () {
	ElementosDelLaboratorio ElementosIniciales ;
	ElementosIniciales.CrearCVS() ;
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	if (!Archivo.is_open()) {
		cout << "\nError al abrir el documento de los Elementos del Laboratorio \n" ;
		system("pause") ;
	}
}

// CARGAR CONTENIDO DEL CVS
void CargarCsvDeElementos () {
	string Nombre, Marca, Estado, Anio, Codigo, AsignadoA ;
	
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	if (!Archivo.is_open()) {
		cout << "\nError No Encontramos el documento \n" ;
		system("pause" ) ;
		exit(1) ;
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
		
		Elementos.push_back(ElementoTemporal) ;
	}
	Elementos.pop_back() ;
	Archivo.close() ;
}

// MOSTRAR TODO LO DEL CVS 
void MostrarElementosLaboratorio () {
	for(int i=1; i<Elementos.size(); i++){
		cout << "\tElemento " << i << "\n" ;
		cout << ". Nombre: " << Elementos[i].get_nombre() << "\n";
		cout << ". Marca: " << Elementos[i].get_marca() << "\n" ;
		cout << ". Codigo: " << Elementos[i].get_codigo() << "\n" ;
		cout << ". Año: " << Elementos[i].get_anio() << "\n" ;
		cout << ". Asiganado A:" << Elementos[i].get_asignadoA() << "\n" ;
		cout << ". Estado: " << Elementos[i].get_estado() << "\n\n" ;
	}
}

// MODIFICAR LO QUE HAY EN LOS ELEMENTOS DEL LABORATORIO
void ModificarElementosLaboratorio (int opcion) {
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	string NombreTemporal, MarcaTemporal, CodigoTemporal, AnioTemporal, AsignadoTemporal, EstadoTemporal ; 
	if (Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Elementos-Laboratorio.csv", ios::app) ; 
		
		for (int i=1 ; i<Elementos.size() ; i++) {
			if (opcion == i) {
				cout << "\tQue informacion del elemento desea modificar? \n\n" ;
				cout << " 1. Nombre: " << Elementos[i].get_nombre() << "\n" ;
				cout << " 2. Marca: " << Elementos[i].get_marca() << "\n" ;
				cout << " 3. Codigo: " << Elementos[i].get_codigo() << "\n" ;
				cout << " 4. Año: " << Elementos[i].get_anio() << "\n" ;
				cout << " 5. Nombre del asignado: " << Elementos[i].get_asignadoA() << "\n" ;
				cout << " 6. Estado: " << Elementos[i].get_estado() << "\n" ;
				
				int opcionAux ;
				cout << "Ingrese cual desea modificar: " ;
				cin  >> opcionAux ;
				
				switch (opcionAux) {
					case 1 : {
						system("cls") ;
						cout << "Ingrese el nuevo nombre: \n" ;
						cin  >> NombreTemporal ;
						Elementos[i].set_nombre(NombreTemporal) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 2 : {
						system("cls") ;
						cout << "Ingrese la nueva marca: \n" ;
						cin  >> MarcaTemporal ;
						Elementos[i].set_marca(MarcaTemporal) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 3 : {
						system("cls") ;
						cout << "Ingrese el nuevo codigo: \n" ;
						cin  >> CodigoTemporal ;
						Elementos[i].set_codigo(CodigoTemporal) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 4 : {
						system("cls") ;
						cout << "Ingrese el nuevo Año: \n" ;
						cin  >> AnioTemporal ;
						Elementos[i].set_anio(AnioTemporal) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 5 : {
						system("cls") ;
						cout << "Ingrese el nuevo Año: \n" ;
						cin  >> AsignadoTemporal ;
						Elementos[i].set_asignadoA(AsignadoTemporal) ;
						cout << "\nCambio Exitoso \n" ;
						system("pause") ;
						system("cls") ;
					} break ;
					
					case 6 : {
						system("cls") ;
						cout << "Ingrese el nuevo Año: \n" ;
						cin  >> EstadoTemporal ;
						Elementos[i].set_estado(EstadoTemporal) ;
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

// Para Registrar elementos esa funcion esta en un metodo de la clase.....

// ELIMINAR ELEMENTOS DEL LABORATORIO
void EliminarElementosLaboratorio (int opcion) {
	ifstream Archivo ("Elementos-Laboratorio.csv") ;
	if (Archivo.is_open()) {
		ofstream Archivo ;
		Archivo.open("Elementos-Laboratorio.csv", ios::app) ;
		
		for (int i=1 ; i<Elementos.size() ; i++) {
			if (opcion == i) {
				system("cls") ;
				cout << "La informacio que deseas eliminar es la siguiente: \n" ;
				cout << " 1. Nombre: " << Elementos[i].get_nombre() << "\n" ;
				cout << " 2. Marca: " << Elementos[i].get_marca() << "\n" ;
				cout << " 3. Codigo: " << Elementos[i].get_codigo() << "\n" ;
				cout << " 4. Año: " << Elementos[i].get_anio() << "\n" ;
				cout << " 5. Nombre del asignado: " << Elementos[i].get_asignadoA() << "\n" ;
				cout << " 6. Estado: " << Elementos[i].get_estado() << "\n" ;
				
								
				char OpcionYN ;
				cout << "Seguro que desear eliminar este elemento? (y=yes /n=no \n" ;
				cin  >> OpcionYN ;
				if (OpcionYN == 'y') {
					//ElementosDelLaboratorio ole ;
					//ole.Eliminar(Elementos, i) ;
					//Elementos.erase(Elementos.begin()+i, Elementos.end()+i+1) ;
				}
			}
		}
	}
	Archivo.close() ;
}

int main() {
	
	// INFORMACION LABORATORIO
	CrearCSVDelLaboratorio () ;
	CargarDatosLaboratorio () ;
	
	// INFORMACION ELEMENTOS DEL LABORATORIO 
	CrearElementosEnCVs ()  ;
	CargarCsvDeElementos () ;
	
	
	int Opcion ;
	Dia1.Anio = 2019 ;
	Dia1.Dia = 01 ;
	Dia1.Mes = 01 ;
	Dia1.Hora = "13:00" ;
	
	bool Salir = false ;
		do {
			// Menu Inicial 
			cout << "\n\tBienvenido al Laboratorio de Sistemas \n" ;
			cout << "\t\t Universidad de Valle \n\n" ;
			cout << "Hora: " << Dia1.Hora ;
			cout << "\t\t\t\tFecha: " << Dia1.Anio << "/" << Dia1.Mes << "/" << Dia1.Dia ;
			cout << "\n\n" ;				
			
			Menu Ingreso ;
			Ingreso.MenuIngreso() ;
			Opcion = Ingreso.getOpcionElegida() ;
			switch (Opcion) {
				case 1 : {
					// Menu Principal
					system ("cls") ;
					// Informacion Basica
					cout << "\n\tBienvenido al Laboratorio de Sistemas \n" ;
					cout << "\t\t Universidad de Valle \n\n" ;
					cout << "Hora: " << Dia1.Hora ;
					cout << "\t\t\t\tFecha: " << Dia1.Anio << "/" << Dia1.Mes << "/" << Dia1.Dia ;
					cout << "\n\n" ;			
					cout << "\n\n" ;	
					
					// Menu Principal 
					// Opciones
					do {
						Ingreso.MenuPrincipal() ;
						Opcion = Ingreso.getOpcionElegida() ;
						switch (Opcion) {
							case 1 : { // Informacion del laboratorio y acciones
								system ("cls") ;
								bool OpCorrecta = true ;
								
								do {
									Ingreso.SubMenuInformacion() ;
									Opcion = Ingreso.getOpcionElegida() ;
									vector< vector<string> > Datos;
									
									switch (Opcion) {
										case 1 : { // Ver Informacion del archivo
											system ("cls") ;
											MostrarInformacionLaboratorio () ;
											system("pause") ;
											system("cls") ;
 										} break ;
										
										case 2 : { // Agregar Informacion al Laboratorio
											system("cls") ;	
											AgregarDatosLaboratorio () ;
											cout << "\nSe Agrego la informacion Exitosamente \n\n" ;																										
											system("pause") ;
											system("cls") ; 
										} break ;
										
										case 3 : {// Modificar informacion del Laboratorio											
											system("cls") ; 
											MostrarInformacionLaboratorio () ;
											cout << "Ingrese el numero de la informacion que dea modificar: \n" ;
											cin  >> Opcion ;
											system("cls") ;
											ModificarInformacionLaboratorio (Opcion) ;																 
											system("pause") ;
											system("cls") ;						
										} break ;
										
										case 4 : {// Atras 
											system("cls") ;
										} break ;									
										
										default : {// Opcion Incorrecta
											system ("cls") ;
											cout << "Opcion Incorrecta \n" ;
											OpCorrecta = false ;
										} break ;
									}
								} while (!OpCorrecta) ;
							} break ;
							
							case 2 : { // Mostrar elementos, estudiantes o profesores
								bool OpCorrecta = false ;
								
								do {
									Ingreso.SubMenuMostrarTodo() ;
									Opcion = Ingreso.getOpcionElegida() ;
									switch (Opcion) {
										case 1 : {
											system("cls") ;
											MostrarElementosLaboratorio () ;
											system("pause") ;
											system("cls") ;
										} break ;
										
										case 2 : {											
											
										} break ;
										
										case 3 : {
											
										} break ;
										
										case 4 : { // Atras	
											OpCorrecta = true ;	
											system("cls") ;										

										} break ;
										
										default : { // Opcion incorrecta
											system("cls") ;
											cout  << "\nOpcion Incorrecta \n\n" ;
											OpCorrecta = true ;
											system("pause") ;
											system("cls") ;
										} break ;
									}									
								}while (!OpCorrecta) ;
								
							} break ;
							
							case 3 : { // Modificar Elementos, Estudiantes o Profesores
								bool OpCorrecta = false ;
								do {
									Ingreso.SubMenuModificarTodo() ;
									Opcion = Ingreso.getOpcionElegida() ;
									switch (Opcion) {
										case 1 : {
											system("cls") ;
											MostrarElementosLaboratorio () ;
											cout << "Ingrese el numero del elemento que desea modificar: \n" ;
											cin  >> Opcion ;
											system("cls") ;
											ModificarElementosLaboratorio (Opcion) ;
											ElementosDelLaboratorio ElementosActualizados ;
											ElementosActualizados.ActualizarDatosElementos(Elementos) ;											
										} break ;
										
										case 2 : {
											
										} break ;
										
										
										case 3 : {
											
										} break ;
										
										case 4 : {
											system("cls") ;
											OpCorrecta = true ;
										} break ;
										
										default : {
											system("cls") ;
											cout << "\nOpcion Incorrecta \n\n" ;
											OpCorrecta = true ;
											system("pause") ;
										}break ;
									}	
								}while (!OpCorrecta) ;
							} break ;
							
							case 4 : { // Registar Nuevos Elementos, Estudiantes o Profesores
								system("cls") ;							
								bool OpCorrecta = false ;
								
								do {
									Ingreso.SubMenuRegistrarTodo() ;
									Opcion = Ingreso.getOpcionElegida() ;
									switch (Opcion){
										case 1 :{
											system("cls") ;
											ElementosDelLaboratorio ElementosTemp ;	
											ElementosTemp.CrearElementos() ;
											Elementos.push_back(ElementosTemp) ;
											ElementosTemp.ActualizarDatosElementos(Elementos) ;
											cout << "\nRegistro Exitoso \n\n" ;
											system("pause") ;
											system("cls") ;
										}break ;
										
										case 2 : {
										
										} break ;
										
										case 3 : {
											
										} break ;
										
										case 4 : {
											system("cls") ;
											OpCorrecta = true ;
										} break ;
										
										default : {
											system("cls") ;
											cout << "\nOpcion Incorrecta \n\n" ;
											OpCorrecta = true ;
											system("pause") ;
										} break ;
									}
								}while (!OpCorrecta) ;
								
							} break ;
							
							case 5 : { // Eliminar elementos del laboratorio, profesores o estudiantes
								system("cls") ;							
								bool OpCorrecta = false ;
								
								do {
									Ingreso.SubMenuEliminarTodo() ;
									Opcion = Ingreso.getOpcionElegida() ;
									switch (Opcion) {
										case 1 : {
											system("cls") ;
											MostrarElementosLaboratorio () ;
											cout << "Ingrese el numero del elemento que desea eliminar: \n" ;
											cin  >> Opcion ;
											EliminarElementosLaboratorio (Opcion) ;
											system("pause") ; 
											system("cls") ;
											
											
										} break ;
										
										case 2 : {
											
										} break ;
										
										case 3 : {
											
										} break ;
										
										case 4 : {
											system("cls") ;
											OpCorrecta = true ;
										} break ;
										
										default : {
											system("cls") ;
											cout << "\nOpcion Incorrecta \n\n" ;
											OpCorrecta = true ;
											system("pause") ;
										} break ;
									}
								} while (!OpCorrecta) ;
							} break ;
							
							case 6 : { // Registrar Prestamos
								
							} break ;
							
							case 7 : { // Registrar Devolucines
								
							} break ;
							
							case 8 : { // Salir
								system ("cls") ;
								Salir = true ;
							} break ;
							
							default :{ // Opcion Incorrecta
								system ("cls") ;
								cout << "Opcion Incorrecta \n\n" ;
								system("pause") ;
								system("cls") ;
							} break ;
						}
					} while (!Salir) ;
				} break ;
				
				case 2 :
					system ("cls") ;
					Salir = true ;
					break ;
				
				default : {
					system ("cls") ;
					cout << "Opcion Incorrecta \n" ;
				} break;
			}
		}while (!Salir) ;
		
	system("pause") ;
	return 0;
}
