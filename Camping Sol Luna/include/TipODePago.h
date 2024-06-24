#ifndef TIPODEPAGO_H
#define TIPODEPAGO_H
#include "Fecha.h"
#include "Cliente.h"

class TipoDePago
{
   private:

       Cliente InfoCliente;
       int IDServicio, modoDePago;
       int Cabana, Carpa;
       char IDSector[30];
       Fecha FechaPago;
       float Monto;
       bool estado;///verifica si se realizo el pago en su totalidad o no.

       bool cabania[10]={false};///Leo
       bool carpa[20]={false};///Leo

   public:
    ///TipoDePago();
    void Cargar();
    void CargarPrueba();
    void Mostrar();
    void setCliente(Cliente );
    void setIDServicio(int );
    void setModoDePago(int);
    void setCabana(int);
    void setCarpa(int);
    void setIDSector(const char *);
    void setFechaPago(Fecha);
    void setMonto(float monto);
    void setEstado(bool );
    Cliente getCliente();
    int getIDServicio();
    int getModoDePago();
    int getCabana();
    int getCarpa();
    const char* getIDSector();
    Fecha getFechaDePago();
    float getMonto();
    bool getEstado();

    bool *getVecCarpa(){return carpa;}///Leo
    bool *getVecCabania(){return cabania;}///Leo
};

#endif // TIPODEPAGO_H
