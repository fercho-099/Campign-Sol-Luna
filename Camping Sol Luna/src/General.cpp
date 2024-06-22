#include <iostream>

using namespace std;

#include "General.h"
#include "ArchivoReservas.h"
#include "ArchivoCabanias.h"
#include "ArchivoCarpas.h"
#include "ArchivoClientes.h"
#include "Reservas.h"
#include "Cliente.h"

General::General()
{

}

void General::InformeMensual()
{
       ArchivoClientes InfoCliente("Clientes.dat");
       Cliente cliente;

       ArchivoCabanias InfoCabanias("Cabanias.dat");

       ArchivoCarpas InfoCarpas("Carpas.dat");
       ArchivoReservas  InfoReservas("Reservas.dat");




}

void General::InformeUltimo30Dias()
{

}

void General::facturacionTotal()
{

}

void General::mostrarCabaniasEnUso()
{

}


void General::mostrarCarpasEnUso()
{

}

