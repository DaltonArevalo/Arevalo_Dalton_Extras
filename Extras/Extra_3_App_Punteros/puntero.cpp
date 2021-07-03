#include "puntero.h"
#include <string>

Puntero::Puntero(std::string mensaje, std::string* puntero){
    this->mensaje = mensaje;
    this->puntero = puntero;
}

std::string Puntero::get_mensaje(){
    return mensaje;
}

void Puntero::set_mensaje(std::string mensaje){
    this->mensaje = mensaje;
}

std::string* Puntero::get_puntero(){
    return puntero;
}

void Puntero::set_puntero(std::string* puntero){
    this->puntero = puntero;
}

