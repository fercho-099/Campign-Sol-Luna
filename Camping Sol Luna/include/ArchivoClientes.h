#ifndef ARCHIVOCLIENTES_H
#define ARCHIVOCLIENTES_H

#include "Cliente.h"
#include "Reservas.h"

class ArchivoClientes{
private:
	char nombre[30];
public:
	ArchivoClientes();
	bool grabarRegistro(Cliente obj);
	Cliente leerRegistro(int pos);
	int buscarRegistro(int dni);
	int contarRegistros();
	bool modificarRegistro(Cliente obj, int pos);
	bool listarRegistros();
	void verificarEstadoCliente(int dni);
};

#endif
