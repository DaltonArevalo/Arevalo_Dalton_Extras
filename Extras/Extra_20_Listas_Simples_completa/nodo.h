#pragma once
class Nodo {

private:
	int dato;
	Nodo* next;

public:
	
	Nodo();
	void set_dato(int);
	void set_next(Nodo*);
	int get_dato();
	Nodo* get_next();

};
