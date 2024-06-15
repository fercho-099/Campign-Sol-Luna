#include <iostream>

using namespace std;
#include "Reservas.h"
#include <cstring>
#include <chrono>

void Reservas::Cargar(){

    Fecha aux;
    Datos.Cargar();
    std::cout<<"Fecha de entrada"<<std::endl;
    Desde.Cargar();
    std::cout<<"Fecha de salida"<<std::endl;
    Hasta.Cargar();
    Estado = 1;

}

/*void Reservas::CargarPrueba()
{
    system("cls");
    Fecha aux;
    std::cout<<"Se procedera a la carga fecha de entrada"<<std::endl;
    Desde.Cargar();
    system("cls");
    std::cout<<"Fecha de salida"<<std::endl;
    Hasta.Cargar();
    system("cls");

    //Datos.CargarPrueba();
    ///Desde = aux.Cargar();///No esta en diagrama, se diferencia de dos cargar por case sensitive. Una carga automatico la otra carga manual.
    Estado = 1;


}*/

long long Reservas::RestanteFecha()
{
        int diaDesde, mesDesde, anioDesde, diaHasta,mesHasta,anioHasta;
        diaDesde = Desde.getDia();
        mesDesde = Desde.getMes();
        anioDesde = Desde.getAnio();
        diaHasta = Hasta.getDia();
        mesHasta = Hasta.getMes();
        anioHasta = Hasta.getAnio();

        std::tm tmDesde = {0, 0, 0, diaDesde, mesDesde - 1, anioDesde - 1900};
        std::tm tmHasta = {0, 0, 0, diaHasta, mesHasta - 1, anioHasta - 1900};

        std::time_t tiempoDesde = std::mktime(&tmDesde);
        std::time_t tiempoHasta = std::mktime(&tmHasta);

        std::chrono::system_clock::time_point desde = std::chrono::system_clock::from_time_t(tiempoDesde);
        std::chrono::system_clock::time_point hasta = std::chrono::system_clock::from_time_t(tiempoHasta);

        auto diferencia = std::chrono::duration_cast<std::chrono::seconds>(hasta - desde);

        return diferencia.count() / 86400; // Convertir segundos a días
}

void Reservas::Mostrar()
{

    ///system("cls");
    Fecha aux;
    Datos.Mostrar();
    std::cout<<"Fecha de Entrada: ";
    Desde.Mostrar();
    ///std::cout<<std::endl;
    std::cout<<"Fecha de salida: ";
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


