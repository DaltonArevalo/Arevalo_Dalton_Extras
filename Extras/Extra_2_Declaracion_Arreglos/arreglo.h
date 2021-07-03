#pragma once

class Arreglo{
    private:
        int arreglo[10];
        int suma;
    
    public:
        Arreglo() = default;
        Arreglo(int [], int);

        void set_suma(int suma);
        int get_suma();
};