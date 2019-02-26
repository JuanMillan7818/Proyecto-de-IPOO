
#include <iostream> 
#include <stdlib.h> 
#include <vector>

using namespace std ;

class ElementosDelLaboratorio {
	private :
		string Nombre ;
		string Marca  ;
		string Anio      ;
		string Codigo    ;
		string Estado    ;
		string AsignadoA ;
				
	public :
		ElementosDelLaboratorio () ;
		void set_nombre(string nombre) ;
		void set_marca(string marca) ;
		void set_codigo(string codigo) ;
		void set_estado(string estado) ;
		void set_anio (string anio) ;
		void set_asignadoA (string asignadoA) ;
		string getNombre() ;
		string getMarca() ;
		string getAnio() ;
		string getCodigo() ;
		string getEstado() ;
		string getAsignadoA () ;
		void CrearCVS () ;
		void CargarCVSDeElementos () ;
		void MostrarElementos () ;
		void ModificarElementos (int opcion) ;
		void CrearElementos () ;
		void ActualizarDatosElementos () ;
		void Eliminar (vector <ElementosDelLaboratorio> ElementosActuales, int i) ;
};

