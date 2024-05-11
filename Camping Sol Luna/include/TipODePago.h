#ifndef TIPODEPAGO_H
#define TIPODEPAGO_H
#include "Fecha.h"
#include "Cliente.h"

class TipODePago
{
   private:

       Cliente InfoCliente;
       int IDServicio, Estado;
       char IDSector[30], ModoPago[30];
       Fecha FechaPago;
       float Monto;

   public:

    void Cargar();
    void Mostrar();
    void setCliente(Cliente );
    void setIDServicio(int );
    void setEstado(int );
    void setIDSector(const char *);
    void setModoPago(const char *);
    void setFechaPago(Fecha);
    void setMonto(float monto);


};

#endif // TIPODEPAGO_H
