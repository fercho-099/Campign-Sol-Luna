/*
#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED
#include <cstdlib>
#include <cstring>
void OpcionesMenuClientes();

void OpcionesMenuClientes(){

system("cls");
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

#endif // MENUCLIENTES_H_INCLUDED
*/
