#include <iostream>
#include <cstring>
#include<cstdlib>

using namespace std;

#include "Cliente.h"
#include "Funciones.h"

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

Cliente::Cliente(int DNI, const char *nombre, const char *apellido, int telefono)
{
	setDNI(DNI);
	setNombre(nombre);
	setApellido(apellido);
	setTelefono(telefono);
	setEstado(true);
}

Cliente::Cliente()
{
	_DNI=0;
	strcpy(_nombre,"NULL");
	strcpy(_apellido,"NULL");
	_telefono=12345;
	_estado=false;
}

void Cliente::Cargar(){
    cout<<"Ingrese el Dni: ";
    _DNI = IngresoNumero();
    if(_DNI < 1000000)
        {
         cout<<"Ingrese un dni valido: ";
         _DNI = IngresoNumero();
        }
    cout<<"Ingrese el nombre: ";
    cargarCadena(_nombre,30);
    cout<<"Ingrese el apellido: ";
    cargarCadena(_apellido,30);
    cout<<"Ingrese el telefono: ";
    _telefono = IngresoNumero();
    if(_telefono<10000000)
        {
          cout<<"Ingrese un telefono valido: ";
          _telefono = IngresoNumero();
        }
    setEstado(true);
}

void Cliente::Mostrar(){
    cout<<"Dni: "<<_DNI<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"Telefono: "<<_telefono<<endl;
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

void Cliente::setEstado(bool e){
    _estado=e;
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

bool Cliente::getEstado(){
    return _estado;
}
