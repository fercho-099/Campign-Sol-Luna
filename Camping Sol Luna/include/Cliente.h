#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
using namespace std;


class Cliente
{
	private:

	int _DNI;
	char _nombre[30];
	char _apellido[30];
	int _telefono;


	public:
	Cliente(int DNI, const char *nombre, const char *apellido, int telefono);
	bool Cargar();
	void Mostrar();
	void setDNI(int DNI);
	void setNombre(const char *nombre);
	void setApellido(const char *apellido);
	void setTelefono(int telefono);
	int getDNI();
	const char* getNombre();
	const char* getApellido();
	int getTelefono();

};

#endif // CLIENTE_H
