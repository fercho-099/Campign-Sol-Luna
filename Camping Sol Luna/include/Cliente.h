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
	bool _estado;

	public:
	Cliente(int DNI, const char *nombre, const char *apellido, int telefono);
	Cliente();
	void Cargar();
	void Mostrar();
	void setDNI(int DNI);
	void setNombre(const char *nombre);
	void setApellido(const char *apellido);
	void setTelefono(int telefono);
	void setEstado(bool e);
	int getDNI();
	const char* getNombre();
	const char* getApellido();
	int getTelefono();
    bool getEstado();
};

#endif // CLIENTE_H
