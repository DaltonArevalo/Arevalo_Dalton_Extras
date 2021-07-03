#pragma once
#include "nodo.h"
#include <functional>

class ListaDobleEnlazada {
public:
    ListaDobleEnlazada() = default;
    void insertar(int valor);
    void insertar_inicio(int valor);
    void insertar_en(int indice, int valor);
    void eliminar(int indice);
    void recorrer(std::function<void(int, int)> callback);
    int get_tamanio();

private:
    Nodo *ultimo_nodo();
    Nodo *obtener_nodo(int indice);

    Nodo *cabeza = nullptr;
    int tamanio = 0;
};
