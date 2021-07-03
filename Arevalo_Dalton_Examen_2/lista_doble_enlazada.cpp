#include "lista_doble_enlazada.h"
#include <stdexcept>
#include <exception>

void ListaDobleEnlazada::insertar(int valor) {
    Nodo *nodo = new Nodo(valor);
    Nodo *ultimo;

    // incrementamos el tamaño de la lista
    tamanio++;

    if (cabeza == nullptr) {
        this->cabeza = nodo;
        return;
    }

    // obtenemos la cola
    ultimo = ultimo_nodo();
    
    // definir el nodo siguiente de la cola, ahora
    // el nuevo nodo sera la cola
    ultimo->set_siguiente(nodo);

    // definimos el nodo anterior del nuevo nodo insertado
    nodo->set_anterior(ultimo);
}

void ListaDobleEnlazada::insertar_inicio(int valor) {
    // si la cabeza es nula, entonces insertamos el nuevo elemento solamente
    if (cabeza == nullptr) {
        return insertar(valor);
    }

    Nodo *nodo = new Nodo(valor);
    Nodo *temporal = cabeza;

    cabeza = nodo;
    cabeza->set_siguiente(temporal);
    temporal->set_anterior(cabeza);
    tamanio++;
}

void ListaDobleEnlazada::insertar_en(int indice, int valor) {
    if (indice < 0 || indice > tamanio) {
        throw std::invalid_argument("indice fuera de los limites de la lista");
    }

    if (indice == 0 || tamanio == 0) {
        return insertar_inicio(valor);
    } else if (indice == tamanio) {
        return insertar(valor);
    }

    Nodo *actual = obtener_nodo(indice);
    Nodo *anterior = actual->get_anterior();
    Nodo *siguiente = actual->get_siguiente();

    Nodo *nodo = new Nodo(valor);

    anterior->set_siguiente(nodo);
    nodo->set_siguiente(actual);
    nodo->set_anterior(anterior);
    actual->set_anterior(nodo);

    tamanio++;
}

void ListaDobleEnlazada::eliminar(int indice) {
    if (indice < 0 || indice >= tamanio) {
        throw std::invalid_argument("index out of bounds");
    }
    
    if (indice == 0) {
        Nodo *temporal = cabeza;
        cabeza = cabeza->get_siguiente();
        cabeza->set_anterior(nullptr);
        delete temporal;
    } else if (indice == tamanio - 1) {
        Nodo *nodo = ultimo_nodo();
        Nodo *anterior = nodo->get_anterior();
        
        anterior->set_siguiente(nullptr);
        delete nodo;
    } else {
        Nodo *actual = obtener_nodo(indice);
        Nodo *anterior = actual->get_anterior();
        Nodo *siguiente = actual->get_siguiente();
        
        anterior->set_siguiente(siguiente);
        siguiente->set_anterior(anterior);
        delete actual;
    }

    tamanio--;
}

void ListaDobleEnlazada::recorrer(std::function<void(int, int)> callback) {
    Nodo *temporal = cabeza;
    int indice = 0;

    while (temporal != nullptr) {
        callback(temporal->get_valor(), indice++);
        temporal = temporal->get_siguiente();
    }
}

Nodo *ListaDobleEnlazada::ultimo_nodo() {
    Nodo *temporal = cabeza;

    if (temporal == nullptr) {
        return nullptr;
    }

    while (temporal->get_siguiente() != nullptr) {
        temporal = temporal->get_siguiente();
    }

    return temporal;
}

Nodo *ListaDobleEnlazada::obtener_nodo(int indice) {
    if (indice < 0 || indice >= tamanio) {
        throw std::invalid_argument("indice fuera de los limites de la lista");
    }

    if (indice == 0) {
        return cabeza;
    }

    int indice_actual = 0;
    Nodo *ultimo = cabeza;

    while (ultimo->get_siguiente() != nullptr) {
        if (indice_actual == indice) {
            break;
        }

        indice_actual++;
        ultimo = ultimo->get_siguiente();
    }

    return ultimo;
}