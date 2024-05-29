#include "ArchivoClientes.h"

using namespace std;

#include<iostream>
#include<cstdlib>
#include <cstring>

ArchivoClientes::ArchivoClientes(const char *aperturaArchivo)
{
    strcpy(AperturaArchivo, aperturaArchivo);
}



/*Cliente ArchivoClientes::leerArchivos(Cliente datos, int Cantidad){
	FILE *p;
	Cliente obj;
	p=fopen(nombre, "rb");
	obj.setDni(-5);
	if(p==NULL) return obj;
	fseek(p, pos*sizeof obj,0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}*/

void ArchivoCliente::LeerArchivos(Cliente Datos, int TotalRegistros){///ver como se carga en el objeto sin modificar

FILE *P=fopen(AperturaArchivo, "rb");

if(P==nullptr){
        system("cls");
cout<<"No se pudo abrir el archivo"<<endl;
system("pause");

}

fwrite(&Datos, sizeof(Cliente), TotalRegistros,P);

fclose(P);
return;

}

void ArchivoClientes::LeerArchivo(Cliente info, int TotalRegistros){

    system("cls");

    for(int x=0; x<TotalRegistros; x++){

        info[x].Mostrar();
    }

    system("pause");

}



bool ArchivoClientes::grabarRegistro(Cliente obj){
	FILE *p;
	p=fopen(AperturaArchivo, "ab");
	if(p==NULL) return false;
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}


bool ArchivoClientes::modificarRegistro(Cliente Datos, int pos){
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==NULL) return false;
	fseek(p, pos*sizeof obj,0);
	bool escribio=fwrite(&Datos, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}


int ArchivoClientes::ContarRegistros(){
	FILE *p;
	p=fopen(AperturaArchivo, "rb");
	if(p==NULL) return -1;
	fseek(p, 0,2);
	int tam=ftell(p);
	fclose(p);
	return tam/sizeof(Cliente);
}


/*void verificarEstadoReserva(int dni){
    ArchivoClientes.reg;
    Cliente aux;
    int pos=reg.buscarRegistro(dni);
    aux=reg.leerRegistro(pos);
    if(aux.getEstado()==false){
        cout<<"El cliente se encuentra borrado"<<endl;
    }else cout<<"El cliente se encuantra habilitado"<<endl;

}*/

Cliente ArchivoClientes::buscarRegistro(int DNI){
	FILE *p;
	Cliente Dato;
	Dato.setDNI(-1);
	p=fopen(AperturaArchivo, "rb");

	if(p==NULL) return Dato;
	while(fread(&Dato, sizeof Dato, 1, p)==1){
		if(obj.getDni()==num){
			fclose(p);
			return pos;
		}
		pos++;
	}
	fclose(p);
	return -2;
}*/
















