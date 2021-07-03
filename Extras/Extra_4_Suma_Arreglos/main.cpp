#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
#include "operaciones.h"

int main(int argc, char** argv) {
	srand(time(NULL));	
	Operaciones operacion;
	
	operacion.encerar();
	operacion.generar();
	//operacion.ingresar();
	operacion.toString();
	std::cout << std::endl << "La suma es: " 
	<< operacion.procesar() << std::endl;
	
	system("pause");
	return 0;
}

