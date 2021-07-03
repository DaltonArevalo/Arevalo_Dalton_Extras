#pragma once
#include <iostream>

class Matriz{
	private:
		int matriz_1[10][10];
		int matriz_2[10][10];
		int matriz_r[10][10];
	public: 
		Matriz();
		Matriz(int**, int**, int**);
		
		int (*getMatriz_1())[10];
		void setMatriz_1(int**);
		
		int (*getMatriz_2())[10];
		void setMatriz_2(int**);
		
		int (*getMatriz_r())[10];
		void setMatriz_r(int**);
};

