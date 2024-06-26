#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
 private:

     int dia, mes, anio;

 public:
    Fecha();
    bool MaximosDias( int, int , int );
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    int getDia();
    int getMes();
    int getAnio();
    void Cargar();
    void Mostrar();
    void CargarActual();
    bool ValidarFecha(int,int,int);
    bool esBisiesto();
};

#endif // FECHA_H
