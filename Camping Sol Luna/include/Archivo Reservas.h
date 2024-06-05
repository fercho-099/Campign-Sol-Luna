#pragma once

#include "Reservas.h"


class ArchivoReservas{
private:
	char AperturaArchivo[30];
public:
	ArchivoReservas(const char *n="Reservas.dat"){strcpy(AperturaArchivo,n);}
	bool grabarRegistro(Reservas obj);
	Reservas leerRegistro(int pos);
	int buscarRegistro(int dni);
	int contarRegistros();
	bool modificarRegistro(Reservas obj, int pos);
	bool listarRegistros();
	void verificarEstadoReserva(int dni);

};
