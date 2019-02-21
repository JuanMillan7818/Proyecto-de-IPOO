
#include <iostream>
#include <stdlib.h> 
#include <vector>

using namespace std ;

//Crear una Clase

class InformacionPrinLaboratorio {
	private :
		string NombreRegistrar ;
		string ContenidoRegistrar ;
	
	public :
		void setNombre (string NombreRegistrar_) ;
		void setContenido (string ContenidoRegistrar_) ;
		string getNombre () ;
		string getContenido () ;
		void CrearDatosEnCsv () ;
		void CargarContenido (vector <InformacionPrinLaboratorio> Informacion) ;
		void ActualizarInformacion (vector <InformacionPrinLaboratorio> InformacionTotal) ;
};
