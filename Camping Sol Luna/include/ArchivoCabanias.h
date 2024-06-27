#pragma once

#include "Reservas.h"

class ArchivoCabanias
{
private:
    char nombre[30];
public:
    ArchivoCabanias(const char *n);
    ArchivoCabanias();
    bool grabarRegistro(Reservas obj);
    Reservas leerRegistro(int pos);
    int buscarRegistro(int dni);
    int contarRegistros();
    bool modificarRegistro(Reservas obj, int pos);
    bool listarRegistros();
    void verificarEstadoReserva(int dni);
    bool crearBackupCabanias();
};
