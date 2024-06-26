#ifndef MENUINFORMES_H_INCLUDED
#define MENUINFORMES_H_INCLUDED

#include <cstring>
#include <cstdlib>
#include "ArchivoReservas.h"
#include "ArchivoClientes.h"
#include "ArchivoCarpas.h"
#include "ArchivoCabanias.h"
#include "Reservas.h"

void informeMensual();
void facturacionTotal();
void mostrarCabaniasReservadas();
void mostrarCarpasReservadas();

void OpcionesDeInformes(){
    system("cls");
    bool loop=true;
    int opc;
    while(loop){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Informe mensual "<<endl;
        cout<<"2 - Facturacion total"<<endl;
        cout<<"3 - Mostrar cabañas en uso"<<endl;
        cout<<"4 - Mostrar carpas en uso"<<endl;
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
            facturacionTotal();
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarCabaniasReservadas();
            system("pause");
            system("cls");
            break;
        case 4:
            mostrarCarpasReservadas();
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
    Reservas obj;
    int contador;
    float ocupacionMensual;
    float recaudacion;
    system("cls");
    std::cout<<"INFORMACION DE CLIENTES"<<std::endl;
    std::cout<<"-----------------------"<<std::endl;
    int cantidad=InfoCliente.contarRegistros();
    cout<<"La cantidad de clientes registrados en el sistema son: "<<cantidad<<endl;
    system("pause");
    system("cls");
    std::cout<<"INFORMACION DE CABANIAS"<<std::endl;
    std::cout<<"-----------------------"<<std::endl;
    for(int i=1;i<=12;i++){
        contador=0;
        recaudacion=0;
        cout<<"Mes: "<<i<<endl;
        int cantidad=InfoCabanias.contarRegistros();
        for(int z=0;z<cantidad;z++){
            obj=InfoCabanias.leerRegistro(z);
            if(obj.getEstado()){
                if(obj.getFechaDesde().getMes()==i){
                    contador++;
                    recaudacion+=obj.getTipoDePago().getMonto();
                }
            }
        }
        cout<<"La cantidad de reservas efectuadas el mes "<<i<<" es: "<<contador<<endl;
        cout<<"La ocupacion del mes "<<i<<" es:"<<(contador/5)*100<<"%"<<endl;
        cout<<"El monto recaudado el mes "<<i<<" es: "<<recaudacion<<endl;
        system("pause");
    }
    system("cls");
    std::cout<<"INFORMACION DE CARPAS"<<std::endl;
    std::cout<<"---------------------"<<std::endl;
    for(int i=1;i<=12;i++){
        contador=0;
        recaudacion=0;
        cout<<"Mes: "<<i<<endl;
        int cantidad=InfoCarpas.contarRegistros();
        for(int z=0;z<cantidad;z++){
            obj=InfoCarpas.leerRegistro(z);
            if(obj.getEstado()){
                if(obj.getFechaDesde().getMes()==i){
                    contador++;
                    recaudacion+=obj.getTipoDePago().getMonto();
                }
            }
        }
        cout<<"La cantidad de reservas efectuadas el mes "<<i<<" es: "<<contador<<endl;
        cout<<"La ocupacion del mes "<<i<<" es:"<<(contador/10)*100<<"%"<<endl;
        cout<<"El monto recaudado el mes "<<i<<" es: "<<recaudacion<<endl;
        system("pause");
    }
    system("pause");
}

void facturacionTotal(){
    system("cls");
    ArchivoReservas archiR;
    Reservas obj;
    int contador=0;
    float recaudacion=0;
    int cantidad=archiR.contarRegistros();
    for(int i=0;i<cantidad;i++){
        obj=archiR.LeerRegistro(i);
        if(obj.getEstado()){
            contador++;
            recaudacion+=obj.getTipoDePago().getMonto();
        }
    }
    cout<<"La cantidad de ventas fue: "<<contador<<endl;
    cout<<"El monto recaudado total es: "<<recaudacion<<endl;
    system("pause");
}

void mostrarCabaniasReservadas(){
    ArchivoCabanias archiC;
    Reservas aux;
    int cant=archiC.contarRegistros();
    cout<<"Cabanias reservadas:" <<endl;
    if(cant==0){
        cout<<"No hay cabanias reservadas"<<endl;
        system("pause");
        return;
    }
    for(int i=0;i<cant;i++){
        aux=archiC.leerRegistro(i);
        if(aux.getEstado()){
            aux.Mostrar();
            cout<<"--------------------------------"<<endl;
        }
    }
}

void mostrarCarpasReservadas(){
    ArchivoCarpas archiC;
    Reservas aux;
    int cant=archiC.contarRegistros();
    if(cant==0){
        cout<<"No hay carpas reservadas"<<endl;
        system("pause");
        return;
    }
    cout<<"Carpas reservadas:"<<endl;
    for(int i=0;i<cant;i++){
        aux=archiC.leerRegistro(i);
        if(aux.getEstado()){
            aux.Mostrar();
            cout<<"--------------------------------"<<endl;
        }
    }
}

#endif // MENUINFORMES_H_INCLUDED
