/***********************************************************************
 * Module:  Fecha.h
 * Author:  DALTON AREVALO
 * Modified: jueves, 3 de junio de 2021 12:47:06
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Fecha_h)
#define __Class_Diagram_1_Fecha_h

class Fecha
{
public:
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getAnio(void);
   void setAnio(int newAnio);
   Fecha(int _dia, int _mes, int _anio);
   ~Fecha();

protected:
private:
   int dia;
   int mes;
   int anio;


};

#endif