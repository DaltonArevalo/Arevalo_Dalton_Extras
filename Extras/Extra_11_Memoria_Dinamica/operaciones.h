#pragma once
#include "matriz.h"

class Operaciones{
	public:
		Operaciones() = default;
		Operaciones(int**, int**, int**);
		
		int **segmentar();
		void encerar();
		void ingresar();
		void procesar();
		void toString();
	
	private: 
		Matriz matriz;
};
