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

     bool operator>=(Fecha& otra)
     {
        if(anio > otra.anio)
            {
                return true;
            }
        else if(anio == otra.anio && mes > otra.mes)
            {
                return true;
            }
        else if(anio == otra.anio && mes == otra.mes && dia>= otra.dia)
        {
            return true;
        }
        else return false;
     }

     bool operator<=(Fecha& otra)
     {
        if(anio < otra.anio)
            {
                return true;
            }
        else if(anio == otra.anio && mes < otra.mes)
            {
                return true;
            }
        else if(anio == otra.anio && mes == otra.mes && dia <= otra.dia)
        {
            return true;
        }
        else return false;
     }
};

#endif // FECHA_H
