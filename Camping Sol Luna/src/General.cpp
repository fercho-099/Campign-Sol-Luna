#include <iostream>

using namespace std;

#include "General.h"
#include "ArchivoReservas.h"
#include "ArchivoCabanias.h"
#include "ArchivoCarpas.h"
#include "ArchivoClientes.h"
#include "Reservas.h"
#include "Cliente.h"

void OpcionesDeInformes(){

    system("cls");

    bool ciclo = true;
    int opcion;
    General Opcion;
    do{

        std::cout<<"INFORMES"<<std::endl;
        std::cout<<"--------"<<std::endl;
        std::cout<<"1 - Informes Mensual"<<std::endl;
        std::cout<<"2 - Facturacion Total"<<std::endl;
        std::cout<<"3 - Mostrar Cabanias en uso"<<std::endl;
        std::cout<<"4 - Mostrar Carpas en uso"<<std::endl;
        std::cout<<"0 - Volver al menu anterior"<<std::endl;
        std::cout<<"Ingrese una opcion: ";
        std::cin>>opcion;

        switch(opcion){

    case 1:
                Opcion.InformeMensual();
        break;

    case 2:

                Opcion.facturacionTotal();

        break;

    case 3:

                Opcion.mostrarCabaniasEnUso();

        break;

    case 4:

                Opcion.mostrarCarpasEnUso();

        break;

    case 0:

        break;

    default:

        system("cls");
        std::cout<<"Opcion Incorrecta, seleccione una opcion valida"<<std::endl;
        system("pause");

        }

    }while(ciclo);



}

General::General()
{

}

void General::InformeMensual()
{
       ArchivoClientes InfoCliente("Clientes.dat");

       ArchivoCabanias InfoCabanias("Cabanias.dat");

       ArchivoCarpas InfoCarpas("Carpas.dat");

       ArchivoReservas  InfoReservas("Reservas.dat");

        system("cls");
        std::cout<<"INFORMACION DE CLIENTES"<<std::endl;
        std::cout<<"-----------------------"<<std::endl;
        InfoCliente.listarRegistros();
        system("pause");
        system("cls");
        std::cout<<"INFORMACION DE CABANIAS"<<std::endl;
        std::cout<<"-----------------------"<<std::endl;
        InfoCabanias.listarRegistros();
        system("pause");
        system("cls");
        std::cout<<"INFORMACION DE CARPAS"<<std::endl;
        std::cout<<"---------------------"<<std::endl;
        InfoCarpas.listarRegistros();
        system("pause");
        system("cls");
        std::cout<<"INFORMACION DE RESERVAS"<<std::endl;
        std::cout<<"-----------------------"<<std::endl;
        InfoReservas.ListarRegistros();
        system("pause");
        system("cls");




}

void General::InformeUltimo30Dias()
{

}

void General::facturacionTotal()
{

}

void General::mostrarCabaniasEnUso()
{

}


void General::mostrarCarpasEnUso()
{

}

