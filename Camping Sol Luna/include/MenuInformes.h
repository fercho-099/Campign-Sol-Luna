#ifndef MENUINFORMES_H_INCLUDED
#define MENUINFORMES_H_INCLUDED

#include <cstring>
#include <cstdlib>
#include "ArchivoReservas.h"
#include "ArchivoClientes.h"
#include "ArchivoCarpas.h"
#include "ArchivoCabanias.h"

void informeMensual();
void informeUltimo30Dias();
void facturacionTotal();
void mostrarCabaniasEnUso();
void mostrarCarpasEnUso();

void OpcionesDeInformes(){
    system("cls");
    bool loop=true;
    int opc;
    while(loop){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Informe mensual "<<endl;
        cout<<"2 - Informe ultimos 30 dias "<<endl;
        cout<<"3 - Facturacion total"<<endl;
        cout<<"4 - Mostrar cabañas en uso"<<endl;
        cout<<"5 - Mostrar carpas en uso"<<endl;
        cout<<"0 - Volver al menu anterior"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc){
        case 1:
            informeMensual();
            system("pause");
            system("cls");
            break;
        case 2:
            informeUltimo30Dias();
            system("pause");
            system("cls");
            break;
        case 3:
            facturacionTotal();
            system("pause");
            system("cls");
            break;
        case 4:
            mostrarCabaniasEnUso();
            system("pause");
            system("cls");
            break;
        case 5:
            mostrarCarpasEnUso();
            system("pause");
            system("cls");
            break;
        case 0:
            loop=false;
            break;
        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            system("pause");
        }
    }
}

void informeMensual()
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

void informeUltimo30Dias()
{

}

void facturacionTotal()
{

}

void mostrarCabaniasEnUso(){
    ArchivoCabanias archiC;
    Reservas aux;
    int cant=archiC.contarRegistros();
    cout<<"Cabanias disponibles:"<<endl;
    int cabanias=10;
    int contador;
    for(int i=0;i<cant;i++){
        aux=archiC.leerRegistro(i);
        if(aux.getEstado()){
            for(int i=0;i<cabanias;i++){
                contador=0;
                if(aux.getTipoDePago().getVecCabania()[i]==true){
                        contador++;
                    }
            }
            if(contador==0){
                cout<<i+1<<endl;
            }
        }
    }
}



void mostrarCarpasEnUso(){
    ArchivoCarpas archiC;
    Reservas aux;
    int cant=archiC.contarRegistros();
    cout<<"Carpas disponibles:"<<endl;
    int carpas=20;
    int contador;
    for(int i=0;i<cant;i++){
        aux=archiC.leerRegistro(i);
        if(aux.getEstado()){
            for(int i=0;i<carpas;i++){
                contador=0;
                if(aux.getTipoDePago().getVecCarpa()[i]==true){
                        contador++;
                    }
            }
            if(contador==0){
                cout<<i+1<<endl;
            }
        }
    }
}

#endif // MENUINFORMES_H_INCLUDED
