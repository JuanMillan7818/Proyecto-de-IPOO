
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std ;

class InformacionDelLaboratorio {
	private :
		string NombreRegistrar ;
		string ContenidoRegistrar ;
	
	public :
		void setNombre (string NombreRegistrar_) ;
		void setContenido (string ContenidoRegistrar_) ;
		string getNombre () ;
		string getContenido () ;
		void CrearDatosEnCsv () ;
		void CargarContenido () ;
		void MostrarDatos () ; 
		void ModificarDatos (int opcion) ;
		void AgregarDatos () ;
		void ActualizarInformacion () ;
};

