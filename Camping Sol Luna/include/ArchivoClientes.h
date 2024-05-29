#pragma once

#include "Cliente.h"
#include <cstring>

class ArchivoClientes
{
    public:

        ArchivoClientes(const char *aperturaArchivo);
        void LeerArchivos(Cliente Datos, int TotalRegistros);///se le necesita mandar el objeto cargado
        bool GrabarEnDisco(Cliente obj);
        bool ModificarRegistro(Cliente datos, int DNI);///Se busca por dni y devuelve un bool todo la modificacion se realiza dentro de la clase????
        int ContarRegistros();/// no tiene por que recibir la posicicion de lo que va a leer, si cuenta la totalidad de registros
        ///void VerificarEstadoReservas(int NumeroReserva, int IDServicio);///no deberia ser void por que solo en la funcion informaria si esta ocupado o no, pero del otro lado de la programacion, se necesita que retorne un valor para saber como seguir la ejecucion del programa.
                ///por que verificar estado reserva esta en clientes?????
        void CrearBackUpManual();
        Reservas BuscarRegistros(int DNI);


    private:

        const char *AperturaArchivo;
};


