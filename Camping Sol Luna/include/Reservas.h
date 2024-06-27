#ifndef RESERVAS_H
#define RESERVAS_H

#include<cstdlib>
#include "Fecha.h"
#include "TipODePago.h"


class Reservas
{
private:

    TipoDePago Datos;
    Fecha Desde, Hasta;
    bool Estado;

public:
    void Cargar();
    void Mostrar();
    void setTipoDePago(TipoDePago );
    void setFechaDesde(Fecha);
    void setFechaHasta(Fecha);
    void setEstado(bool e);
    bool getEstado();
    TipoDePago getTipoDePago();
    Fecha getFechaDesde();
    Fecha getFechaHasta();
    long long int RestanteFecha();
};
#endif // RESERVAS_H
