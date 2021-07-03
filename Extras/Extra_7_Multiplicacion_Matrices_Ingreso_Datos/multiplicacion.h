#pragma once
#include "matriz.h"

class Multiplicacion{
	public:
		Multiplicacion();
		Multiplicacion(int**, int**, int**);
		void multiplicar();
		void toString();
	
	private: 
		Matriz matriz;
};


