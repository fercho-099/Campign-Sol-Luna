#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>
#include <chrono>

void Reservas::Cargar(){
    system("cls");
    Fecha aux;
    Datos.Cargar();
    ///Desde = aux.Cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    system("cls");
    std::cout<<"Se procedera a la carga fecha de entrada"<<std::endl;
    Desde.Cargar();
    system("cls");
    std::cout<<"Fecha de salida"<<std::endl;
    Hasta.Cargar();
    Estado = 1;

}

void Reservas::CargarPrueba()
{
    system("cls");
    Fecha aux;
    std::cout<<"Se procedera a la carga fecha de entrada"<<std::endl;
    Desde.Cargar();
    system("cls");
    std::cout<<"Fecha de salida"<<std::endl;
    Hasta.Cargar();
    system("cls");

    Datos.CargarPrueba();
    ///Desde = aux.Cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    Estado = 1;


}

///Alan
///Devuelve la cantidad de dia entre fecha de entrada y salida
long long Reservas::RestanteFecha()
{
        tm tmDesde = {0, 0, 0, Desde.getDia(), Desde.getMes() - 1, Desde.getAnio() - 1900};
        tm tmHasta = {0, 0, 0, Hasta.getDia(), Hasta.getMes() - 1, Hasta.getAnio() - 1900};

        time_t tiempoDesde = mktime(&tmDesde);///Las funciones mktime convierten las estructuras tm a time_t, que es el número de segundos transcurridos
        time_t tiempoHasta = mktime(&tmHasta);

        chrono::system_clock::time_point desde = chrono::system_clock::from_time_t(tiempoDesde); ///las variables time_t se convierten en time_point de chrono::system_clock, que se utilizan para operaciones de duración en la librería <chrono>
        chrono::system_clock::time_point hasta = chrono::system_clock::from_time_t(tiempoHasta);

        auto diferencia = chrono::duration_cast<chrono::seconds>(hasta - desde); ///Calcula la diferenia en segundos

        return diferencia.count() / 86400; ///Convertir segundos a días
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


