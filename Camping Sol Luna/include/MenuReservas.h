#pragma once

#include "ArchivoReservas.h"
#include "Reservas.h"

void CargarReserva();
void ModificarReserva();
void BorrarReserva();
void EstadoReserva();
void MostrarArchivoReservas();
void OpcionesDeReservas(){
system("cls");
 int opc;
 bool loop=true;


    do{
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
        switch(opc){
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
    }while(loop);

}
///Fer: Cargar Reserva en teoria tiene que estar lista.

void CargarReserva(){

    Reservas DatosReservas;
    ArchivoReservas InfoReservas;
    DatosReservas.Cargar();
    if(InfoReservas.GrabarRegistro(DatosReservas)) {std::cout<<"Se guardo Guardo correctamente la reserva"<<std::endl;
    system("pause");
    }
    else{
        std::cout<<"No se Gestionar la reserva"<<std::endl;
        system("pause");
    }

}

///Modificar Reserva lista
void ModificarReserva(){/// se necesita verificar QUE RESERVA se debe modificar por que el dni mismo puede tener mas de una reserva activa.

    system("cls");
    ArchivoReservas InfoReservas;
    Reservas *DatoReserva, aux;
    int pos;
    int TotalRegistros = InfoReservas.contarRegistros();

    if(TotalRegistros<=0){
        std::cout<<"No se pudo realizar modificacion del registro"<<std::endl;
        system("pause");
        return;
    }
    DatoReserva = new Reservas[TotalRegistros];
    InfoReservas.LeerRegistrosTotales(*DatoReserva, TotalRegistros);///agregue esto

    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;

    /*pos = InfoReservas.BuscarRegistro(dni);///usar memoria dinamica, aca se usa memoria comun
    aux = InfoReservas.LeerRegistro(pos);///usar memotia dinamica*/
    pos = InfoReservas.BuscarRegistro(DatoReserva, TotalRegistros, dni);
    aux = InfoReservas.LeerRegistrosDinamicos(DatoReserva, pos);

    InfoReservas.ModificarRegistros(aux);///ver si se modifica correctamente
    if(InfoReservas.grabarRegistros(aux, pos)){

        std::cout<<"Se Realizaron los cambios con satisfaccion"<<std::endl;

    }
    else{
        std::cout<<"No se pudieron realizar los cambios"<<std::endl;
    }

    system("pause");


delete []DatoReserva;
}

///Borrar Reservas Lista
void BorrarReserva(){
    system("cls");
    int dni, TotalCantidad, Opcion;
    ArchivoReservas InfoReservas;
    Reservas *vec, NuevoRegistro;
    bool primeravez=true;
    if(InfoReservas.CrearBackUpManual()) {
        std::cout<<"Se ha creado una copia de los registros de Reservas"<<std::endl;
        system("pause");
        system("cls");
        std::cout<<"Ingrese el Dni del Cliente: "<<std::endl;
        std::cin>>dni;

        /*int pos = InfoReservas.BuscarRegistros(dni);/// Devuelve posicion para baja logica.
        aux = InfoReservas.LeerRegistro(pos);
        aux.setEstado(3);*/

        TotalCantidad = InfoReservas.contarRegistros();
        vec = new Reservas[TotalCantidad];

        InfoReservas.LeerRegistrosTotales(*vec, TotalCantidad);///hasta aca estamos bien

        for(int x=0; x<TotalCantidad; x++){

            if(vec[x].getTipoDePago().getCliente().getDNI() == dni){

                vec[x].Mostrar();
                std::cout<<"Desea borrar este archivo? 1 - SI / 2 - NO"<<std::endl;
                std::cout<<"Digite una opcion: ";
                std::cin>>Opcion;

                if((Opcion != 1) && (primeravez==true)){

                      NuevoRegistro = vec[x];
                       InfoReservas.grabarRegistroNuevo(NuevoRegistro);
                       primeravez = false;
                }

                else if( Opcion !=1){

                    NuevoRegistro = vec[x];
                    if(InfoReservas.GrabarRegistro(NuevoRegistro)){}

                }

                else{}

            }
        }






    }
    else{

        std::cout<<"No se ha creado copia de los registros de Reservas"<<std::endl;
        system("pause");
    }



delete []vec;

}

void EstadoReserva(){

system("cls");
ArchivoReservas InfoReservas;
Reservas *DatosReservas;
int dni;
int TotalRegistros = InfoReservas.contarRegistros();
if(TotalRegistros<=0){

    std::cout<<"No hay reservas gestionadas"<<std::endl;
    system("pause");
    return;

}
DatosReservas = new Reservas[TotalRegistros];
std::cout<<"Ingrese el Dni de la persona que realizo la reserva: ";
std::cin>>dni;

InfoReservas.verificarEstadoReserva(DatosReservas, TotalRegistros, dni);

delete []DatosReservas;

}

void MostrarArchivoReservas(){


ArchivoReservas InfoReservas;
InfoReservas.ListarRegistros();
}
