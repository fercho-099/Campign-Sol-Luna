<<<<<<< Updated upstream
#include<iostream>
#include<cstdlib>

using namespace std;

#include "ArchivoClientes.h"

bool ArchivoClientes::grabarRegistro(Cliente obj){
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}


bool ArchivoClientes::listarRegistros(){
	FILE *p;
	Cliente obj;
	p=fopen(nombre, "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
		obj.Mostrar();
		cout<<endl;
	}
	fclose(p);
	return true;
}

int ArchivoClientes::buscarRegistro(int dni){
	FILE *p;
	Cliente obj;
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

Cliente ArchivoClientes::leerRegistro(int pos){
	FILE *p;
	Cliente obj;
	p=fopen(nombre, "rb");
	obj.setDni(-5);
	if(p==NULL) return obj;
	fseek(p, pos*sizeof obj,0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}

bool ArchivoClientes::modificarRegistro(Cliente obj, int pos){
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==NULL) return false;
	fseek(p, pos*sizeof obj,0);
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivoClientes::contarRegistros(){
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==NULL) return -1;
	fseek(p, 0,2);
	int tam=ftell(p);
	fclose(p);
	return tam/sizeof(Cliente);
}

void verificarEstadoReserva(int dni){
    ArchivoClientes.reg;
    Cliente aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"El cliente se encuentra borrado"<<endl;
    }else cout<<"El cliente se encuantra habilitado"<<endl;
=======
#include <iostream>

using namespace std;
#include "ArchivoClientes.h"

ArchivoClientes::ArchivoClientes(const char *aperturaArchivo)
{
    strcpy(AperturaArchivo, aperturaArchivo);
}

void ArchivoClientes::LeerArchivo(Cliente info, int TotalRegistros){

    system("cls");

    for(int x=0; x<TotalRegistros; x++){

        info[x].Mostrar();
    }

    system("pause");

}

bool ArchivoClientes::GrabarEnDisco(Cliente obj){

    FILE *P=fopen(AperturaArchivo, "ab");
    if(P==nullptr)return false;

    bool valor = fwrite(&obj, sizeof (Cliente), 1, P);

    fclose(P);

return valor;

>>>>>>> Stashed changes
}
