<<<<<<< Updated upstream
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
=======
#ifndef ARCHIVOCLIENTES_H
#define ARCHIVOCLIENTES_H
#include "Cliente.h"
#include <cstring>
class ArchivoClientes
{
    public:

        void LeerArchivo(Cliente obj, int TotalRegistros);///se le necesita mandar el objeto cargado
        bool GrabarEnDisco(Cliente obj);
        bool ModificarReservas(int DNI);
        int ContarRegistros();/// no tiene por que recibir la posicicion de lo que va a leer, si cuenta la totalidad de registros
        void VerificarEstadoReservas(int NumeroReserva, int IDServicio);///no deberia ser void por que solo en la funcion informaria si esta ocupado o no, pero del otro lado de la programacion, se necesita que retorne un valor para saber como seguir la ejecucion del programa.
        void CrearBackUpManual();
        Reservas BuscarRegistros(int DNI);
        ArchivoClientes(const char *aperturaArchivo);

    private:

        const char *AperturaArchivo;
};

#endif // ARCHIVOCLIENTES_H
>>>>>>> Stashed changes
