#include <iostream>
#include "lista.h"

List::List() {
	cabeza = NULL;
}

Nodo* List::get_cabeza() {
	return cabeza;
}
void List::set_cabeza(Nodo* cabeza_) {
	cabeza = cabeza_;
}

Nodo* List::get_ultimoNodo() {
	Nodo* ultimo = get_cabeza();
	while (ultimo->get_next() != NULL) {
		ultimo = ultimo->get_next();
	}
	return ultimo;
}

void List::agregar(Nodo* nuevo) {
	if (get_cabeza() == NULL)
		set_cabeza(nuevo);
	else
		get_ultimoNodo()->set_next(nuevo);
}

Nodo* List::buscar(int dato_) {
	Nodo* busqueda = get_cabeza();
	while ((busqueda != NULL) && (busqueda->get_dato() != dato_)) {
		busqueda = busqueda->get_next();
	}
	return busqueda;
}

void List::eliminar(int dato_) {
	Nodo* busqueda = get_cabeza();
	Nodo* anterior = NULL;
	if (busqueda->get_dato() == dato_)
		set_cabeza(get_cabeza()->get_next());
	else {
		while ((busqueda != NULL)&&(busqueda->get_dato() != dato_)){
			anterior = busqueda;
			busqueda = busqueda->get_next();
		}
		if (busqueda != NULL) {
			anterior->set_next(busqueda->get_next());
		}
	}
	delete busqueda;
}
