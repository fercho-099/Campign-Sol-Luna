#pragma once

void cargarReserva();
void modificarReserva();
void borrarReserva();

void cargarReserva(){
    Reservas obj;
    obj.Cargar();
}

void modificarReserva(){
    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;
    ///FALTA TERMINAR
}

void borrarReserva(){
    int dni;
    cout<<"Ingrese el Dni del cliente de la reserva que desea modificar: "<<endl;
    cin>>dni;
    ///FALTA TERMINAR
}
