
#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std ;

class Menu {
	private :
		int OpcionElegida ;
		struct Fecha ;
				
	public :
		void setOpcionElegida (int OpcionElegida_) ;
		int getOpcionElegida () ;
		void MenuDeInformacionIngreso () ;
		void MenuIngreso () ;
		void MenuPrincipal () ;
		void SubMenuInformacion () ;
		void SubMenuFuncionesParaElementos () ;
		void SubMenuModificarTodo () ;
		void SubMenuRegistrarTodo () ;
		void SubMenuEliminarTodo () ;
}; 
