#ifndef RESERVAS_H
#define RESERVAS_H
#include "Fecha.h"
#include "TipODePago.h"

class Reservas
{
    private:

        TipoDePago Datos;
        Fecha Desde, Hasta;
        int Estado;///Fer

        public:
          Reservas();
          void Cargar();
          void Mostrar();
          void setTipoDePago(TipoDePago );
          void setFechaDesde(Fecha);
          void setFechaHasta(Fecha);
          void setEstado(int e);
          int getEstado();
          TipoDePago getTipoDePago();
          Fecha getFechaDesde();
          Fecha getFechaHasta();
};
#endif // RESERVAS_H
