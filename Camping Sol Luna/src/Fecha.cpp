#include "Fecha.h"

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

void Fecha::Cargar(){
    cout<<"Ingrese dia: ";
    cin>>dia;
    cout<<"Ingrese mes: ";
    cin>>mes;
    cout<<"Ingrese año: ";
    cin>>anio;
}

void Fecha::Mostrar(){
    cout<<dia<<":"<<mes<<":"<<anio<<endl;
}




