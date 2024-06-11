#include <iostream>

using namespace std;

#include "TipODePago.h"

#include <cstring>

void TipoDePago::Cargar()
{

    bool sectorValido= true;
    system("cls");

    InfoCliente.Cargar();
    cout<<"Ingrese el ID Servicio(1- Carpa 2- Cabania): ";
    cin>>IDServicio;
    cout<<endl;
    do
    {
        cout<<"Ingrese el Sector correcpondiente (A-C): ";
        cin>>IDSector;

        if((strcmp(IDSector,"a")==0) || (strcmp(IDSector,"A")==0) || (strcmp(IDSector,"b")==0) || (strcmp(IDSector,"B")==0) || (strcmp(IDSector,"c")==0) || (strcmp(IDSector,"C")==0)){

            sectorValido = false;
        }

        else
        {
            cout<<"Opcion Incorrecta, ingrese nuevamente una opcion valida"<<endl;
            system("pause");
        }

    }while(sectorValido);///esto verifica que el sector ingresado sea el correcto de la letra "a" a la "c" verifica que sea tanto mayuscula como minuscula habilitados para poner un sector valido.

            cout<<" Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
            cin>>modoDePago;
            cout<<endl;
            std::cout<<"Se procedera a cargar la fecha de pago"<<std::endl;
            FechaPago.Cargar();/// poner fecha modo automatico preguntando si paga en el momento o no.
            cout<<"Ingrese el Monto: ";
            cin>>Monto;
            cout<<endl;
            estado = true; ///reservado- Hay que ver como modificar de reservado a pagado si se pago la totalidad. En caso de pagar la totalidad, se debe poner 0 u otro numero, y en caso de cancelado, valor 2.
}



void TipoDePago::Mostrar(){

        system("cls");
        InfoCliente.Mostrar();
        cout<<"Servicio: "<<IDServicio<<endl;
        cout<<"Sector asignado: "<<IDSector<<endl;
        ///cout<<"Estado de Reserva: "<<Estado<<endl;///informar el estado en palabras no en numeros.
        cout<<"Modo de Pago: ";
        if(modoDePago==1){
            cout<<"Efectivo "<<endl;
        }else cout<<"Tarjeta de debito/credito "<<endl;
        cout<<" Fecha de Pago"<<endl;
        FechaPago.Mostrar();
        cout<<"Monto abonado: "<<Monto<<endl;
        system("pause");
}

/*TipoDePago::TipoDePago()
{
       InfoCliente;
       IDServicio = 0;
       modoDePago = 0;
       strcpy(IDSector,"NULL");
       FechaPago;
       Monto = 0;
       estado = false;
}*/


void TipoDePago::setCliente(Cliente datos){

    InfoCliente = datos;

}

void TipoDePago::setIDServicio(int idservicio){

    IDServicio=idservicio;
}

void TipoDePago::setIDSector(const char * idsector){

    strcpy(IDSector,idsector);

}

void TipoDePago::setModoDePago(int _modopago){

    modoDePago=_modopago;
}

void TipoDePago::setFechaPago(Fecha fechapago){

    FechaPago = fechapago;

}

void TipoDePago::setMonto(float monto){

    Monto = monto;
}

void TipoDePago::setEstado(bool _estado){

    estado = _estado;

}

Cliente TipoDePago::getCliente(){

    return InfoCliente;

}

int TipoDePago::getIDServicio(){

    return IDServicio;
}

const char* TipoDePago::getIDSector(){

    return IDSector;
}

int TipoDePago::getModoDePago(){

    return modoDePago;
}

Fecha TipoDePago::getFechaDePago(){

    return FechaPago;
}

float TipoDePago::getMonto(){

    return Monto;

}

bool TipoDePago::getEstado(){

    return estado;

}

