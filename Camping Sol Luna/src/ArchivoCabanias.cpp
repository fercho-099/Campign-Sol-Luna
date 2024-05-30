#include<iostream>
#include<cstdlib>

using namespace std;


#include "ArchivoCabanias.h"
/*
bool ArchivoCabanias::grabarRegistro(Reservas obj){

#include<cstdlib>
#include <cstring>

Reservas ArchivoCabanias::leerRegistro(int pos){///No esta definido en el diagrama
>>>>>>> Stashed changes
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}


bool ArchivoCabanias::listarRegistros(){
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
}

int ArchivoCabanias::buscarRegistro(int dni){
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

Reservas ArchivoCabanias::leerRegistro(int pos){
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



bool ArchivoCabanias::modificarRegistro(Reservas obj, int pos){
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==NULL) return false;
	fseek(p, pos*sizeof obj,0);
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivoCabanias::contarRegistros(){
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==NULL) return -1;
	fseek(p, 0,2);
	int tam=ftell(p);
	fclose(p);
	return tam/sizeof(Reservas);
}

void verificarEstadoReserva(int dni){
    ArchivoCabanias reg;
    Reservas aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"La reserva se encuentra deshabilitada"<<endl;
    }else cout<<"La reserva se encuentra habilitada"<<endl;
}
*/
