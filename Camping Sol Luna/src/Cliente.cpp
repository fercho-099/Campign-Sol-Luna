#include <iostream>
#include <cstring>
#include<cstdlib>

using namespace std;

#include "Cliente.h"


Cliente::Cliente(int DNI, const char *nombre, const char *apellido, int telefono)
{
	setDNI(DNI);
	setNombre(nombre);
	setApellido(apellido);
	setTelefono(telefono);
}

void Cliente::setDNI(int DNI)
{
	_DNI=DNI;
}

void Cliente::setNombre(const char *nombre)
{
	 strcpy(_nombre,nombre);
}

void Cliente::setApellido(const char *apellido)
{
	 strcpy(_apellido,apellido);
}

void Cliente::setTelefono(int telefono)
{
	_telefono=telefono;
}

int Cliente::getDNI()
{
	return _DNI;
}

const char* Cliente::getNombre()
{
	return _nombre;
}

const char* Cliente::getApellido()
{
	return _apellido;
}

int Cliente::getTelefono()
{
	return _telefono;
}
