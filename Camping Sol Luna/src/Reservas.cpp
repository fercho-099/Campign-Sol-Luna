#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>


void Reservas::Cargar(){
    system("cls");

    Fecha aux;
    datos.Cargar();
    Desde = aux.cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    Hasta.Cargar();

}

void Reservas::Mostrar()
{

    system("cls");
    Fecha aux;
    Datos.Mostrar();
    Aux.to_string(Desde);
    Aux.to_string(Hasta
};

}

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

TipODePago getTipoDePago(){

return datos;

}


