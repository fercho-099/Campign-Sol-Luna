#pragma once

class ArchivoClientes{
private:
	char nombre[30];
public:
	ArchivoCarpas(const char *n="clientes.dat"){strcpy(nombre,n);}
	bool grabarRegistro(Cliente obj);
	Cliente leerRegistro(int pos);
	int buscarRegistro(int dni);
	int contarRegistros();
	bool modificarRegistro(Cliente obj, int pos);
	bool listarRegistros();
	void verificarEstadoReserva(int dni);
};
