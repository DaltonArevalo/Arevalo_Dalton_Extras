#pragma once
#include <iostream>

class Matriz{
	private:
		int filas;
		int columnas;
		int matriz_1[filas][columnas];
		int matriz_2[filas][columnas];
		int matriz_r[filas][columnas];
	public: 
		Matriz();
		Matriz(int**, int**, int**);
		
		int (*getMatriz_1())[filas];
		void setMatriz_1(int**);
		
		int (*getMatriz_2())[filas];
		void setMatriz_2(int**);
		
		int (*getMatriz_r())[filas];
		void setMatriz_r(int**);
};

