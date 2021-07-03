#include <iostream>
#include <string>
#include "Nodo.h"

Nodo::Nodo() {
	dato = 0;
	next = NULL;   ///OJO Q EL PUNTERO DEL NODO DEBE SER NULL
}
void Nodo::set_dato(int dato_) {
	dato = dato_;
}
void Nodo::set_next(Nodo* next_) {
	next = next_;
}
int Nodo::get_dato() {
	return dato;
}
Nodo* Nodo::get_next() {
	return next;
}