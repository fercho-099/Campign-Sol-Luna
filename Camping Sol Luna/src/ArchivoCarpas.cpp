#include<iostream>
#include<cstdlib>

using namespace std;

#include "ArchivoCarpas.h"

/*
bool ArchivoCarpas::grabarRegistro(Reservas obj){


bool ArchivoCarpas::leerRegistro(int pos){///¿Por que devuelve Reservas? si ya es un registro de una carpa ya efectuado sea de alta-todavia sigue el tipo usando la carpa que alquilo- o de baja- el tipo ya dejo el alquiler-.

>>>>>>> Stashed changes
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}


bool ArchivoCarpas::listarRegistros(){
	FILE *p;
	Reservas obj;
	p=fopen(nombre, "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.Mostrar();
		cout<<endl;
	}
	fclose(p);
	return true;
<<<<<<< Updated upstream
=======
}

bool ArchivoCarpas::modificarRegistro(Reservas obj, int pos){
	FILE *p;
	p=fopen(AperturaArchivo, "rb+");///nombre no va, el atributo se definio como AperturaArchivo
	if(p==NULL) return false;
	fseek(p, pos*sizeof (Reservas),0);
	bool escribio=fwrite(&obj, sizeof (Reservas), 1, p);///hay que ver si es sizeof reservas o obj
	fclose(p);
	return escribio;
>>>>>>> Stashed changes
}

int ArchivoCarpas::buscarRegistro(int dni){
	FILE *p;
	Reservas obj;
	p=fopen(nombre, "rb");
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
<<<<<<< Updated upstream

Reservas ArchivoCarpas::leerRegistro(int pos){
	FILE *p;
	Reservas obj;
	p=fopen(nombre, "rb");
	obj.setDni(-5);
	if(p==NULL) return obj;
	fseek(p, pos*sizeof obj,0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}
=======

bool ArchivoCarpas::modificarRegistro(Reservas obj, int pos){
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==NULL) return false;
	fseek(p, pos*sizeof obj,0);
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivoCarpas::contarRegistros(){
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==NULL) return -1;
	fseek(p, 0,2);
	int tam=ftell(p);
	fclose(p);
	return tam/sizeof(Reservas);
}

void verificarEstadoReserva(int dni){
    ArchivoCarpas reg;
    Reservas aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"La reserva se encuentra deshabilitada"<<endl;
    }else cout<<"La reserva se encuentra habilitada"<<endl;
}
*/
