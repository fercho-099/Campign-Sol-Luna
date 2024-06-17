#include <iostream>
#include <cstring>
using namespace std;
#include "MenuReservas.h"
#include "MenuClientes.h"
#include "Reservas.h"

int main()
{
    bool Ejecutar = true;
    int Opcion;
    Fecha obj;
    Reservas aux;
    Fecha Fdesde;
    Fecha Fhasta;
    int valor, diasrest,total;

    do{
        system("cls");
       cout<<"-----Camping SOL-LUNA-----"<<endl;
       cout<<"1 - Reservas "<<endl;
       cout<<"2 - Clientes "<<endl;
       cout<<"3 - Informes "<<endl;
       cout<<"4 - Pruebas Fecha "<<endl;
       cout<<"0 - Cerrar Programa "<<endl;
       cout<<endl;
       cout<<"Ingrese una opcion: ";
       cin>>Opcion;

       switch(Opcion){

   case 1:
            OpcionesDeReservas();

            break;

   case 2:

            OpcionesDeClientes();
            break;

   case 3:
            ///OpcionesDeInformes();

            break;

   case 4:

            cout<<"Ingrese una fecha de entrada: "<<endl;
            Fdesde.Cargar();
            cout<<"Ingrese una fecha de salida: "<<endl;
            Fhasta.Cargar();
            aux.setFechaDesde(Fdesde);
            aux.setFechaHasta(Fhasta);
            cout<<"pago por noche: "<<endl;
            cin>>valor;
            diasrest = aux.RestanteFecha();
            total = diasrest * valor;
            cout<<"Total de noches: "<<diasrest<<endl;
            cout<<"Total a pagar: "<<total<<endl;


            system("pause");
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
