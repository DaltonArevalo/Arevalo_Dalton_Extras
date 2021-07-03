#include "operaciones.h"
#include <malloc.h>
#include <stdio.h>

Operaciones::Operaciones(int** matriz_1, int** matriz_2, int** matriz_r, int _dim){
	Matriz matriz;
	this->matriz.getDim() = _dim;
	matriz.setMatriz_1(matriz_1, dim);
	matriz.setMatriz_2(matriz_2, dim);
	matriz.setMatriz_r(matriz_r, dim);
}

int** Operaciones::segmentar(){
	int** matriz, j;
    matriz = (int**)malloc(this->matriz.getDim() * sizeof(int*));
    for (j = 0; j < this->matriz.getDim(); j++) {
        *(matriz + j) = (int*)malloc(this->matriz.getDim() * sizeof(int));
    }
    return matriz;
}

void Operaciones::encerar(){
	int i, j,**matriz;
    for (i = 0; i < this->matriz.getDim(); i++)
        for (j = 0; j < this->matriz.getDim(); j++)
            *(*(matriz + i) + j) = 0;
    this->matriz.setMatriz_1(matriz,this->);
    this->matriz.setMatriz_2(matriz,);
    this->matriz.setMatriz_3(matriz,);
}

Operaciones::ingresar(){
	
}

Operaciones::procesar(){
	
}

Operaciones::toString(){
	
}

