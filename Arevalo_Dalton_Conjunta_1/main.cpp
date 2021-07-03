#define NOMINMAX 1

#include <iostream>
#include <limits>
#include <conio.h>
#include "menu.h"
#include "menu_option.h"
#include "lista_simple.h"
#include "nodo.h"
#include "utils.h"

int pedir_cedula(int id)
{
    cout<<"Ingresar numero de cedula: ";
    cin>>id;
    return id;
}
int validacion(int id)
{
    if(id<999999999)
        do{
        cout<<"Error!!!faltan numeros en la cedula ingresada!"<<endl;
        cout<<"Ingresar numero de cedula: ";
        cin>>id;
        }while(id<999999999);
        return id;
}

void encriptar_cifras_cedula(int id,int *ptr_a,int *ptr_b,int *ptr_c,int *ptr_d,int *ptr_e,int *ptr_f,int *ptr_g,int *ptr_h,int *ptr_i,int *ptr_j){
    int cedula=id, suma = 0;
        *ptr_a=cedula/1000000000;
        cedula=cedula-(*ptr_a*1000000000);
        *ptr_b=cedula/100000000;
        cedula=cedula-(*ptr_b*100000000);
        *ptr_c=cedula/10000000;
        cedula=cedula-(*ptr_c*10000000);
        *ptr_d=cedula/1000000;
        cedula=cedula-(*ptr_d*1000000);
        *ptr_e=cedula/100000;
        cedula=cedula-(*ptr_e*100000);
        *ptr_f=cedula/10000;
        cedula=cedula-(*ptr_f*10000);
        *ptr_g=cedula/1000;
        cedula=cedula-(*ptr_g*1000);
        *ptr_h=cedula/100;
        cedula=cedula-(*ptr_h*100);
        *ptr_i=cedula/10;
        cedula=cedula-(*ptr_i*10);
        *ptr_j=cedula/1;
        cedula=cedula-(*ptr_j*1);
        suma = *ptr_a + *ptr_b + *ptr_c + *ptr_d + *ptr_e + *ptr_f + *ptr_g + *ptr_h + *ptr_i + *ptr_j;
        std::cout << suma << std::endl;
}

void separar_cifras_cedula(int id,int *ptr_a,int *ptr_b,int *ptr_c,int *ptr_d,int *ptr_e,int *ptr_f,int *ptr_g,int *ptr_h,int *ptr_i,int *ptr_j)
{
        int cedula=id;
        *ptr_a=cedula/1000000000;
        cedula=cedula-(*ptr_a*1000000000);
        *ptr_b=cedula/100000000;
        cedula=cedula-(*ptr_b*100000000);
        *ptr_c=cedula/10000000;
        cedula=cedula-(*ptr_c*10000000);
        *ptr_d=cedula/1000000;
        cedula=cedula-(*ptr_d*1000000);
        *ptr_e=cedula/100000;
        cedula=cedula-(*ptr_e*100000);
        *ptr_f=cedula/10000;
        cedula=cedula-(*ptr_f*10000);
        *ptr_g=cedula/1000;
        cedula=cedula-(*ptr_g*1000);
        *ptr_h=cedula/100;
        cedula=cedula-(*ptr_h*100);
        *ptr_i=cedula/10;
        cedula=cedula-(*ptr_i*10);
        *ptr_j=cedula/1;
        cedula=cedula-(*ptr_j*1);
}
void calculo_pares_impares(int pares,int impares,int dec,int total, int id,int *ptr_a,int *ptr_b,int *ptr_c,int *ptr_d,int *ptr_e,int *ptr_f,int *ptr_g,int *ptr_h,int *ptr_i,int *ptr_j)
{
    if (id>9999999999){
                cout<<"Error!!!sobran numeros en la cedula ingresada!"<<endl;
        }else{
                pares=*ptr_b+*ptr_d+*ptr_f+*ptr_h;
                *ptr_a=*ptr_a*2;
                if (*ptr_a>9){
                        *ptr_a=(*ptr_a%10)+(*ptr_a/10);
                }
                *ptr_c=*ptr_c*2;
                if (*ptr_c>9){
                        *ptr_c=(*ptr_c%10)+(*ptr_c/10);
                }
                *ptr_e=*ptr_e*2;
                if (*ptr_e>9){
                        *ptr_e=(*ptr_e%10)+(*ptr_e/10);
                }
                *ptr_g=*ptr_g*2;
                if (*ptr_g>9){
                        *ptr_g=(*ptr_g%10)+(*ptr_g/10);
                }
                *ptr_i=*ptr_i*2;
                if (*ptr_i>9){
                        *ptr_i=(*ptr_i%10)+(*ptr_i/10);
                }
                impares=*ptr_a+*ptr_c+*ptr_e+*ptr_g+*ptr_i;
                total=pares+impares;
                while (dec-total!=*ptr_j && dec<total+10){
                        dec=dec+10;
                }
                if (dec-total==*ptr_j){
                        cout<<"EL NUMERO DE CEDULA ES VALIDO"<<endl;
                }else {
                        cout<<"EL NUMERO DE CEDULA NO EXISTE"<<endl;
                        cout<<"Fin proceso...."<<endl;
                }
        }
}

int main(int argc, char **argv){
    Menu menu("Listas Simples - Menu - Dalton Arevalo");

    ListaSimple<int> lista;

    menu.add_option(MenuOption("- Agregar elemento por la cabeza", [&](MenuOptionArguments args) {
        std::cout << "Estas a punto de ingresar un elemento a la lista" << std::endl;
        do {
            int numero = read_int("Ingrese un numero o c para cancelar: ");

            if (numero == INT_MAX) {
                break;
            }

            lista.insertar_inicio(numero);

        } while (true);
    }));

    menu.add_option(MenuOption("- Agregar una persona (Cedula se maneja en lista)", [&](MenuOptionArguments args) {
        long int cedula=0;
        int pares,impares,total,dec=0,a,b,c,d,e,f,g,h,i,j;
        cedula=pedir_cedula(cedula);
        cedula=validacion(cedula);
        lista.insertar_final(cedula);
        separar_cifras_cedula(cedula,&a,&b,&c,&d,&e,&f,&g,&h,&i,&j); //Se cambia el valor mediante punteros
        calculo_pares_impares(pares,impares,dec,total,cedula,&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
        std::cout << "La cedula encriptada es: ";
        encriptar_cifras_cedula(cedula,&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
    }));

    menu.add_option(MenuOption("- Encontrar numero en lista", [&](MenuOptionArguments args) {
        int numero = read_int("Ingrese el numero que quiere buscar: ");
        Nodo<int>* encontrado = lista.buscar(numero);

        if (encontrado == nullptr) {
		cout << "No se encontro en la lista!!!" << endl;
	    }else {
		cout << "Se encontro el elemento: " << encontrado->get_valor() << endl;
	    }
    }));

    menu.add_option(MenuOption("- Modificar valores lista", [&](MenuOptionArguments args) {
        lista.recorrer_nodos([](Nodo<int> *nodo) {
		int valor = nodo->get_valor();
		nodo->set_valor(valor + valor);
	    });

        lista.recorrer([](int valor) {
		cout << "=> " << valor << endl;
	    });
    }));

    menu.add_option(MenuOption("- Mostrar lista", [&](MenuOptionArguments args) {
        std::cout << "Lista Simple" << std::endl;
        lista.imprimir();
    }));

    menu.add_option(MenuOption("- Tamanio lista", [&](MenuOptionArguments args) {
        if(lista.tamanio() == 0){
            std::cout << "Lista vacia" << std::endl;
        }else{
            std::cout << "El tamanio de la lista es: " << lista.tamanio() << std::endl;
        }
    }));

    menu.add_option(MenuOption("- Eliminar", [&](MenuOptionArguments args) {
        std::cout << "Se eliminara elemento de la lista por indice" << std::endl;
        std::cout << "Lista de elementos" << std::endl;
        
        int i = 0;

        lista.recorrer([&](int valor) {
		cout <<"[" << i++ << "]"  "-> " << valor << endl;
	    });

        int numero = read_int("Ingrese el indice del numero que quiere eliminar: ");
        lista.eliminar(numero);
    }));

    menu.add_option(MenuOption("- Salir", [&](MenuOptionArguments args) {
        std::cout << "Salio con exito del programa..." << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}
