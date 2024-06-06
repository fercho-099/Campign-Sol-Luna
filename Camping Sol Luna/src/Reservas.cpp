#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>

void Reservas::Cargar(){
    system("cls");
    Fecha aux;
    datos.Cargar();
    ///Desde = aux.Cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    Desde.Cargar();
    Hasta.Cargar();
}

Reservas::Reservas()
{
    datos;
    Desde;
    Hasta;
    estado = false;
}

void Reservas::Mostrar()
{

    system("cls");
    Fecha aux;
    datos.Mostrar();
    Desde.Mostrar();
    Hasta.Mostrar();
    ///aux.to_string(Desde);
    ///aux.to_string(Hasta);
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

TipoDePago Reservas::getTipoDePago(){
    return datos;
}

void Reservas::setEstado(bool e){
    estado=e;
}

bool Reservas::getEstado(){
    return estado;
}



