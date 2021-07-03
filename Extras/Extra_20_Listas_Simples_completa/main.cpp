#define NOMINMAX 1

#include <iostream>
#include <limits>
#include <conio.h>
#include "menu.h"
#include "menu_option.h"
#include "lista.h"
#include "nodo.h"

int main(int argc, char **argv){
    Menu menu("Listas Simples - Menu");

    int num = 0;
    Nodo* aux = NULL, *temp = NULL;
    List* cadena = new List();

    menu.add_option(MenuOption("Agregar elemento", [&](MenuOptionArguments args) {
        std::cout << "Estas a punto de ingresar un elemento a la lista" << std::endl;
        aux = new Nodo();
        std::cout << "Ingrese un numero:  ";
        std::cin >> num;
        aux->set_dato(num);
        cadena->agregar(aux);
        std::cout << "Numero almacenado exitosamente";
    }));

    menu.add_option(MenuOption("Mostrar elementos", [&](MenuOptionArguments args) {
        std::cout << "Mostrar.. \n";
            temp = cadena->get_cabeza();
            while (temp != NULL) {
                std::cout << temp->get_dato() << " | ";
                temp = temp->get_next();
            }
    }));

    menu.add_option(MenuOption("Buscar elemento", [&](MenuOptionArguments args) {
        std::cout << "Buscar.. \n";
            std::cout << "Ingrese el valor que desea buscar: ";
            std::cin >> num;
            std::cout << std::endl;
            temp = cadena->buscar(num);
            if (temp != NULL) {
                std::cout << "El numero " << num << " fue hallado" << std::endl;
                std::cout << temp->get_dato() << " fue hallado en la direccion de memoria " << &temp <<std::endl;
            }
            else {
                std::cout << "Numero no encontrado"<<std::endl;
            }
            cadena->buscar(num);
    }));

    menu.add_option(MenuOption("Eliminar", [&](MenuOptionArguments args) {
       std::cout << "Eliminar.. \n";
            std::cout << "Ingrese el valor que desea eliminar: ";
            std::cin >> num;
            temp = cadena->buscar(num);
            if (temp != NULL) {
                cadena->eliminar(num);
                std::cout << "El numero " << num << " fue hallado y eliminado" << std::endl;
            }
            else {
                std::cout << "Numero no encontrado, no se puede eliminar" << std::endl;
            }
    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}