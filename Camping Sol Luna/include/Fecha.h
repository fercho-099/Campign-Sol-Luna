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
<<<<<<< Updated upstream
    void cargar();
    void mostrar();
=======
    void Cargar();
    void Mostrar();
>>>>>>> Stashed changes
};

#endif // FECHA_H
