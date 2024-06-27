#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>
#include <chrono>


void Reservas::Cargar()
{
    system("cls");
    Fecha aux;
    std::cout<<"Se procedera a la carga fecha de entrada"<<std::endl;
    Desde.Cargar();
    system("cls");
    std::cout<<"Fecha de salida"<<std::endl;
    Hasta.Cargar();
    system("cls");
    Datos.Cargar(Desde,Hasta);
    Estado = true;
}

long long Reservas::RestanteFecha()
{
    tm tmDesde = {0, 0, 0, Desde.getDia(), Desde.getMes() - 1, Desde.getAnio() - 1900};
    tm tmHasta = {0, 0, 0, Hasta.getDia(), Hasta.getMes() - 1, Hasta.getAnio() - 1900};

    time_t tiempoDesde = mktime(&tmDesde);///Las funciones mktime convierten las estructuras tm a time_t, que es el número de segundos transcurridos
    time_t tiempoHasta = mktime(&tmHasta);

    chrono::system_clock::time_point desde = chrono::system_clock::from_time_t(tiempoDesde); ///las variables time_t se convierten en time_point de chrono::system_clock, que se utilizan para operaciones de duración en la librería <chrono>
    chrono::system_clock::time_point hasta = chrono::system_clock::from_time_t(tiempoHasta);

    auto diferencia = chrono::duration_cast<chrono::seconds>(hasta - desde); ///Calcula la diferenia en segundos

    return (1+(diferencia.count() / 86400)); ///Convertir segundos a días
}

void Reservas::Mostrar()
{
    Datos.Mostrar();
    cout<<"Fecha de ingreso"<<endl;
    Desde.Mostrar();
    cout<<"Fecha de salida"<<endl;
    Hasta.Mostrar();
}

void Reservas::setTipoDePago(TipoDePago info)
{

    Datos=info;

}

void Reservas::setFechaDesde(Fecha desde)
{

    Desde = desde;

}

void Reservas::setFechaHasta(Fecha hasta)
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

TipoDePago Reservas::getTipoDePago()
{
    return Datos;
}

void Reservas::setEstado(bool e)
{
    Estado=e;
}

bool Reservas::getEstado()
{
    return Estado;
}


