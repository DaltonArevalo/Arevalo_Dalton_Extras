#pragma once
#include"Matriz.h"
class Operaciones {
	private:
		Matriz m;
	public:
		Operaciones();
		Operaciones(int**,int**,int**);
		int** segmentar();
		void encerar();
		void ingresar(int **);
		void calcular();
		void imprimir(int **);
};
