#include <iostream>
#include <cstring>
using namespace std;
#include "MenuReservas.h"
#include "Reservas.h"
#include "ArchivoClientes.h"

int main()
{
    bool Ejecutar = true;
    int Opcion;
    Fecha obj;
    Reservas aux;
    Fecha Fdesde;
    Fecha Fhasta;
    int valor;

    do{
        system("cls");
       cout<<"-----Camping SOL-LUNA-----"<<endl;
       cout<<"1 - Reservas "<<endl;
       cout<<"2 - Pruebas Fecha "<<endl;
       cout<<"2 - Clientes "<<endl;
       cout<<"3 - Informes "<<endl;
       cout<<"0 - Cerrar Programa "<<endl;
       cout<<endl;
       cout<<"Ingrese una opcion: ";
       cin>>Opcion;

       switch(Opcion){

   case 1:
           OpcionesDeReservas();

            break;

   case 2:

            Fdesde.Cargar();
            Fhasta.Cargar();
            aux.setFechaDesde(Fdesde);
            aux.setFechaHasta(Fhasta);
            valor = aux.RestanteFecha();
            cout<<"valor: "<<valor;

            system("pause");
            ///OpcionesDeClientes();
            break;

   case 3:
            ///OpcionesDeInformes();

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
