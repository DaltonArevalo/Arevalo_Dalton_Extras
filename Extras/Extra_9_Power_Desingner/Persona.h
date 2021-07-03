/***********************************************************************
 * Module:  Persona.h
 * Author:  DALTON AREVALO
 * Modified: jueves, 3 de junio de 2021 12:44:18
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Persona_h)
#define __Class_Diagram_1_Persona_h

#include <Fecha.h>

class Persona
{
public:
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   Fecha getFecha(void);
   void setFecha(Fecha newFecha);
   Persona(std::string _nombre, std::string _cedula, Fecha _fecha);
   ~Persona();

protected:
private:
   std::string nombre;
   std::string cedula;
   Fecha fecha;


};

#endif