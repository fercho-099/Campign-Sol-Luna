#include <iostream>

using namespace std;

#include "TipODePago.h"
#include "ArchivoReservas.h"
#include "ArchivoClientes.h"
#include "ArchivoCabanias.h"
#include "ArchivoCarpas.h"
#include <cstring>

void TipoDePago::CargarPrueba(Fecha Desde, Fecha Hasta)
{

    int DiaRestantes, valorcarpa = 5000, valorcabana=12000, dni, pos;

    Reservas reserva;
    ArchivoCabanias ArchiCabania;
    ArchivoCarpas ArchiCarpas;
    ArchivoReservas ArchivoReserva;
    ArchivoClientes ArchiClientes;
    reserva.setFechaDesde(Desde);
    reserva.setFechaHasta(Hasta);
    DiaRestantes = reserva.RestanteFecha();

    do
    {
        cout<<"Ingrese el ID Servicio(1- Carpas 2- Cabania): ";
        cin>>IDServicio;
        if(IDServicio > 2)
        {
            cout<<"Ingrese un ID de servicio valido: ";
            system("pause");
            system("cls");
        }
    }
    while(IDServicio>2 || IDServicio <1);

    switch (IDServicio)
    {
    case 1:
    {

        int Contar = ArchiCarpas.contarRegistros();
        int contando = 20;

        if(Contar>0)
        {


            for(int i=0; i<Contar; i++)
            {
                reserva = ArchiCarpas.leerRegistro(i);

                if(reserva.getFechaDesde() >= Desde && reserva.getFechaHasta() <= Hasta)
                {
                    contando--;
                }

                else if(reserva.getFechaDesde() <= Desde && reserva.getFechaHasta() <= Hasta)
                {
                    contando--;
                }

            }
        }

        if (contando==0)
        {
            cout << "No hay carpas disponibles en el rango de fechas ingresado"<<endl;
            return;
        }
        else
        {
            cout<<"Hay "<<contando<<" carpas disponible"<<endl;
            system("pause");
            std::cout<<"Ingrese el DNI para corroborar si el usuario existe: ";
            std::cin>>dni;
            pos = ArchiClientes.buscarRegistro(dni);

            if(pos <0)
            {
                InfoCliente.Cargar();
                ArchiClientes.grabarRegistro(InfoCliente);
                Monto = DiaRestantes * valorcarpa;
                cout<<"Monto total a abonar: "<<Monto<<endl;

                do
                {
                    cout<<"Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
                    cin>>modoDePago;

                    if(modoDePago > 2 || modoDePago<1)
                    {
                        cout<<"Medio de pago invalido, vuelva a ingresar: ";
                        system("pause");
                    }


                }
                while(modoDePago !=1 && modoDePago !=2);

                std::cout<<"La fecha de pago se cargo correctamente"<<std::endl;
                FechaPago.CargarActual();/// Pone la fecha en automatico del dia
                estado = true;
            }

            else
            {

                InfoCliente = ArchiClientes.leerRegistro(pos);
                Monto = DiaRestantes * valorcarpa;
                cout<<"Monto total a abonar: "<<Monto<<endl;

                do
                {
                    cout<<"Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
                    cin>>modoDePago;

                    if(modoDePago > 2 || modoDePago<1)
                    {
                        cout<<"Medio de pago invalido, vuelva a ingresar: ";
                        system("pause");
                    }


                }
                while(modoDePago !=1 && modoDePago !=2);

                std::cout<<"La fecha de pago se cargo correctamente"<<std::endl;
                FechaPago.CargarActual();/// Pone la fecha en automatico del dia
                estado = true;

            }
        }
    }
    break;

    case 2:
    {
        int Contar = ArchiCabania.contarRegistros();
        int contando = 10;

        if(Contar>0)
        {


            for(int i=0; i<Contar; i++)
            {
                reserva = ArchiCabania.leerRegistro(i);

                if(reserva.getFechaDesde() >= Desde && reserva.getFechaHasta() <= Hasta)
                {
                    contando--;
                }

                else if(reserva.getFechaDesde() >= Desde || reserva.getFechaHasta()==(Hasta))
                {
                    contando--;
                }


            }
        }

        if (contando==0)
        {
            cout << "No hay Cabanias disponibles en el rango de fechas ingresado"<<endl;
            return;
        }
        else
        {
            cout<<"Hay "<<contando<<" cabanias disponible"<<endl;
            system("pause");
            std::cout<<"Ingrese el DNI para corroborar si el usuario existe: ";
            std::cin>>dni;
            pos = ArchiClientes.buscarRegistro(dni);

            if(pos <0)
            {
                InfoCliente.Cargar();
                ArchiClientes.grabarRegistro(InfoCliente);
                Monto = DiaRestantes * valorcabana;
                cout<<"Monto total a abonar: "<<Monto<<endl;

                do
                {
                    cout<<"Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
                    cin>>modoDePago;

                    if(modoDePago > 2 || modoDePago<1)
                    {
                        cout<<"Medio de pago invalido, vuelva a ingresar: ";
                        system("pause");
                    }


                }
                while(modoDePago !=1 && modoDePago !=2);

                std::cout<<"La fecha de pago se cargo correctamente"<<std::endl;
                FechaPago.CargarActual();/// Pone la fecha en automatico del dia
                estado = true;
            }

            else
            {

                InfoCliente = ArchiClientes.leerRegistro(pos);
                Monto = DiaRestantes * valorcabana;
                cout<<"Monto total a abonar: "<<Monto<<endl;

                do
                {
                    cout<<"Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
                    cin>>modoDePago;

                    if(modoDePago > 2 || modoDePago<1)
                    {
                        cout<<"Medio de pago invalido, vuelva a ingresar: ";
                        system("pause");
                    }


                }
                while(modoDePago !=1 && modoDePago !=2);

                std::cout<<"La fecha de pago se cargo correctamente"<<std::endl;
                FechaPago.CargarActual();
                estado = true;

            }
        }


    break;///case 2
}
    default:
        cout << "Vuelva a ingresar un ID de servicio valido"<<endl;
        break;
}

}


void TipoDePago::Mostrar(){

        InfoCliente.Mostrar();
        cout<<"Servicio: "<<IDServicio<<endl;
        cout<<"Modo de Pago: ";
        if(modoDePago==1){
            cout<<"Efectivo "<<endl;
        }else cout<<"Tarjeta de debito/credito "<<endl;
        cout<<"Fecha de Pago"<<endl;
        FechaPago.Mostrar();
        cout<<"Monto abonado: "<<Monto<<endl;

}

void TipoDePago::setCliente(Cliente datos){

    InfoCliente = datos;

}

void TipoDePago::setIDServicio(int idservicio){

    IDServicio=idservicio;
}

void TipoDePago::setModoDePago(int _modopago){

    modoDePago=_modopago;
}

void TipoDePago::setFechaPago(Fecha fechapago){

    FechaPago = fechapago;

}

void TipoDePago::setMonto(float monto){

    Monto = monto;
}

void TipoDePago::setEstado(bool _estado){

    estado = _estado;

}

void TipoDePago::setCabana(int _cabana)
{
    Cabana = _cabana;
}

void TipoDePago::setCarpa(int _carpa)
{
    Carpa = _carpa;
}

Cliente TipoDePago::getCliente(){

    return InfoCliente;

}

int TipoDePago::getIDServicio(){

    return IDServicio;
}

int TipoDePago::getModoDePago(){

    return modoDePago;
}

int TipoDePago::getCabana()
{
    return Cabana;
}

int TipoDePago::getCarpa()
{
    return Carpa;
}

Fecha TipoDePago::getFechaDePago(){

    return FechaPago;
}

float TipoDePago::getMonto(){

    return Monto;

}

bool TipoDePago::getEstado(){

    return estado;

}

