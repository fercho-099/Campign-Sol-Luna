#ifndef TIPODEPAGO_H
#define TIPODEPAGO_H
#include "Fecha.h"
#include "Cliente.h"

class TipoDePago
{
private:

    Cliente InfoCliente;
    int IDServicio, modoDePago;
    Fecha FechaPago;
    float Monto;
public:
    void Cargar(Fecha, Fecha);
    void Mostrar();
    void setCliente(Cliente );
    void setIDServicio(int );
    void setModoDePago(int);
    void setFechaPago(Fecha);
    void setMonto(float monto);
    void setEstado(bool );
    Cliente getCliente();
    int getIDServicio();
    int getModoDePago();
    Fecha getFechaDePago();
    float getMonto();
};

#endif // TIPODEPAGO_H
