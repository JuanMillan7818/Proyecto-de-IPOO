
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include "Informacion del laboratorio.h"
#include "Elementos del laboratorio.h"
#include "Menu.h"

using namespace std ;



// Crear CVS De Informacion del laboratorio
void CrearCSVDelLaboratorio () {
	InformacionDelLaboratorio InfoPrincipal ;
	InfoPrincipal.CrearDatosEnCsv() ;	
}

// Crear CVS De Elementos del laboratorio
void CrearCVSDeElementosDeLaboratorio () {
	ElementosDelLaboratorio ElementosIniciales ;
	ElementosIniciales.CrearCVS() ;
}


int main () {		
	// Crear CVS De Elementos
	CrearCVSDeElementosDeLaboratorio () ;
	
	// Crear CVS De Informacion
	CrearCSVDelLaboratorio () ;
	
	// Menu inicial 
	Menu MenuPrograma ;
	
	// Menu Ingreso 
	MenuPrograma.MenuIngreso() ;
	
	
	
	system("pause") ;
	return 0 ;
}



