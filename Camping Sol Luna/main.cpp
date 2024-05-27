#include <iostream>
using namespace std;
#include "Fecha.h"
#include "Funcion Generales.h"
#include "Cliente.h"
#include "TipODePago.h"
#include "Reservas.h"
#include "MenuReservas.h"
#include "Archivo Reservas.h"

int main()
{
    bool Ejecutar = true;
    int Opcion;

    do{
        system("cls");
       cout<<"-----Camping SOL-LUNA-----"<<endl;
       cout<<"1 - Reservas "<<endl;
       cout<<"2 - Clientes "<<endl;
       cout<<"3 - Informes "<<endl;
       cout<<"0 - Cerrar Programa "<<endl;
       cout<<endl;
       cout<<"Ingrese una opcion: ";
       cin>>Opcion;

       switch(Opcion){

   case 1:
            Reservas();

            break;

   case 2:
            Clientes();

            break;

   case 3:

            Informes();

            break;

   case 0:

            Ejecutar = false;

            break;

   default:

            cout<<"Opcion invalida, seleccione una opcion valida"<<endl;
            system("pause");
            }


    }while(Ejecutar);


    return 0;
}



void Reservas(){
    int opc;
    while(true){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Crear una reserva "<<endl;
        cout<<"2 - Modificar una reserva "<<endl;
        cout<<"3 - Borrar una reserva"<<endl;
        cout<<"0 - Salir del menu"<<endl;
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
            false;
        }
    }
}



void Clientes(){
    int opc;
    while(true){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Ingresar nuevo cliente "<<endl;
        cout<<"2 - Modificar datos de un cliente "<<endl;
        cout<<"3 - Borrar un cliente"<<endl;
        cout<<"0 - Salir del menu"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc){
        case 1:
            cargarCliente();
            break;
        case 2:
            modificarCliente();
            break;
        case 3:
            borrarCliente();
            break;
        case 0:
            false;
        }
    }
}



void Informes(){
    int opc;
    while(true){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Informe mensual "<<endl;
        cout<<"2 - Informe ultimos 30 dias "<<endl;
        cout<<"3 - Facturacion total"<<endl;
        cout<<"4 - Mostrar cabañas en uso"<<endl;
        cout<<"5 - Mostrar carpas en uso"<<endl;
        cout<<"0 - Salir del menu"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc){
        case 1:
            informeMensual();
            break;
        case 2:
            informeUltimo30Dias();
            break;
        case 3:
            facturacionTotal();
            break;
        case 4:
            mostrarCabaniasEnUso();
            break;
        case 5:
            mostrarCarpasEnUso();
            break;
        case 0:
            false;
        }
    }
}
