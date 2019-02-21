
#include <iostream>
#include <stdlib.h>

using namespace std ;

class Menu {
	private :
		int OpcionElegida ;
		
	public :
		void setOpcionElegida (int OpcionElegida_) ;
		int getOpcionElegida () ;
		void MenuIngreso () ;
		void MenuPrincipal () ;
		void SubMenuInformacion () ;
		void SubMenuMostrarTodo () ;
		void SubMenuModificarTodo () ;
		void SubMenuRegistrarTodo () ;
		void SubMenuEliminarTodo () ;
}; 
