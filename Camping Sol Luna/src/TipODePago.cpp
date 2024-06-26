#include <iostream>

using namespace std;

#include "TipODePago.h"
#include "ArchivoReservas.h"
#include "ArchivoClientes.h"
#include "ArchivoCabanias.h"
#include "ArchivoCarpas.h"
#include <cstring>


void TipoDePago::Cargar(){
    system("cls");
    bool sectorValido= true;
    int dni, pos;
    ArchivoClientes InfoClientes;


    std::cout<<"Ingrese el DNI para corroborar si el usuario existe: ";
    std::cin>>dni;
    pos = InfoClientes.buscarRegistro(dni);

    if(pos == -2)
    {
        InfoCliente.Cargar();
        cout<<"Ingrese el ID Servicio(1- Carpa 2- Cabania): ";
        cin>>IDServicio;

        do
        {
            cout<<"Ingrese el Sector correspondiente (A-C): ";
            cin>>IDSector;

            if((strcmp(IDSector,"a")==0) || (strcmp(IDSector,"A")==0) || (strcmp(IDSector,"b")==0) || (strcmp(IDSector,"B")==0) || (strcmp(IDSector,"c")==0) || (strcmp(IDSector,"C")==0))
            {

                sectorValido = false;
            }

            else
            {
                cout<<"Opcion Incorrecta, ingrese nuevamente una opcion valida"<<endl;
                system("pause");
            }

        }
        while(sectorValido); ///esto verifica que el sector ingresado sea el correcto de la letra "a" a la "c" verifica que sea tanto mayuscula como minuscula habilitados para poner un sector valido.

        cout<<"Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
        cin>>modoDePago;

        std::cout<<"La fecha de pago se cargo correctamente"<<std::endl;
        FechaPago.CargarActual();/// poner fecha modo automatico preguntando si paga en el momento o no.

        cout<<"Ingrese el Monto: ";
        cin>>Monto;
        if(Monto <= 0)
        {
            cout<<"Ingrese un Monto mayor a 0: ";
            cin>>Monto;
        }

        estado = true; ///reservado- Hay que ver como modificar de reservado a pagado si se pago la totalidad. En caso de pagar la totalidad, se debe poner 0 u otro numero, y en caso de cancelado, valor 2.
    }

    else
    {

        ///InfoClientes.leerRegistro(pos)

    }
}

void TipoDePago::CargarPrueba(){
}

void TipoDePago::CargarPrueba(Fecha Desde, Fecha Hasta)
{

    int DiaRestantes, valorcarpa = 5000, valorcabana=12000, dni, pos;

    Reservas Reservas;
    ArchivoCabanias ArchiCabania;
    ArchivoCarpas ArchiCarpas;
    ArchivoReservas ArchivoReserva;
    ArchivoClientes ArchiClientes;
    Reservas.setFechaDesde(Desde);
    Reservas.setFechaHasta(Hasta);
    DiaRestantes = Reservas.RestanteFecha();///ver 1

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

    ///int Contar = ArchivoReserva.contarRegistros();///podemos hacer el if del case 1 afuera despues de este comando para ingresar  de una la carga si la carga es menor a 0

    switch (IDServicio)
    {
    case 1:
    {

        int Contar = ArchiCarpas.contarRegistros();
        int contando = 20;

        if(Contar>0)/// Fer: Hay que hacer un else donde si no hay registro, se ingresa directamente la reserva
        {


            for(int i=0; i<Contar; i++)
            {
                Reservas = ArchiCarpas.leerRegistro(i);

                if(Reservas.getFechaDesde() >= Desde && Reservas.getFechaHasta() <= Hasta)
                {
                    contando--;
                }

                else if(Reservas.getFechaDesde() >= Desde || Reservas.getFechaHasta() <= Hasta)
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
                Reservas = ArchiCabania.leerRegistro(i);

                if(Reservas.getFechaDesde() >= Desde && Reservas.getFechaHasta() <= Hasta)
                {
                    contando--;
                }

                else if(Reservas.getFechaDesde() >= Desde || Reservas.getFechaHasta() <= Hasta)
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
                FechaPago.CargarActual();/// Pone la fecha en automatico del dia
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
        cout<<"Sector asignado: "<<IDSector<<endl;
        ///cout<<"Estado de Reserva: "<<Estado<<endl;///informar el estado en palabras no en numeros.
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

void TipoDePago::setIDSector(const char * idsector){

    strcpy(IDSector,idsector);

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

const char* TipoDePago::getIDSector(){

    return IDSector;
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

