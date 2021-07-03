#include "aplicacion.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "puntero.h"


Aplicacion &Aplicacion::get_instance() {
    static auto &&instance = Aplicacion();
    return instance;
}

void Aplicacion::run() {
    int opcion;

    do {
        system("cls");
        std::cout << "Uso de Punteros" << std::endl << std::endl;
        std::cout << "1: Mostrar mensaje" << std::endl;
        std::cout << "2: Mostrar direccion del mensaje" << std::endl;
        std::cout << "3: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 3);

        switch (opcion) {
            case 1: {
                std::string mensaje;

                Puntero puntero_mensaje;

                std::cout << "Ingrese el mensaje: ";
                std::cin >> mensaje;
                puntero_mensaje.set_mensaje(mensaje);

                std::cout << puntero_mensaje.get_mensaje() << std::endl;
            }
            break;
            case 2: {
                std::string mensaje;
                std::string* puntero;

                Puntero puntero_mensaje;

                std::cout << "Ingrese el mensaje: ";
                std::cin >> mensaje;

                puntero = &mensaje;
                
                puntero_mensaje.set_mensaje(mensaje);

                std::cout << puntero_mensaje.get_mensaje() << std::endl;
                std::cout << "La direccion del mensaje es: " << puntero << std::endl;
            }
            break;

        }

        if (opcion != 3) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 3);
}
