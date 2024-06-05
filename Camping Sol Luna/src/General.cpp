#include <iostream>

using namespace std;

#include "General.h"
#include "Archivo Reservas.h"
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
       Clientes clientes;

       ArchivoCabanias InfoCabanias("Cabanias.dat");

       ArchivoCarpas InfoCarpas("Carpas.dat");
       Archivo Reservas  ("Reservas.dat");


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
