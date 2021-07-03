#include <iostream>
#include "vector.h"

Vector::Vector(){
	
}

Vector::Vector(int *vect){
	setVec(vect);
}

void Vector::setVec(int *vect){
	for(int i=0; i<10; i++){
		vec[i] = vect[i];
		//this->vec[i] = vect[i];
	}
}

int *Vector::getVec(){
	return vec;
}
