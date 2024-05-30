#include <iostream>
#include <cstring>
using namespace std;

#include "Reservas.h"

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
            ///OpcionesDeReservas();
            {
            Reservas objeto;
            objeto.Cargar();
            objeto.Mostrar();
            system("pause");
            }
            break;

   case 2:
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
