/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: 
 * 
 * @date xx/xx/2021
 * @author Diego Jimenez
 */
#include <iostream>
#include "dcList.h"
#include "person.h"
#include "personOperation.h"
//#include <fmt/chrono.h>

// include_directories("${PROJECT_SOURCE_DIR}/external/date/include")

// add_executable(ed main.cpp node.h dcList.h person.h personOperation.h date.h date.cpp ${PROJECT_SOURCES})


int main(int, char**) {
    // std::cout << "Hello, world!\n";
    
    // Person p1("carolina", "gaitan", "1745166107");
    // Person p2("carmen", "ramirez","1745126202");
    // DoubleCircularList<Person> dcl;
    // dcl.addFirst(p1);
    // dcl.addFirst(p2);
    // dcl.for_each([&](Person aux){
    //     std::cout<<aux.getName() <<"\t" <<aux.getLastname()<< std::endl;
    // });
    std::cout << "Programa para manejar listas circulares"<<std::endl;
    int select = 0;    
    DoubleCircularList<Person> dcl;
    Person p1("Carolina Musika", "Gaitan Marin", "1745166107");
    Person p2("Andrea Katalina", "Santana Zambrano","1745126202");
    Date d1(02,10,1999);
    p1.setBirthday(d1);
    Date d2(05,11,1998);
    p2.setBirthday(d2);
    dcl.addFirst(p1);
    dcl.addFirst(p2);
    do{
        std::cout << "1. Agregar elementos " <<std::endl;
        std::cout << "2. Imprimir elementos " <<std::endl;
        std::cout << "3. Eliminar elemento" << std::endl;
        std::cout << "Presione 0 para salir" << std::endl;
        std::cin >> select;
        if(select ==1){
            Person p;
            p.fillByConsole();
            dcl.addFirst(p);
        }else if (select ==2)
        {
            dcl.for_each([](Person p){
                //std::string dateF = fmt::format(
                //    "{:02d}/{:02d}/{:02d}", p.getBirthday().getDay(), p.getBirthday().getMonth(), p.getBirthday().getYear()
                //);
                std::cout<< p.getName() <<"\n"
                << p.getLastname() << "\n"
                << p.getDNI() <<std::endl;
                printf("%02d / %02d / %d \n",
                p.getBirthday().getDay(), p.getBirthday().getMonth(), p.getBirthday().getYear());
                // std::cout.fill('0');
                // std::cout.width(1);
            });
            system("pause");
        }else if (select ==3)
        {
            /* code */
        }
        
        
        system("cls");
    }while (select != 0);
    
}