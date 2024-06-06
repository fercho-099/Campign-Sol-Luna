#pragma once

#include "ArchivoReservas.h"
#include "Reservas.h"

void cargarReserva();
void modificarReserva();
void borrarReserva();


void OpcionesDeReservas(){
system("cls");
 int opc;
 bool loop=true;


    do{
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Crear una reserva "<<endl;
        cout<<"2 - Modificar una reserva "<<endl;
        cout<<"3 - Borrar una reserva"<<endl;
        cout<<"0 - Volver al menu anterior"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc){
        case 1:
            cargarReserva();
            break;
        case 2:
            //modificarReserva();
            break;
        case 3:
            borrarReserva();
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

void cargarReserva(){

    Reservas DatosReservas;
    ArchivoReservas InfoReservas;
    DatosReservas.Cargar();
    if(InfoReservas.grabarRegistro(DatosReservas)) {std::cout<<"Se guardo Guardo correctamente la reserva"<<std::endl;
    system("pause");
    }
    else{
        std::cout<<"No se Gestionar la reserva"<<std::endl;
        system("pause");
    }
}

/*void modificarReserva(){

    Reservas *DatosReservas, aux;
    ArchivoReservas InfoReservas;
    int TotalRegistros = InfoReservas.contarRegistros();

    if(TotalRegistros<0){
        std::cout<<"No hay reservas gestionadas, realice una"<<std::endl;
        system("pause");
        return;
    }

    DatosReservas = new Reservas[TotalRegistros];

    InfoReservas.LeerRegistrosTotales(*DatosReservas, TotalRegistros);///debe tener todos los registros metidos en ram
    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;
    InfoReservas.BuscarRegistros(*DatosReservas, TotalRegistros, dni);

delete[]DatosReservas;
}*/

void borrarReserva(){
    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;
    ///FALTA TERMINAR
}




