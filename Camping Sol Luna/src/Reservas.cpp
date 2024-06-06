#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>

void Reservas::Cargar(){
    system("cls");
    Fecha aux;
    Datos.Cargar();
    ///Desde = aux.Cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    Desde.Cargar();
    Hasta.Cargar();
    Estado = 1;

}

Reservas::Reservas()
{
    Datos;
    Desde;
    Hasta;
    Estado = 0;
}

void Reservas::Mostrar()
{

    system("cls");
    Fecha aux;
    Datos.Mostrar();
    Desde.Mostrar();
    Hasta.Mostrar();
    ///aux.to_string(Desde);
    ///aux.to_string(Hasta);
}

void Reservas::setTipoDePago(TipoDePago info) ///verificar que se copie el objeto correctamente
{

    Datos=info;

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
    return Datos;
}

void Reservas::setEstado(int e){
    Estado=e;
}

int Reservas::getEstado(){
    return Estado;
}


