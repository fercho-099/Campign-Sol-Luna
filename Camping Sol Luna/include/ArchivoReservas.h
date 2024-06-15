#pragma once
#include <cstring>
#include "Reservas.h"


class ArchivoReservas{
private:
	char AperturaArchivo[30];

public:
    ArchivoReservas();///se usa
	ArchivoReservas(const char *n);///se usa

	bool GrabarRegistro(Reservas obj);
	bool GrabarRegistro(Reservas obj, int TotalRegistros);
	bool grabarRegistros(Reservas obj, int pos);
    void grabarRegistroNuevo(Reservas obj);

    Reservas LeerRegistro(int pos);///se usa
	void LeerRegistrosTotales(Reservas &, int );///se usa
    Reservas LeerRegistrosDinamicos(Reservas *DatoReserva, int pos);///agregue esto

	int BuscarRegistro(int dni);///ver si no es pretendida por ningun otro metodo donde necesita el retorno
    int BuscarRegistro(Reservas *DatoReserva, int TotalRegistros, int dni);///Agregue esto

	int contarRegistros();///se usa


	bool ModificarRegistros(Reservas &obj, int pos);
	void ModificarRegistros(Reservas &obj);///se usa



    bool CrearBackUpManual();///se usa
	void ListarRegistros();
	///void VerificarEstadoReserva(int dni);   PREGUNTAR A LEO
	void verificarEstadoReserva(Reservas *DatosReservas, int TotalRegistros, int dni);

};
