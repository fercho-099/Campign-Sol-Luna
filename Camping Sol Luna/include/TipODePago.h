#ifndef TIPODEPAGO_H
#define TIPODEPAGO_H
#include "Fecha.h"
#include "Cliente.h"

class TipoDePago
{
   private:

       Cliente InfoCliente;
       int IDServicio, modoDePago;
       char IDSector[30];
       Fecha FechaPago;
       float Monto;
       bool estado;

   public:
    void Cargar();
    void Mostrar();
    void setCliente(Cliente );
    void setIDServicio(int );
    void setModoDePago(int);
    void setIDSector(const char *);
    void setFechaPago(Fecha);
    void setMonto(float monto);
    void setEstado(bool );
    Cliente getCliente();
    int getIDServicio();
    int getModoDePago();
    const char* getIDSector();
    Fecha getFechaDePago();
    float getMonto();
    bool getEstado();
};

#endif // TIPODEPAGO_H
