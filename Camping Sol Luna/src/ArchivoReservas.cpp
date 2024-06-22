#include "../include/ArchivoReservas.h"
#include<iostream>

#include<cstdlib>

using namespace std;


ArchivoReservas::ArchivoReservas(){

    strcpy(AperturaArchivo,"Reservas.dat");
    }

ArchivoReservas::ArchivoReservas(const char *n){

    strcpy(AperturaArchivo,n);
}

void ArchivoReservas::setAperturaArchivo(const char *n){

    strcpy(AperturaArchivo, n);

}

bool ArchivoReservas::GrabarRegistro(Reservas obj){
	FILE *p;
	p=fopen(AperturaArchivo, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

bool ArchivoReservas::GrabarRegistro(Reservas obj, int TotalRegistros){
	FILE *p;
	p=fopen(AperturaArchivo, "ab");
	if(p==NULL) return false;

	bool escribio=fwrite(&obj, sizeof obj, TotalRegistros, p);
	fclose(p);
	return escribio;
}

bool ArchivoReservas::grabarRegistros(Reservas obj, int pos){

    bool retorno;
    FILE *P=fopen(AperturaArchivo,"rb+");
    if(P==nullptr){

        retorno = false;
        return retorno;
    }
    fseek(P, sizeof obj* pos,0);
    retorno = fwrite(&obj, sizeof (Reservas), 1, P);///fwrite(&obj, sizeof (Reservas)*pos, 1, P)
    fclose(P);
    return retorno;

}

void ArchivoReservas :: grabarRegistroNuevo(Reservas obj){

    FILE *p;
	p=fopen(AperturaArchivo, "wb");
	if(p==NULL) return;
	fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return;
}

Reservas ArchivoReservas::LeerRegistro(int pos){
	FILE *p;
	Reservas obj;
	obj.setEstado(-4);
	p=fopen(AperturaArchivo, "rb");
	//obj.setTipoDePago()
	if(p==NULL) return obj;
	fseek(p, pos*sizeof obj,0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}

Reservas ArchivoReservas::LeerRegistrosDinamicos(Reservas *DatoReserva, int pos){///probando dinamico

Reservas aux;

        aux = DatoReserva[pos];

        return aux;


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

int ArchivoReservas::BuscarRegistro(int dni){///Se Usa
	FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	int pos=0;
	if(p==NULL) return -1;
	while(fread(&obj, sizeof obj, 1, p)==1){
		if(obj.getTipoDePago().getCliente().getDNI()==dni){
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -2;
}

int ArchivoReservas::BuscarRegistro(Reservas *DatoReserva, int TotalRegistros, int dni){///probando dinamico

    int pos, Opcion;

    for(int x=0; x<TotalRegistros; x++){

        pos=x;

        if(DatoReserva[x].getTipoDePago().getCliente().getDNI() == dni){

            system("cls");
            DatoReserva[x].Mostrar();
            std::cout<<"----------"<<std::endl;
            std::cout<<"Desea Modificar O borrar Este registro? 1 - SI / 2 - NO: ";
            std::cin>>Opcion;
            if(Opcion == 1){

                return pos;
            }

        }
    }
    system("cls");
    std::cout<<"El Registro con el dni ingresado no existe"<<std::endl;
    system("pause>null");
    return -1;
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

void ArchivoReservas::ModificarRegistros(Reservas *aux)
{

    std::cout<<"----------"<<std::endl;
    int OpcSwitch;
    Fecha fecha;
    int dia, mes, anio;
    bool ciclo=true;

    do
    {

        std::cout<<"Digite la opcion correcta"<<std::endl;
        std::cout<<"1 - Si desea cancelar la reserva"<<std::endl;
        std::cout<<"2 - Si desea cambiar la fecha de entrada"<<std::endl;
        std::cout<<"3 - Si desea cambiar la fecha de salida"<<std::endl;
        std::cout<<"4 - Volver Menu anterior / Cancelar Cambios"<<std::endl;
        std::cout<<"Ingrese una opcion: ";
        std::cin>>OpcSwitch;
        system("cls");
        switch(OpcSwitch)
        {

        case 1:
            aux->setEstado(2);///iria el .
            ciclo = false;
            break;

        case 2:
            std::cout<<"Ingrese Dia de Entrada: ";
            std::cin>>dia;
            std::cout<<std::endl;
            std::cout<<"Ingrese Mes de Entrada: ";
            std::cin>>mes;
            std::cout<<std::endl;
            std::cout<<"Ingrese anio de Entrada: ";
            std::cin>>anio;
            fecha.setAnio(anio);
            fecha.setMes(mes);
            fecha.setDia(dia);
            aux->setFechaDesde(fecha);
            ciclo = false;
            break;

        case 3:

            std::cout<<"Ingrese Dia de Salida: ";
            std::cin>>dia;
            std::cout<<std::endl;
            std::cout<<"Ingrese Mes de Salida: ";
            std::cin>>mes;
            std::cout<<std::endl;
            std::cout<<"Ingrese anio de Salida: ";
            std::cin>>anio;
            fecha.setAnio(anio);
            fecha.setMes(mes);
            fecha.setDia(dia);
            aux->setFechaHasta(fecha);
            ciclo = false;

            break;

        case 4:
            ciclo = false;
            break;

        default:

            std::cout<<"Opcion Incorrecta"<<std::endl;
            system("pause");
        }
    }
    while(ciclo);
}

bool ArchivoReservas::CrearBackUpManual(){


    int TotalRegistros = this->contarRegistros();
    if(TotalRegistros<=0)return false;

    Reservas *RegistrosReservas, obj;
    RegistrosReservas = new Reservas[TotalRegistros];
    this->LeerRegistrosTotales(*RegistrosReservas, TotalRegistros);


    ArchivoReservas backup("Reservas.bak");

    for(int x=0; x<TotalRegistros; x++){

    obj = RegistrosReservas[x];
    backup.GrabarRegistro(obj);

    }
    return true;

}

void ArchivoReservas::ListarRegistros(){
    system("cls");
	FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	if(p==NULL){

        std::cout<<"No se pudo abrir el archivo / No existe el archivo"<<std::endl;
        system("pause");
        return;
	}
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.Mostrar();
		cout<<"-----------"<<endl;
	}
	fclose(p);
	system("pause");
	return;
}

/**void verificarEstadoReserva(int dni){ PREGUNTAR A LEO SI PUEDO BORRAR YA QUE SE TRABAJA CON MEMORIA DINAMICA
    ArchivoReservas reg;
    Reservas aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"La reserva se encuentra deshabilitada"<<endl;
    }
    else cout<<"La reserva se encuentra habilitada"<<endl;
}*/

void ArchivoReservas::verificarEstadoReserva(Reservas *DatosReservas, int TotalRegistros, int dni){

    for(int x=0; x<TotalRegistros; x++){

        if(DatosReservas[x].getTipoDePago().getCliente().getDNI() == dni){

            if(DatosReservas[x].getEstado() == 1){

                DatosReservas[x].Mostrar();
                std::cout<<std::endl;
                std::cout<<"La reserva se encuentra activa"<<std::endl;
                std::cout<<std::endl;
                system("pause");
            }

            else if(DatosReservas[x].getEstado() == 2){

                DatosReservas[x].Mostrar();
                std::cout<<std::endl;
                std::cout<<"La reserva se encuentra cancelada"<<std::endl;
                std::cout<<std::endl;
                system("pause");
            }

            else{

                DatosReservas[x].Mostrar();
                std::cout<<std::endl;
                std::cout<<"La reserva se encuentra Gestionada. Verificar el archivo de servicio contratado para mas informacion"<<std::endl;
                std::cout<<std::endl;
                system("pause");
            }
        }
    }
}

///Leo
void ArchivoReservas::mostrarCabaniasDisponibles(){
    FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	if(p==NULL) return;
	int cant=10;
	cout<<"Cabanias disponibles:"<<endl;
	for(int i=0;i<cant;i++){
        int contador=0;
        while(fread(&obj, sizeof obj, 1, p)==1){
            if(obj.getTipoDePago().getVecCabania()[i]==false){
                contador++;
            }
        }
        if(contador==0){
            cout<<i+1<<endl;
        }
    }
	fclose(p);
}

void ArchivoReservas::mostrarCarpasDisponibles(){
    FILE *p;
	Reservas obj;
	p=fopen(AperturaArchivo, "rb");
	if(p==NULL) return;
	int cant=20;
	cout<<"Carpas disponibles:"<<endl;
	for(int i=0;i<cant;i++){
        int contador=0;
        while(fread(&obj, sizeof obj, 1, p)==1){
            if(obj.getTipoDePago().getVecCarpa()[i]==false){
                contador++;
            }
        }
        if(contador==0){
            cout<<i+1<<endl;
        }
    }
	fclose(p);
}
