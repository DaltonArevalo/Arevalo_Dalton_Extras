#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"



int main()
{

	int** a, **b, **c;
	Matriz m{ a,b,c,4 };
	Operaciones op;
	a = op.segmentar();
	b = op.segmentar();
	c = op.segmentar();
	op.encerar();
	op.ingresar(a);
	op.ingresar(b);
	op.ingresar(c);
	op.imprimir(a);
	op.calcular();



}
