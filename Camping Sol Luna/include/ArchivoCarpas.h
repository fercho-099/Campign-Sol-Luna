#pragma once

#include "Reservas.h"

class ArchivoCarpas{
private:
	char nombre[30];
public:
	ArchivoCarpas(const char *n);
	ArchivoCarpas();
	bool grabarRegistro(Reservas obj);
	Reservas leerRegistro(int pos);
	int buscarRegistro(int dni);
	int contarRegistros();
	bool modificarRegistro(Reservas obj, int pos);
	bool listarRegistros();
	void verificarEstadoReserva(int dni);
	bool crearBackupCarpas();
};
