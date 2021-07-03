#include "multiplicacion.h"

Multiplicacion::Multiplicacion(){}

Multiplicacion::Multiplicacion(int** m1, int** m2, int** mr){
	matriz.setMatriz_1(m1);
	matriz.setMatriz_2(m2);
	matriz.setMatriz_r(mr);
}

void Multiplicacion::multiplicar(){
	int (*m1)[10] = matriz.getMatriz_1();
	int (*m2)[10] = matriz.getMatriz_2();
	int (*mr)[10] = matriz.getMatriz_r();
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			m1[i][j] = 1;
			m2[i][j] = 1;
			mr[i][j] = 0;
			for(int k=0 ; k < 10; k++){
				mr[i][j] = mr[i][j] + (m1[i][k] * m2[j][k]);
			}
		}
	}
}

void Multiplicacion::toString(){
	int (*mr)[10] = matriz.getMatriz_r();
	
	std::cout << "La matriz es:" << std::endl;

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			std::cout << mr[i][j] << " ";
		}

		std::cout << std::endl;
	}
}
