#pragma once
#include <cstring>
#include "Reservas.h"


class ArchivoReservas{
private:
	char AperturaArchivo[30];
public:
	ArchivoReservas(const char *n="Reservas.dat"){strcpy(AperturaArchivo,n);}
	bool grabarRegistro(Reservas obj);
	bool grabarRegistro(Reservas obj, int pos);
	Reservas leerRegistro(int pos);
	void LeerRegistrosTotales(Reservas &, int );///Fer
	int buscarRegistro(int dni);
	void BuscarRegistros(Reservas &, int, int );///Fer
	int contarRegistros();
	bool modificarRegistro(Reservas obj, int pos);
	bool ModificarRegistros(Reservas &obj);
	bool listarRegistros();
	void verificarEstadoReserva(int dni);

};
