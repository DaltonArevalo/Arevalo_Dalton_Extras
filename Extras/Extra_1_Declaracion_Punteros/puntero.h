#pragma once
#include <string>
#include <iostream>

class Puntero{
    private:
        std::string mensaje;
        std::string* puntero;
    
    public:
        Puntero() = default;
        Puntero(std::string, std::string*);

        void set_mensaje(std::string mensaje);
        std::string get_mensaje();

        void set_puntero(std::string* puntero);
        std::string* get_puntero();
};
