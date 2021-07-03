#pragma once
#include <sstream>
#include <stdexcept>
#include <limits>
#include "person.h"

class PersonOperation{
    private:
        Person cliente;
    public:
        PersonOperation()= default;
        static bool validateDNI(Person cliente);
        static int toInt(std::string s);
        static int encript(Person s, int n);
};

int PersonOperation::toInt(std::string s){
    std::stringstream geek(s);
    int aux = 0;
    geek>>aux;
    return aux;
}

bool PersonOperation::validateDNI(Person cliente){
    if (cliente.getDNI().length()==10)
    {
        if(0 <= toInt(cliente.getDigitDNI(0,2)) && toInt(cliente.getDigitDNI(0,2)) <25){
            int sumaPar= 0;
            for(int i = 0; i<4; i++){
                sumaPar += toInt(cliente.getDigitDNI(2*i+1,1));
            }
            int sumaImpar = 0;
            for(int i=0; i<5; i++){
                int aux= 2* toInt(cliente.getDigitDNI(2*i,1));
                if(aux > 9){
                    aux-=9;
                }else{
                    aux= aux;
                }
                sumaImpar+=aux;
            }
            int sumaTotal= sumaImpar +sumaPar;
            int comp = sumaTotal%10;
            if(comp == 0){
                if(comp == toInt(cliente.getDigitDNI(9,1))){
                    return true;
                }
                else{
                    return false;
                }
            }else{
                int comp2 = 10 - comp;
                if(comp2 == toInt(cliente.getDigitDNI(9,1)) ){
                    return true;
                }else{
                    return false;
                }
            }
        }else{
            throw "La cedula no es real pues no pertenece a ninguna provincia del pais";
        }
    }else{
        throw "La cedula debe contener 10 digitos ";
    }   
}

int PersonOperation::encript(Person s, int n){
    if(n == s.getDNI().length()){
        return 0;
    }else{
        return toInt(s.getDigitDNI(n,1)) + encript(s,n+1);
    }
}