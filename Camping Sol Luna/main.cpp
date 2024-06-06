#include <iostream>
#include <cstring>
using namespace std;
#include "MenuReservas.h"
#include "MenuClientes.h"
#include "MenuInformes.h"
#include "Reservas.h"
#include "ArchivoClientes.h"

int main()
{
    bool Ejecutar = true;
    int Opcion;

    do{
        system("cls");
       cout<<"-----Camping SOL-LUNA-----"<<endl;
       cout<<"1 - Ingresar a menu reservas "<<endl;
       cout<<"2 - Ingresar a menu clientes "<<endl;
       cout<<"3 - Ingresar a menu informes "<<endl;
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
            OpcionesDeInformes();

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
