#pragma once
#include <iostream>

class Matriz{
	private:
		int dim;
		int** matriz_1;
		int** matriz_2;
		int** matriz_r;
	public: 
		Matriz();
		Matriz(int**, int**, int**, int);
		
		int getDim();
		void setDim(int);
		
		int *(*getMatriz_1());
		void setMatriz_1(int**, int);
		
		int *(*getMatriz_2());
		void setMatriz_2(int**, int);
		
		int *(*getMatriz_r());
		void setMatriz_r(int**, int);
};
