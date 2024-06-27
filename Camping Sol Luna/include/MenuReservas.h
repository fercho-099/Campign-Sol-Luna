#pragma once

#include "ArchivoReservas.h"
#include "ArchivoCarpas.h"
#include "ArchivoCabanias.h"
#include "Reservas.h"

void CargarReserva();
void CargarReservaPrueba();
void ModificarReserva();
void BorrarReserva();
void EstadoReserva();
void MostrarArchivoReservas();

void OpcionesDeReservas()
{
    system("cls");
    int opc;
    bool loop=true;


    do
    {
        system("cls");
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Crear una reserva "<<endl;
        cout<<"2 - Modificar una reserva "<<endl;
        cout<<"3 - Borrar una reserva"<<endl;
        cout<<"4 - Verificar Reserva"<<endl;
        cout<<"5 - Mostrar Reservas"<<endl;
        cout<<"0 - Volver al menu anterior"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            CargarReserva();
            break;
        case 2:
            ModificarReserva();
            break;
        case 3:
            BorrarReserva();
            break;
        case 4:
            EstadoReserva();
            break;
        case 5:
            MostrarArchivoReservas();
            break;
        case 0:
            loop=false;
            break;
        default:

            std::cout<<"Ingrese una opcion correcta"<<std::endl;
            system("pause");
        }
    }
    while(loop);

}

void CargarReserva()
{

    Reservas DatosReservas;
    ArchivoReservas InfoReservas;
    DatosReservas.Cargar();
    if(InfoReservas.GrabarRegistro(DatosReservas))
    {
        std::cout<<"Se guardo Guardo correctamente la reserva"<<std::endl;
        if(DatosReservas.getTipoDePago().getIDServicio()==1)
        {
            ArchivoCarpas archiCarpas;
            archiCarpas.grabarRegistro(DatosReservas);
        }
        else if(DatosReservas.getTipoDePago().getIDServicio()==2)
        {
            ArchivoCabanias archiCabanias;
            archiCabanias.grabarRegistro(DatosReservas);
        }
        system("pause");
    }
    else
    {
        std::cout<<"No se Gestiona la reserva"<<std::endl;
        system("pause");
    }

}

void ModificarReserva()
{

    system("cls");
    ArchivoReservas InfoReservas;
    Reservas *DatoReserva, aux;
    int pos;
    int TotalRegistros = InfoReservas.contarRegistros();

    if(TotalRegistros<=0)
    {
        std::cout<<"No se pudo realizar modificacion del registro"<<std::endl;
        system("pause");
        return;
    }
    DatoReserva = new Reservas[TotalRegistros];
    InfoReservas.LeerRegistrosTotales(*DatoReserva, TotalRegistros);

    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;

    pos = InfoReservas.BuscarRegistro(DatoReserva, TotalRegistros, dni);

    if(pos == -1)
    {

        delete []DatoReserva;
        return;
    }
    aux = InfoReservas.LeerRegistrosDinamicos(DatoReserva, pos);

    InfoReservas.ModificarRegistros(&aux);
    if(InfoReservas.grabarRegistros(aux, pos))
    {

        std::cout<<"Se Realizaron los cambios con satisfaccion"<<std::endl;

    }
    else
    {
        std::cout<<"No se pudieron realizar los cambios"<<std::endl;
    }

    system("pause");


    delete []DatoReserva;
}

void BorrarReserva()
{
    system("cls");
    int dni, TotalCantidad, Opcion;
    ArchivoReservas InfoReservas;
    Reservas *vec, NuevoRegistro;
    bool primeravez=true;

    if(InfoReservas.CrearBackUpManual())
    {
        std::cout<<"Se ha creado una copia de los registros de Reservas"<<std::endl;
        system("pause");
        system("cls");
        std::cout<<"Ingrese el Dni del Cliente: "<<std::endl;
        std::cin>>dni;

        TotalCantidad = InfoReservas.contarRegistros();
        vec = new Reservas[TotalCantidad];

        InfoReservas.LeerRegistrosTotales(*vec, TotalCantidad);

        for(int x=0; x<TotalCantidad; x++)
        {

            if(vec[x].getTipoDePago().getCliente().getDNI() == dni)
            {

                vec[x].Mostrar();
                std::cout<<"Desea borrar este archivo? 1 - SI / 2 - NO"<<std::endl;
                std::cout<<"Digite una opcion: ";
                std::cin>>Opcion;

                if((Opcion != 1) && (primeravez==true))
                {

                    NuevoRegistro = vec[x];
                    InfoReservas.grabarRegistroNuevo(NuevoRegistro);///Sirve para grabar en archivo nuevo con una apertura wb y pisando el archivo viejo.
                    primeravez = false;///Fer: Este if es por que se crea el nuevo archivo como "wb" asi borra el anterior, el que ya se guardo como back up. Una vez pasado por aca, salta a la linea 177 revisar
                }

                else if( Opcion !=1)
                {

                    NuevoRegistro = vec[x];
                    if(InfoReservas.GrabarRegistro(NuevoRegistro)) {} ///Sirve para guardar ya con el nuevo archivo creado en la linea 169, tiene apertura con "ab".

                }

                else
                {

                    std::cout<<"Registro Borrado"<<std::endl;
                    system("pause");
                }

            }

            else if(primeravez==true)///a pesar de la linea 177, este else if, sirve por que no siempre coinciden el dni ingresado con el que se quiere ingresar. Se busca el dni y cuando no coincide, entra por esta parte.
            {

                NuevoRegistro = vec[x];
                InfoReservas.grabarRegistroNuevo(NuevoRegistro);///Sirve para grabar en archivo nuevo con una apertura wb y pisando el archivo viejo.
                primeravez = false;///Fer: Mismo motivo que linea 177
            }

            else
            {
                NuevoRegistro = vec[x];
                if(InfoReservas.GrabarRegistro(NuevoRegistro)) {} ///Sirve para guardar ya con el nuevo archivo creado, tiene apertura con "ab".

            }
        }


    }
    else
    {

        std::cout<<"No se ha creado copia de los registros de Reservas"<<std::endl;
        system("pause");
    }



    delete []vec;

}

void EstadoReserva()
{

    system("cls");
    ArchivoReservas InfoReservas;
    Reservas *DatosReservas;
    int dni;
    int TotalRegistros = InfoReservas.contarRegistros();

    if(TotalRegistros<=0)
    {

        std::cout<<"No hay reservas gestionadas"<<std::endl;
        system("pause");
        return;

    }
    DatosReservas = new Reservas[TotalRegistros];
    InfoReservas.LeerRegistrosTotales(*DatosReservas,TotalRegistros);
    std::cout<<"Ingrese el Dni de la persona que realizo la reserva: ";
    std::cin>>dni;
    std::cout<<std::endl;
    InfoReservas.verificarEstadoReserva(DatosReservas, TotalRegistros, dni);

    delete []DatosReservas;

}

void MostrarArchivoReservas()
{

    system("cls");
    bool loop = true;
    int opcion;
    ArchivoReservas InfoReservas;
    do
    {
        std::cout<<"1 - Mostrar Reservas Activa"<<std::endl;
        std::cout<<"2 - Mostrar Back Up Reservas"<<std::endl;
        std::cout<<"0 - Volver al menu anterior"<<std::endl;
        std::cout<<"Ingrese una opcion: ";
        std::cin>>opcion;

        switch(opcion)
        {

        case 1:


            InfoReservas.ListarRegistros();
            loop=false;

            break;

        case 2:

            InfoReservas.setAperturaArchivo("Reservas.bak");
            InfoReservas.ListarRegistros();
            loop=false;

            break;

        case 0:

            loop = false;

            break;

        default:

            std::cout<<"Opcion Incorredcta, seleccione una nueva"<<std::endl;
            system("pause");


        }
    }
    while(loop);
}
