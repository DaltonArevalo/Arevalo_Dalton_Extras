#include "operaciones.h"
#include <stdlib.h>
#include <string> 
#include <cstdlib>

Operaciones::Operaciones(){
	
}

Operaciones::Operaciones(int* vec){
	Vector vector;
	vector.setVec(vec);
}

void Operaciones::encerar(){
	int *vec = vector.getVec();
	
	for(int i=0; i<10; i++){
		vec[i] = 0;
	}
}


int Operaciones::procesar(){
	int *vec = vector.getVec();
	int suma = 0;
	
	for(int i=0; i<10; i++){
		suma += vec[i];
	}
	
	return suma; 
}

void Operaciones::ingresar(){
	int *vec = vector.getVec();

    for (int i = 0; i < 10; i++) {
        int valor;

        std::cout << "ingrese el elemento para vector[" << i << "]: ";
        std::cin >> valor;

        vec[i] = valor;
    }
}

void Operaciones::generar(){
	int *vec = vector.getVec();
	
	for(int i=0; i<10; i++){
		vec[i] = rand() % 11;
	}
}

void Operaciones::toString(){
	int *vec = vector.getVec();
	std::cout << "Cifras del Arreglo Rondomico" << std::endl;
	
	for (int i = 0; i < 10; i++) {
        std::cout << "vector[" << i + 1 << "] = " << vec[i] << std::endl;
    }
	
}


