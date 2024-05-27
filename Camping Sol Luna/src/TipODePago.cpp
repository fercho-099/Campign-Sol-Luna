#include <iostream>

using namespace std;

#include "TipODePago.h"

#include <cstring>


void TipoDePago::Cargar()
{

    bool sectordisponible = true;
    system("cls");

    InfoCliente.Cargar();
    cout<<"Ingrese el ID Servicio(1- Carpa 2- Cabaña): ";
    cin>>IDServicio;
    cout<<endl;
    do
    {
        cout<<"Ingrese el Sector correcpondiente (A-C): ";
        cin>>IDSector;

        if((strcmp(IDSector,"a")!=0) || (strcmp(IDSector,"A")!=0) || (strcmp(IDSector,"b")!=0) || (strcmp(IDSector,"B")!=0) || (strcmp(IDSector,"c")!=0) || (strcmp(IDSector,"C")!=0)){
        cout<<"Opcion Incorrecta, ingrese nuevamente una opcion valida"<<endl;
        system("pause");
        }

        else
        {
            sectordisponible = false;
        }

    }while(sectordisponible);///esto verifica que el sector ingresado sea el correcto de la letra "a" a la "c" verifica que sea tanto mayuscula como minuscula habilitados para poner un sector valido.

            cout<<" Medio a pagar: ";
            cin>>ModoPago;
            cout<<endl;
            FechaPago.Cargar();
            cout<<"Ingrese el Monto: ";
            cin>>Monto;
            cout<<endl;
            Estado = 1; ///reservado- Hay que ver como modificar de reservado a pagado si se pago la totalidad. En caso de pagar la totalidad, se debe poner 0 u otro numero, y en caso de cancelado, valor 2.
    }
}

void TipoDePago::Mostrar(){

        system("cls");
        InfoCliente.Mostrar();
        cout<<"Servicio: "<<IDServicio<<endl;
        cout<<"Sector asignado: "<<IDSector<<endl;
        cout<<"Estado de Reserva: "<<Estado<<endl;///informar el estado en palabras no en numeros.
       cout<<"Modo de Pago: "ModoPago<<endl;
       cout<<" Fecha de Pago"<<endl;
       cout<<FechaPago<<endl;
       cout<<"Monto abonado: "<<Monto<<endl;
       system("pause");
}

void TipoDePago::setCliente(Cliente datos){

    InfoCliente = datos;

}

void TipoDePago::setIDServicio(int idservicio){

    IDServicio=idservicio;
}

void TipoDePago::setIDSector(const char * idsector){

    strcpy(IDSector,idsector);

}

void TipoDePago::setModoPago(const char *modopago){

    strcpy(ModoPago,modopago);
}

void TipoDePago::setFechaPago(Fecha fechaopago){

    FechaPago = fechapago;

}

void TipoDePago::setMonto(float monto){

    Monto = monto;
}

void TipoDePago::setEstado(bool estado){

    Estado = estado;

}

Cliente TipoDePago::getCliente(){

    return InfoClientes;

}

int TipoDePago::getIDServicio(){

    return IDServicio;
}

char TipoDePago::getIDSector(){

    return IDSector;
}

char TipoDePago::getModoPago(){

    return ModoPago;
}

Fecha TipoDePago::getFechaPago(){

    return FechaPago;
}

float TipoDePago::getMonto(){

    return Monto;

}

bool TipoDePago::getEstado(){

    return Estado;

}
