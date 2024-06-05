#include<iostream>
#include<cstdlib>

using namespace std;

#include "Archivo Reservas.h"


bool Archivo Reservas::grabarRegistro(Reservas obj){
	FILE *p;
	p=fopen(AperturaArchivo, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

bool Archivo Reservas::grabarRegistro(Reservas obj, int Pos){

    FILE *p;
    p=fopen(AperturaArchivo, "rb+");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof (Reservas)*pos, 1, p);
    fclose(p);
    return escribio;

}

Reservas ArchivoReservas::leerRegistro(int pos){
	FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	obj.setDni(-5);
	if(p==NULL) return obj;
	fseek(p, pos*sizeof obj,0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}

void ArchivoReservas::LeerRegistrosTotales(Reservas &obj, int TotalRegistros){

    FILE *P=fopen("Reservas.dat", "rb");
    if(P==nullptr){
        std::cout<<"No se pudo abrir el registro"<<std::endl;
        system("pause");
        return;
    }

    fread(&obj, sizeof (Reservas), TotalRegistros, P);

    fclose(P);
    return;


}

int ArchivoReservas::buscarRegistro(int dni){
	FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	int pos=0;
	if(p==NULL) return -1;
	while(fread(&obj, sizeof obj, 1, p)==1){
		if(obj.getDni()==num){
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -2;
}

void ArchivosReservas::BuscarRegistros(Reservas &Datos, int TotalRegistros, int Dni){

    int opcion, pos=0;
    Reservas aux;
    ArchivoReservas obj;
    for(int x=0; x<TotalRegistros; x++){

        if(Datos[x].getTipoDePago().getCliente().getDNI() == Dni){
                pos++;
            Datos[x].Mostrar();
            std::cout<<"¿Desea Modificar este registro? 1-si 2-no: ";
            std::cin>>opcion;
            if(opcion==1){

                aux = Datos[x];///ver si se copia correctamente
                x=TotalRegistros;
            }
        }
    }

    if(obj.ModificarRegistros(aux)){

            if(obj.grabarRegistro(aux, pos){
        std::cout<<"Se modifico correctamente"<<std::endl;
        system("pause");
            }
    }

    else{
        std::cout<<"No se realizaron cambios en la reserva"<<std::endl;
        system("pause");
    }

    }
}

int ArchivoReservas::contarRegistros(){
	FILE *p;
	p=fopen(AperturaArchivo, "rb");
	if(p==NULL) return -1;
	fseek(p, 0,2);
	int tam=ftell(p);
	fclose(p);
	return tam/sizeof(Reservas);
}

bool ArchivoReservas::modificarRegistro(Reservas obj, int pos){
	FILE *p;
	p=fopen(AperturaArchivo, "rb+");
	if(p==NULL) return false;
	fseek(p, pos*sizeof obj,0);
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

bool ModificarRegistros(Reservas &obj){

    system("cls");
    int opc;
    obj.Mostrar();
    Fecha dato;


    std::cout<<"¿Que desea Modificar?"<<std::endl;
    std::cout<<"1- Fecha principio"<<std::endl;
    std::cout<<"2- Fecha de final Estadia"<<std::endl;
    std::cout<<"3- Cancelar Reserva"<<std::endl;
    std::cout<<"0- Cancelar Modificacion"<<std::endl;
    switch(opc){

    system("cls");

    case 1:

        dato.Cargar();
        ///funcion que verifica disponibilidad mediante if
        obj.setFechaDesde(dato);
        return true;
        break;


    case 2:

        dato.Cargar();
        ///funcion que verifica disponibilidad mediante if
        obj.setFechaHasta(dato);
        return true;
        break;

    case 3:

        obj.setEstado(2);
        return true;
        break;


    case 0:

        return false;
        break;

    default:
            return false;
        }


}

bool ArchivoReservas::listarRegistros(){
	FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.Mostrar();
		cout<<endl;
	}
	fclose(p);
	return true;
}

void verificarEstadoReserva(int dni){
    ArchivoReservas reg;
    Reservas aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"La reserva se encuentra deshabilitada"<<endl;
    }else cout<<"La reserva se encuentra habilitada"<<endl;
}

