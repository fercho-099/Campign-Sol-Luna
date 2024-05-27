#ifndef RESERVAS_H
#define RESERVAS_H
#include "Fecha.h"
#include "TipODePago.h"

class Reservas
{
    private:

        TipoDePago datos;
        Fecha Desde, Hasta;
        bool estado;

        public:
          void Cargar();
          void Mostrar();
          void setTipoDePago(TipoDePago );
          void setFechaDesde(Fecha );
          void setFechaHasta(Fecha );
          void setEstado(bool e);
          bool getEstado();
          TipoDePago getTipoDePago();
          Fecha getFechaDesde();
          Fecha getFechaHasta();
};

#endif // RESERVAS_H
