#include "ArchivoClientes.h"
#include <cstring>

ArchivoClientes::ArchivoClientes(){
    const char *n="Clientes.dat";
    strcpy(nombre,n);
}

ArchivoClientes::ArchivoClientes(const char *_nombre){
    strcpy(nombre,_nombre);
}

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
		if(obj.getDNI()==dni){
			fclose(p);
			return pos;
		}
		pos++;
	}
	cout<<"El cliente no se encuentra en sistema"<<endl;
	fclose(p);
	return -2;
}

Cliente ArchivoClientes::leerRegistro(int pos){
	FILE *p;
	Cliente obj;
	p=fopen(nombre, "rb");
	obj.setDNI(-5);
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

bool ArchivoClientes::verificarEstadoCliente(int dni){
    ArchivoClientes reg;
    Cliente aux;
    int pos=reg.buscarRegistro(dni);
    if(pos>=0){
        aux=reg.leerRegistro(pos);
        if(aux.getEstado()==false){
            cout<<"El cliente se encuentra deshabilitado"<<endl;
            return false;
        }
        else{
            cout<<"El cliente se encuentra habilitado"<<endl;
            return true;
        }
    }

    return false;
}

bool ArchivoClientes::crearBackupClientes(){
    ArchivoClientes archiB("BackupClientes.dat");
    FILE *p;
	Cliente obj;
	Cliente aux;
	p=fopen("Clientes.dat", "rb");
	if(p==NULL) return false;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado()==true){
            aux=obj;
            archiB.grabarRegistro(aux);
        }
    }
	fclose(p);
	return true;
}
