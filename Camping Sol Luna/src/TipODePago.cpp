#include <iostream>

using namespace std;

#include "TipODePago.h"

#include <cstring>


void TipoDePago::Cargar(){

    bool sectordisponible = true;
    system("cls");
    InfoCliente.Cargar();
    cout<<"Ingrese el ID Servicio(1- Carpa 2- Cabaña): ";
    cin>>IDServicio;
    cout<<endl;
    do{
    cout<<"Ingrese el Sector correcpondiente (A-C): ";
    cin>>IDSertor;
    if((strcmp(IDSector,"a")!=0) || (strcmp(IDSector,"A")!=0) || (strcmp(IDSector,"b")!=0) || (strcmp(IDSector,"B")!=0) || (strcmp(IDSector,"c")!=0) || (strcmp(IDSector,"C")!=0){
       cout<<"Opcion Incorrecta, ingrese nuevamente una opcion valida"<<endl;
       system("pause");

       else{sectordisponible = false;}

       }while(sectordisponible);///esto verifica que el sector ingresado sea el correcto de la letra "a" a la "c" verifica que sea tanto mayuscula como minuscula habilitados para poner un sector valido.

    FechaPago.Cargar();
    cout<<"Ingrese el Monto: ";
    cin>>Monto;
    cout<<endl;
    Estado = 1; ///reservado- Hay que ver como modificar de reservado a pagado si se pago la totalidad. En caso de pagar la totalidad, se debe poner 0 u otro numero, y en caso de cancelado, valor 2.
}
