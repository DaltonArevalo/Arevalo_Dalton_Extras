/***********************************************************************
 * Module:  Persona.cpp
 * Author:  DALTON AREVALO
 * Modified: jueves, 3 de junio de 2021 12:44:18
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(std::string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(std::string newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getFecha()
// Purpose:    Implementation of Persona::getFecha()
// Return:     Fecha
////////////////////////////////////////////////////////////////////////

Fecha Persona::getFecha(void)
{
   return fecha;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setFecha(Fecha newFecha)
// Purpose:    Implementation of Persona::setFecha()
// Parameters:
// - newFecha
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setFecha(Fecha newFecha)
{
   fecha = newFecha;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona(std::string _nombre, std::string _cedula, Fecha _fecha)
// Purpose:    Implementation of Persona::Persona()
// Parameters:
// - _nombre
// - _cedula
// - _fecha
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::Persona(std::string _nombre, std::string _cedula, Fecha _fecha)
{

}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::~Persona()
{
   // TODO : implement
}