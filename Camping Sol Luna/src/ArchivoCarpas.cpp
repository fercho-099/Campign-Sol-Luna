#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

#include "ArchivoCarpas.h"

ArchivoCarpas::ArchivoCarpas(){
    const char *n="Carpas.dat";
    strcpy(nombre,n);
}

ArchivoCarpas::ArchivoCarpas(const char *_nombre){
    strcpy(nombre,_nombre);
}

bool ArchivoCarpas::grabarRegistro(Reservas obj){
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

Reservas ArchivoCarpas::leerRegistro(int pos){
	FILE *p;
	Reservas obj;
	p=fopen(nombre, "rb");
	if(p==NULL) return obj;
	fseek(p, pos*sizeof obj,0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
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
}

int ArchivoCarpas::buscarRegistro(int dni){
	FILE *p;
	Reservas obj;
	p=fopen(nombre, "rb");
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

void ArchivoCarpas::verificarEstadoReserva(int dni){
    ArchivoCarpas reg;
    Reservas aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"La reserva se encuentra deshabilitada"<<endl;
    }else cout<<"La reserva se encuentra habilitada"<<endl;
}

bool ArchivoCarpas::crearBackupCarpas(){
    ArchivoCarpas archiB("BackupCarpas.dat");
    FILE *p;
	Reservas obj;
	Reservas aux;
	p=fopen("Carpas.dat", "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		aux=obj;
		archiB.grabarRegistro(aux);
        }
	fclose(p);
	return true;
}
