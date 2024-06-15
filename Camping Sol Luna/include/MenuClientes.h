#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED

#include <cstdlib>
#include <cstring>

#include "ArchivoClientes.h"

void OpcionesDeClientes();
void cargarCliente();
void modificarCliente();
void bajaCliente();
void listarClientes();
void buscarCliente();
void verificarEstadoCliente();
void crearBackupClientes();

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
        system("cls");
        switch(opc){
        case 1:
            cargarCliente();
            system("pause");
            system("cls");
            break;
        case 2:
            modificarCliente();
            system("pause");
            system("cls");
            break;
        case 3:
            bajaCliente();
            system("pause");
            system("cls");
            break;
        case 4:
            listarClientes();
            system("pause");
            system("cls");
            break;
        case 5:
            buscarCliente();
            system("pause");
            system("cls");
            break;
        case 6:
            verificarEstadoCliente();
            system("pause");
            system("cls");
            break;
        case 7:
            crearBackupClientes();
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

void cargarCliente(){
    Cliente obj;
    obj.Cargar();
    ArchivoClientes archiC;
    archiC.grabarRegistro(obj);
}

void modificarCliente(){
    int dni;
    char caracter;
    Cliente aux;
    cout<<"Ingrese el Dni del cliente a modificar:"<<endl;
    cin>>dni;
    ArchivoClientes archiC;
    int pos=archiC.buscarRegistro(dni);
    if(pos>=0){
        cout<<"Desea modificar este cliente?"<<endl;
        aux=archiC.leerRegistro(pos);
        aux.Mostrar();
        cout<<"S(si)/N(no)"<<endl;
        cin>>caracter;
        switch(caracter){
        case('S'):
            {
            aux.Cargar();
            archiC.modificarRegistro(aux,pos);
            cout<<"El cliente fue modificado con exito"<<endl;
            return;
            break;
            }
        case('s'):
            {
            aux.Cargar();
            archiC.modificarRegistro(aux,pos);
            cout<<"El cliente fue modificado con exito"<<endl;
            return;
            break;
            }
        case('N'):
            return;
        case('n'):
            return;
        default:
            cout<<"Ingrese una opcion valida"<<endl;
        }
    }else return;
}

void bajaCliente(){
    int dni;
    cout<<"Ingrese el dni del cliente a dar de baja:"<<endl;
    cin>>dni;
    ArchivoClientes archiC;
    Cliente aux;
    int pos=archiC.buscarRegistro(dni);
    aux=archiC.leerRegistro(pos);
    aux.setEstado(false);
    if(archiC.modificarRegistro(aux,pos)){
        cout<<"Se dio de baja al cliente"<<endl;
    }else cout<<"No se pudo dar de baja al cliente"<<endl;
}

void listarClientes(){
    ArchivoClientes archiC;
    archiC.listarRegistros();
}

void buscarCliente(){
    int dni;
    ArchivoClientes archiC;
    Cliente aux;
    cout<<"Ingrese el dni del cliente a buscar:"<<endl;
    cin>>dni;
    int pos=archiC.buscarRegistro(dni);
    aux=archiC.leerRegistro(pos);
    aux.Mostrar();
}

void verificarEstadoCliente(){
    ArchivoClientes archiC;
    int dni;
    cout<<"Ingrese el dni del cliente a verificar:"<<endl;
    cin>>dni;
    archiC.verificarEstadoCliente(dni);
}

void crearBackupClientes(){
    ArchivoClientes archiC;
    if(archiC.crearBackupClientes()){
        cout<<"Se creo la copia de seguridad con exito"<<endl;
    }else cout<<"No se pudo realizar la copia de seguridad"<<endl;
}

#endif // MENUCLIENTES_H_INCLUDED
