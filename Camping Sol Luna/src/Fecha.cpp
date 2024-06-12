#include <ctime>
#include "Fecha.h"
#include "Funciones.h"

Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}

void Fecha::setDia(int d){
    dia=d;
}

void Fecha::setMes(int m){
    mes=m;
}

void Fecha::setAnio(int a){
    anio=a;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

void Fecha::CargarActual()
{
    time_t now = time(0); // Captura fecha y hora actual
    tm* localTime = localtime(&now); // Creamos el puntero localTime y lo referenciamos al objeto time
    // Accedemos a los atributos de la estructura tm
    int dia = localTime->tm_mday;
    int mes = localTime->tm_mon + 1; // Sumamos 1 porque los meses están indexados desde 0
    int anio = localTime->tm_year + 1900; // Sumamos 1900 para obtener el año actual
}

void Fecha::Cargar(){
    cout<<"Ingrese dia: ";
    dia = IngresoNumero();
    cout<<"Ingrese mes: ";
    mes = IngresoNumero();
    cout<<"Ingrese año: ";
    anio = IngresoNumero();
}

void Fecha::Mostrar(){
    cout<<dia<<":"<<mes<<":"<<anio<<endl;
}




