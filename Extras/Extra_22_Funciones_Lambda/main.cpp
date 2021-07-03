#include <iostream>
#include <functional>
//algoritmo libreria

using namespace std;

void llamar(function<int(int, int)> nombre_funcion_llamar);

int main(){
   int c = 5;
   /*function<int(int, int)> mi_funcion = [](int a, int b)->int{
      return a+b;
   };*/

   // lo mismo pero la declaro de una vez

   llamar([&](int a, int b)->int{
      c = 2;
      return a+b+c;
   });

   return 0;
}

void llamar(function<int(int, int)> nombre_funcion_llamar){
   int a=1, b=2;
   int resultado = nombre_funcion_llamar(a,b);
   cout << resultado << endl;
}