#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED
#include <cstdlib>
#include <cstring>

void OpcionesDeClientes();

void OpcionesDeClientes(){
    system("cls");
    bool loop=true;
    int opc;
    while(loop){
        cout<<"-----Camping SOL-LUNA-----"<<endl;
        cout<<"1 - Ingresar nuevo cliente "<<endl;
        cout<<"2 - Modificar datos de un cliente "<<endl;
        cout<<"3 - Dar de baja a un cliente"<<endl;
        cout<<"4 - Listar a todos los clientes"<<endl;
        cout<<"5 - Buscar a un cliente"<<endl;
        cout<<"6 - Verificar estado de un cliente"<<endl;
        cout<<"7 - Crear una copia de seguridad de los clientes"<<endl;
        cout<<"0 - Salir del menu"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc){
        case 1:
            ///cargarCliente();
            break;
        case 2:
            ///modificarCliente();
            break;
        case 3:
            ///borrarCliente();
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

#endif // MENUCLIENTES_H_INCLUDED

