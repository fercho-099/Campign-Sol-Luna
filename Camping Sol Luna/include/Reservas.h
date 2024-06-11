#ifndef RESERVAS_H
#define RESERVAS_H
#include "Fecha.h"
#include "TipODePago.h"
#include<cstdlib>
class Reservas
{
    private:

        TipoDePago Datos;
        Fecha Desde, Hasta;
        int Estado;///Fer

        public:
          ///Reservas();
          void Cargar();
          void Mostrar();
          void setTipoDePago(TipoDePago );
          void setFechaDesde(Fecha);
          void setFechaHasta(Fecha);
          void setEstado(int e);/// 1 reserva guardada / 2 reserva cancelada / 3 reserva gestionada(pase a servicio activo)
          int getEstado();/// 1 reserva guardada / 2 reserva cancelada / 3 reserva gestionada(pase a servicio activo)
          TipoDePago getTipoDePago();
          Fecha getFechaDesde();
          Fecha getFechaHasta();
};
#endif // RESERVAS_H
