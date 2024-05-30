#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>
<<<<<<< Updated upstream


=======
#include <cstdlib>
/*
>>>>>>> Stashed changes
void Reservas::Cargar(){
    system("cls");

    Fecha aux;
    datos.Cargar();
<<<<<<< Updated upstream
    aux.cargar();
    Desde = aux;///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    Hasta.cargar();
=======

    ///Desde = aux.Cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.

    Desde.Cargar();

    Hasta.Cargar();
>>>>>>> Stashed changes

}

void Reservas::Mostrar()
{

    system("cls");
    Fecha aux;
<<<<<<< Updated upstream
    datos.Mostrar();
    aux.to_string(Desde);
    aux.to_string(Hasta);
=======

    Datos.Mostrar();
    Aux.to_string(Desde);
    Aux.to_string(Hasta);
>>>>>>> Stashed changes
};

void Reservas::setTipoDePago(TipoDePago info) ///verificar que se copie el objeto correctamente
{

    datos=info;

}

void Reservas::setFechaDesde(Fecha desde)
{

    Desde = desde;

}

void Reservas::setFechaHasta(Fecha hasta)  ///Lo mismo, verificar que se copie el objeto correctamente
{

    Hasta = hasta;

}

Fecha Reservas::getFechaDesde()
{

    return Desde;

}

Fecha Reservas::getFechaHasta()
{

    return Hasta;

}

<<<<<<< Updated upstream
TipODePago getTipoDePago(){
=======
TipODePago Reservas::getTipoDePago(){
>>>>>>> Stashed changes

return datos;

}

<<<<<<< Updated upstream
void Reservas::setEstado(bool e){
    estado=e;
}

bool Reservas::getEstado(){
    return estado;
}
=======
*/
>>>>>>> Stashed changes
