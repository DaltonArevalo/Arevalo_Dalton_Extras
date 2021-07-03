#include <iostream>
#include "matriz.h"

Matriz::Matriz() {
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			*(*(matriz_1+i)+j) = 0;
			*(*(matriz_2+i)+j) = 0;
			*(*(matriz_r+i)+j) = 0;
		}
	}
}

Matriz::Matriz(int** m1, int** m2, int** mr, int dim){
	setMatriz_1(m1, dim);
	setMatriz_2(m2, dim);
	setMatriz_r(mr, dim);
}

void Matriz::setDim(int dim){
	this->dim = dim;
}

int Matriz::getDim(){
	return dim;
}

void Matriz::setMatriz_1(int **_m1, int dim){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			*(*(matriz_1+i)+j) = **_m1;
		}
	}
}

int *(*Matriz::getMatriz_1()){
	return matriz_1;
}

void Matriz::setMatriz_2(int **_m2, int dim){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			*(*(matriz_2+i)+j) = **_m2;
		}
	}
}

int *(*Matriz::getMatriz_2()){
	return matriz_2;
}

void Matriz::setMatriz_r(int **_mr, int dim){
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			*(*(matriz_r+i)+j) = **_mr;
		}
	}
}

int *(*Matriz::getMatriz_r()){
	return matriz_r;
}
