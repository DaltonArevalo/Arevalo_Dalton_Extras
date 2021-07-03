#define NOMINMAX 1

#include <iostream>
#include <limits>
#include <conio.h>
#include "menu.h"
#include "menu_option.h"
#include "lista_doble_enlazada.h"
#include "nodo.h"

int main(int argc, char **argv){
    Menu menu("Listas Dobles - Menu");

    int num = 0, num2 = 0;
    ListaDobleEnlazada lista;

    menu.add_option(MenuOption("Agregar elemento por la cabeza", [&](MenuOptionArguments args) {
        std::cout << "Estas a punto de ingresar un elemento a la lista por la cabeza" << std::endl;
        std::cout << "Ingrese un numero:  ";
        std::cin >> num;
        lista.insertar_inicio(num);
        std::cout << "Numero almacenado exitosamente";
    }));

    menu.add_option(MenuOption("Agregar elemento por la cola", [&](MenuOptionArguments args) {
        std::cout << "Estas a punto de ingresar un elemento a la lista por la cola" << std::endl;
        std::cout << "Ingrese un numero:  ";
        std::cin >> num;
        lista.insertar(num);
        std::cout << "Numero almacenado exitosamente";
    }));

    menu.add_option(MenuOption("Agregar elemento por un indice", [&](MenuOptionArguments args) {
        std::cout << "Estas a punto de ingresar un elemento a la lista por el indice" << std::endl;
        std::cout << "Ingrese el indice:  ";
        std::cin >> num2;
        std::cout << "Ingrese un numero:  ";
        std::cin >> num;
        lista.insertar_en(num2,num);
        std::cout << "Numero almacenado exitosamente";
    }));

    menu.add_option(MenuOption("Mostrar elementos", [&](MenuOptionArguments args) {
        std::cout << "Elementos de la Lista" << std::endl;
        lista.recorrer([](int valor, int indice) {
        std::cout 
            << "indice:" << "[" << indice << "]"
            << " valor: " << valor << std::endl;
        });
    }));

    menu.add_option(MenuOption("Eliminar", [&](MenuOptionArguments args) {
        std::cout << "Eliminar.. \n";
        std::cout << "Ingrese el indice del elemento: ";
        std::cin >> num;
        lista.eliminar(num);
    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}
    /*
    lista.recorrer([&suma](int valor, int indice) {
        suma += valor;
    });
    */

