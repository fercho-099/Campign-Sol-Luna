#ifndef FUNCION_GENERALES_H_INCLUDED
#define FUNCION_GENERALES_H_INCLUDED

//DECLARACION DE METODOS GLOBALES
void Reservas();
void Clientes();
void Informes();
<<<<<<< Updated upstream
void FechaActual(Fecha obj);
=======
///void FechaActual(Fecha);
>>>>>>> Stashed changes

//DEFINICION DE METODOS GLOBALES
/*
void Reservas(){

    system("cls");
    bool Ejecutar = true;
    int Opcion;
    ///incluir el archivo.h de la clase reservas y luego definir aca la variable del tipo reserva

    do{
            system("cls");
    cout<<"-----SECCION RESERVAS-----"<<endl;
    cout<<"1 - Alta Reservas "<<endl;
    cout<<"2 - Modificar Reservas "<<endl;
    cout<<"3 - Cancelar Reservas "<<endl;
    cout<<"0 - Volver al Menu Principal "<<endl;
    cout<<endl;
    cout<<"Ingrese una Opcion: ";
    cin>>Opcion;

    switch(Opcion){

    case 1:

            ///VariableReservas.Cargar();

            break;

    case 2:

            ///VariableReservas.Modificar();

            break;

    case 3:

            ///VariableReservas.Cancelar();

            break;

    case 0:

            Ejecutar = false;

            break;

    default:

        cout<<"Opcion invalida, seleccione una opcion valida"<<endl;
        system("pause");
    }

    }while(Ejecutar);

return;
}

void Clientes(){

    system("cls");
    bool Ejecutar = true;
    int Opcion;
    ///incluir el archivo.h de la clase Clientes y luego definir aca la variable del tipo Cliente

    do{
            system("cls");
    cout<<"-----SECCION CLIENTES-----"<<endl;
    cout<<"1 - Alta Cliente "<<endl;///No estoy seguro de este metodo
    cout<<"2 - Modificar Cliente "<<endl;/// direccion, dni, telefono si es que hay
    cout<<"3 - Baja Cliente "<<endl;/// baja logica ¿con backup? cual seria la finalidad?
    cout<<"0 - Volver al Menu Principal "<<endl;
    cout<<endl;
    cout<<"Ingrese una Opcion: ";
    cin>>Opcion;

    switch(Opcion){

    case 1:

            ///VariableCliente.Cargar();

            break;

    case 2:

            ///VariableCliente.Modificar();

            break;

    case 3:

            ///VariableCliente.Cancelar();

            break;

    case 0:

            Ejecutar = false;

            break;

    default:

        cout<<"Opcion invalida, seleccione una opcion valida"<<endl;
        system("pause");
    }

    }while(Ejecutar);

return;
}

void Informes(){

    system("cls");
    bool Ejecutar = true;
    int Opcion;
    ///Esta funcion no interactua con una clase, si no con metodos globales donde dentro estan Incluidos los objetos de distintas clases

    do{
            system("cls");
    cout<<"-----SECCION INFORMES-----"<<endl;
    cout<<"1 - Informe Mensual "<<endl;
    cout<<"2 -  "<<endl;/// se podria incluir otra opcion
    cout<<"3 -  "<<endl;/// se podria incluir otra opcion
    cout<<"0 - Volver al Menu Principal "<<endl;
    cout<<endl;
    cout<<"Ingrese una Opcion: ";
    cin>>Opcion;

    switch(Opcion){

    case 1:

            ///Puede que el objeto de cabaña individual pida su informe

            break;

    case 2:

            ///Puede que el objeto de carpas pida un informe mensual

            break;

    case 3:

            /// sin definir

            break;

    case 0:

            Ejecutar = false;

            break;

    default:

        cout<<"Opcion invalida, seleccione una opcion valida"<<endl;
        system("pause");
    }

    }while(Ejecutar);

return;
}
*/

#endif // FUNCION_GENERALES_H_INCLUDED
