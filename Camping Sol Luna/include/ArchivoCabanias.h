#pragma once

/*
class ArchivoCabanias{
private:
	char nombre[30];
public:
<<<<<<< Updated upstream
	ArchivoCabanias(const char *n="cabañas.dat"){strcpy(nombre,n);}
	bool grabarRegistro(Reservas obj);
	Reservas leerRegistro(int pos);
	int buscarRegistro(int dni);
	int contarRegistros();
	bool modificarRegistro(Reservas obj, int pos);
	bool listarRegistros();
	void verificarEstadoReserva(int dni);
=======


	ArchivoCabanias(const char *n="cabañas.dat"){strcpy(nombre,n);}///esto se define en el cpp
	Reservas leerRegistro(int pos);///Esta como leer archivos y vuelve un bool, se confunde con listar registros
	bool listarRegistros();///¿por que devuelve un bool? se llama leerArchivo en el diagrama de clases
	bool grabarRegistro(Reservas obj);///en el diagrama de clases se llama grabar en disco y recibe como parametro un entero IDServicio
	bool modificarRegistro(Reservas obj, int pos);///modificar registro es un nombre mas apropiado que modificarReservas. En el diagrama de clases recibe el IDServicio pero esta mal, este es lo correcto.
	int contarRegistros();///contar registro no debe recibir un parametro entero como pos. Cuenta todos los registros y devuelve la totalidad para hacer memoria dinamica.
	void verificarEstadoReserva(int dni);///en el diagrama recibe el parametro de numeroReserva y entero IDServicio. El entero IDServicio es innecesario por que al ser cabania ya se sabe cual idservicio es. ¿se va a realizar toda la operacion aca?
	int buscarRegistroDni(int dni);///devuelve el objeto de reservas por que no tiene una clase propia de cabania. Al tener el objeto
	void crearBackUpManual();
>>>>>>> Stashed changes
};
*/
