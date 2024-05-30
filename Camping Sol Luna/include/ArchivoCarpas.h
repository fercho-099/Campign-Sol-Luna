#pragma once

/*
class ArchivoCarpas{
private:
	char nombre[30];
public:
<<<<<<< Updated upstream
	ArchivoCarpas(const char *n="carpas.dat"){strcpy(nombre,n);}
	bool grabarRegistro(Reservas obj);
	Reservas leerRegistro(int pos);
	int buscarRegistro(int dni);
	int contarRegistros();
	bool modificarRegistro(Reservas obj, int pos);
	bool listarRegistros();
	void verificarEstadoReserva(int dni);
=======

    ArchivoCarpas(const char *n="carpas.dat"){strcpy(AperturaArchivo,n);}///este constructor no figura en el diagrama y se define su metodo en el .cpp
    bool LeerRegistros();///En el diagrama Figura como leerArchivos, devuelve en bool..¿para que? es void o retorna el registro leido. Modificar Nombre en el diagrama.
    bool grabarEnDisco(Reservas obj);///en el diagrama figura que se manda un entero y figura como grabar registro
	bool modificarRegistro(Reservas obj, int pos);///En el diagrama los atributos que toma es IDServicio y modificar reservas es propio de la clase archivo reservas. Corregir en el diagrama de clases el nombre, este esta bien.
	int contarRegistros();///Contar registros lo que hace es contar la totalidad de registros. Con esa cantidad devuelve un valor entero. 20 registros, esos 20 registros sirve para luego hacer memoria dinamica. En el diagrama se le manda el IDServicio y si le mandar el IDServicio que es unico para cada caso, siempre retornara 1 por que cuenta ese registro o 0 si el registro no existe.
	///Reservas leerRegistro(int pos);///Lo que hace este metodo es devolver el registro en una posicion especifica. Este metodo es contrario a memoria dinamica.
	///void verificarEstadoReserva(int dni);///Verificar estado reserva es metodo propio de la clase archivo reservas. El metodo tiene que devolver algo, sea un bool o un int. Si no, esta funcion puede que te informe solamente el estado o que se haga todo dentro de la clase, las modificaciones como alta o baja o cancelacion.
	bool VerificarEstadoReservas(int NumeroReservas, int IDServicio);///Este archivo maneja registros de servicios ya efectuados, no se debe preguntar si esta disponible o no. Lo que si se debe saber es si sigue de alta (ocupado) ese lugar o si esta de baja (el servicio termino- queda libre la carpa para su uso nuevamente)
	void crearBackUpManual();
	int buscarRegistro(int Dni);///En el diagrama de clases figura que devuelve Reservas. Pa que? si aca lo que hay que ver es buscar ese registro en carpas ya efectuados y a lo sumo devolver el objeto carpas o devolver el valor del servicio como alta o baja.
>>>>>>> Stashed changes
};
*/
