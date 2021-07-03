#pragma once
#include <iostream>
#include "Nodo.h"

class List {

private:
	Nodo* cabeza;

public:
	List();

	Nodo* get_cabeza();
	void set_cabeza(Nodo*);

	Nodo* get_ultimoNodo();
	Nodo* buscar(int);  /// buscar un dato o valor contenido en algun nodo

	void agregar(Nodo*);
	void eliminar(int);  ///eliminar un dato contenido en algun nodo


};
