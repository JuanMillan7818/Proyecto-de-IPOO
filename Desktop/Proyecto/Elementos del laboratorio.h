
#include <iostream> 
#include <stdlib.h> 
#include <vector>

using namespace std ;

class ElementosDelLaboratorio {
	private :
		string nombre ;
		string marca  ;
		string anio      ;
		string codigo    ;
		string estado    ;
		string asignadoA ;
	//	vector <ElementosDelLaboratorio> ElementosTotales ;
				
	public :
	//	ElementosDelLaboratorio (string nombre, string marca, string anio, string codigo, string estado, string asignadoA, vector <ElementosDelLaboratorio> ElementosTotales) ;
		void set_nombre(string nombre_) ;
		void set_marca(string marca_) ;
		void set_codigo(string codigo_) ;
		void set_estado(string estado_) ;
		void set_anio (string anio_) ;
		void set_asignadoA (string asignadoA_) ;
		string get_nombre() ;
		string get_marca() ;
		string get_anio() ;
		string get_codigo() ;
		string get_estado() ;
		string get_asignadoA () ;
		void CrearCVS () ;
		void CrearElementos () ;
		void ActualizarDatosElementos (vector <ElementosDelLaboratorio> ElementosRegistrados) ;
		void Eliminar (vector <ElementosDelLaboratorio> ElementosActuales, int i) ;
};

