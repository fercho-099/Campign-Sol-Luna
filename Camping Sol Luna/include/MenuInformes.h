/*
#ifndef MENUINFORMES_H_INCLUDED
#define MENUINFORMES_H_INCLUDED
#include <cstring>
#include <cstdlib>
#include "General.h"
void OpcionesDeInformes();


void OpcionesDeInformes(){
        system("cls");
int opc;
    while(true){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Informe mensual "<<endl;
        cout<<"2 - Informe ultimos 30 dias "<<endl;
        cout<<"3 - Facturacion total"<<endl;
        cout<<"4 - Mostrar caba�as en uso"<<endl;
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

#endif // MENUINFORMES_H_INCLUDED
*/
