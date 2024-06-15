#include <iostream>

using namespace std;

#include "TipODePago.h"
#include "Reservas.h"
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
        cout<<"Ingrese el Sector correspondiente (A-C): ";
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

            cout<<"Medio a pagar (1-Efectivo 2-Tarjeta de debito/credito): ";
            cin>>modoDePago;
            cout<<endl;
            std::cout<<"La fecha de pago se cargo correctamente"<<std::endl;
            FechaPago.CargarActual();/// poner fecha modo automatico preguntando si paga en el momento o no.
            system("pause");
            system("cls");
            cout<<"Ingrese el Monto: ";
            cin>>Monto;
            if(Monto <= 0){
                cout<<"Ingrese un Monto mayor a 0: ";
                cin>>Monto;
            }
            cout<<endl;
            estado = true; ///reservado- Hay que ver como modificar de reservado a pagado si se pago la totalidad. En caso de pagar la totalidad, se debe poner 0 u otro numero, y en caso de cancelado, valor 2.
}

/*void TipoDePago::CargarPrueba()
{
    Reservas obj;
    bool Disponible = true;

    cout<<"Por favor, cargue la fecha de entrada";
    obj.Desde.Cargar();

    cout<<"Por favor, cargue la fecha de salida";
    obj.Hasta.Cargar();

    cout<<"Ingrese el ID Servicio(1- Carpa 2- Cabania): ";
    cin>>IDServicio;

    int restante = obj.RestanteFechas();



    ///Alan
    ///Aca tendria que contar los registros de los dos archivos, cabaña y carpa, y en caso
    ///de que se ingrese 1 o 2 hacer un switch asi lee el idservicio correspondiente
    ///despues de esa preguntar la disponibilidad por las fechas ingresadas
    ///listar los id de carpa o cabaña disponible segun el idservicio correspondiente
    ///Ingresar el id para que guarde la reserva, el monto deberia ser estatico entonces aca
    ///lo que se hace es hacer la resta entre fecha de ingreso y salida para que
    ///me de el total de dias que van a ocupar el servicio y multiplicarlo x el monto
    ///asi me da el total que el cliente debe abonar, despues se pregunta si desea continuar
    ///con la reserva S/N, si desea continuar se consulta como abona, efectivo o tarjeta
    ///selecciona una de estas opciones y se procede a cargar la fecha de pago y se realiza
    ///la reserva

    estado = true; ///reservado- Hay que ver como modificar de reservado a pagado si se pago la totalidad. En caso de pagar la totalidad, se debe poner 0 u otro numero, y en caso de cancelado, valor 2.
}*/


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

