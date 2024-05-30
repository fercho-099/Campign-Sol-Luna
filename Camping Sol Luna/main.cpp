#include <iostream>
#include <cstring>
using namespace std;
<<<<<<< Updated upstream
#include "Fecha.h"
#include "Funcion Generales.h"
#include "Cliente.h"
#include "TipODePago.h"
#include "Reservas.h"
#include "MenuReservas.h"
#include "Archivo Reservas.h"
=======

#include "Funcion Generales.h"
<<<<<<< Updated upstream

#include "MenuReservas.h" /// O lo hacemos un menu conn un .h aparte o lo hacemos abaho de este main.
//#include "Fecha.h"
//#include "Funcion Generales.h"
//#include "Cliente.h"
//#include "TipODePago.h"
//#include "Reservas.h"///Para que sirve esto
#include "Archivo Reservas.h"

=======
#include "Fecha.h"
#include "Cliente.h"
#include "TipODePago.h"
#include "Reservas.h"
>>>>>>> Stashed changes

void Informes();
void Reservas();
void Clientes();
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
            Reservas();
=======
            ///OpcionesDeReservas();
>>>>>>> Stashed changes

            break;

   case 2:
<<<<<<< Updated upstream
            Clientes();
=======
            ///OpcionesDeClientes();
>>>>>>> Stashed changes

            break;

   case 3:

<<<<<<< Updated upstream
            Informes();
=======
            ///OpcionesDeInformes();
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream

<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes

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
=======
>>>>>>> Stashed changes
