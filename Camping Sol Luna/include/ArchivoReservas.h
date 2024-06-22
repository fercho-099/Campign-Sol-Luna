#pragma once
#include <cstring>
#include "Reservas.h"


class ArchivoReservas{
private:
	char AperturaArchivo[30];

public:
    ArchivoReservas();///se usa para back up
	ArchivoReservas(const char *n);///se usa para bak up
    void setAperturaArchivo(const char *n);///se usa para bak up

	bool GrabarRegistro(Reservas obj);///se usa para carga normal
	///bool GrabarRegistro(Reservas obj, int TotalRegistros);///No funciona grabar todo junto
	bool grabarRegistros(Reservas obj, int pos);///se usa en el metodo de modificar reserva ya que recibe como parametro un registro completo de reservas y la posicion donde se va a reescribir los datos modificados en el archivo
    void grabarRegistroNuevo(Reservas obj);///Sirve para grabar en archivo nuevo con una apertura wb y pisando el archivo viejo.

    ///Reservas LeerRegistro(int pos);
	void LeerRegistrosTotales(Reservas &, int );///se usa para cargar el vector de objetos en su totalidad
    Reservas LeerRegistrosDinamicos(Reservas *DatoReserva, int pos);///Recibe el vector de registros cargados y la posiccion donde se encuentra en el registro y devuelve ese registro especifico.

	int BuscarRegistro(int dni);/// Se Debe usar para buscar en el registro cliente si existe el cliente antes de cargarlo nuevamente
    int BuscarRegistro(Reservas *DatoReserva, int TotalRegistros, int dni);///se usa para buscar registro en la posicion y devuelve suposicion en el archivo

	int contarRegistros();///se usa para memoria dinamica

    void ModificarRegistros(Reservas *obj);///Recibe el objeto dinamico de reservas con informacion y se modifica.

    bool CrearBackUpManual();///Devuelve true o false si se pudo crear un back up correctamente de manera automatica.
	void ListarRegistros();///Lista la totalidad de registro de un archivo especifico, puede ser el back up o el archivo actual.
	///void VerificarEstadoReserva(int dni);   PREGUNTAR A LEO
	void verificarEstadoReserva(Reservas *DatosReservas, int TotalRegistros, int dni);///recibe tres parametro  e informa el estado de reserva de un registro especifico.

    void mostrarCabaniasDisponibles();///Leo
    void mostrarCarpasDisponibles();///Leo
};
