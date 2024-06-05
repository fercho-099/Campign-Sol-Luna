
#pragma once

/*
#ifndef MENURESERVAS_H
#define MENURESERVAS_H

#include "Reservas.h"
#include "Archivo Reservas.h"


void cargarReserva();
void modificarReserva();
void borrarReserva();


void OpcionesDeReservas();

void OpcionesDeReservas(){
system("cls");
 int opc;
 bool loop=true;
 ///Reservas datos;
 ///ArchivoReservas info("Reservas.dat");

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
            modificarReserva();
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

>>>>>>> Stashed changes
void cargarReserva(){
    Reservas obj;
    obj.Cargar();
}

void modificarReserva(){
    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;
    ///FALTA TERMINAR
}

void borrarReserva(){
    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;
    ///FALTA TERMINAR
}
<<<<<<< Updated upstream
=======


#endif
*/

