#pragma once
#include <string>
#include <cstring>
#include "date.h"

class Person{
    private:
        std::string name;
        std::string lastName;
        std::string dni;
        std::string email;
        Date birthday;
        int age;
    public:
        Person();
        Person(std::string name, std::string lastName, std::string dni);
        std::string getName();
        void setName(std::string name);
        std::string getLastname();
        void setLastname(std::string lastname);
        std::string getDNI();
        void setDNI(std::string dni);
        std::string getEmail();
        void setEmail(std::string email);
        Date getBirthday();
        void setBirthday(Date birthday);
        int getAge();
        void setAge(int age);
        std::string getDigitDNI(int from, int to);
        void fillByConsole();
};

Person::Person(){
}

Person::Person(std::string name, std::string lastName, std::string dni){
    this->name = name;
    this->lastName = lastName;
    this->dni = dni;
}

std::string Person::getName(){
    return this->name;
}

std::string Person::getLastname(){
    return this->lastName;
}

std::string Person::getDNI(){
    return this->dni;
}

void Person::setName(std::string name){
    this->name=name;
}

void Person::setLastname(std::string lastName){
    this->lastName= lastName;
}

void Person::setDNI(std::string dni){
    this->dni=dni;
}

std::string Person::getDigitDNI(int from, int to){
    return this->dni.substr(from, to);
}

Date Person::getBirthday(){
    return this->birthday;
}

void Person::setBirthday(Date birthday){
    this->birthday = birthday;
}

int Person::getAge(){
    return this->age;
}

void Person::setAge(int age){
    this->age = age;
}

void Person::fillByConsole(){
    std::string aux;
    std::getline(std::cin,aux);
    std::cout <<"Escriba sus nombres: ";
    std::getline(std::cin,aux);
    this->setName(aux);
    std::cout <<"Escriba sus apellidos: ";
    //std::string lastnames;
    std::getline(std::cin, aux);
    this->setLastname(aux);
    std::cout <<"Escriba su numero de cedula: ";
    //std::string dna;
    std::getline(std::cin, aux);
    this->setDNI(aux);
    std::cout <<"Escriba su fecha de nacimiento: \n";
    //std::getline(std::cin, aux);
    Date auxDate = Date::read("");
    this->setBirthday(auxDate);
}