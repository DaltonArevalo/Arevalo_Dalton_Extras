#include <iostream>
#include "matriz.h"

Matriz::Matriz() {
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			matriz_1[i][j] = 0;
			matriz_2[i][j] = 0;
			matriz_r[i][j] = 0;
		}
	}
}

Matriz::Matriz(int fila, int columna, int** m1, int** m2, int** mr){
	this->filas = fila;
	this->columnas = columna;
	setMatriz_1(m1);
	setMatriz_2(m2);
	setMatriz_r(mr);
}

void Matriz::setMatriz_1(int **_m1){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			matriz_1[i][j] = _m1[i][j];
		}
	}
}

int (*Matriz::getMatriz_1())[filas]{
	return matriz_1;
}

void Matriz::setMatriz_2(int **_m2){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			matriz_2[i][j] = _m2[i][j];
		}
	}
}

int (*Matriz::getMatriz_2())[filas]{
	return matriz_2;
}

void Matriz::setMatriz_r(int **_mr){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			matriz_r[i][j] = _mr[i][j];
		}
	}
}

int (*Matriz::getMatriz_r())[filas]{
	return matriz_r;
}
