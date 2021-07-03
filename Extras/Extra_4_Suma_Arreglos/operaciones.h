#pragma once
#include "vector.h"

class Operaciones{
	public:
		Operaciones();
		Operaciones(int *vec);
		void encerar(/*int *vec*/);
		int procesar(/*int *vec*/);
		void ingresar();
		void generar(/*int *vec*/);
		void toString();
	
	private: 
		Vector vector;
};



