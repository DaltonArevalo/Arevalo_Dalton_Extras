#include "nodo.h"

Nodo::Nodo(int _valor) {
    this->valor = _valor;
}

Nodo *Nodo::get_anterior() {
    return anterior;
}

void Nodo::set_anterior(Nodo *nodo) {
    this->anterior = nodo;
}

Nodo *Nodo::get_siguiente() {
    return siguiente;
}

void Nodo::set_siguiente(Nodo *nodo) {
    this->siguiente = nodo;
}

int Nodo::get_valor() {
    return valor;
}

void Nodo::set_valor(int _valor) {
    this->valor = valor;
}
