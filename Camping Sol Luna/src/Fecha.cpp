#include <ctime>
#include <chrono>
#include "Fecha.h"
#include "Funciones.h"
#include "Reservas.h"

Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}

bool Fecha::MaximosDias(int Dia, int Mes, int Anio){


    dia = Dia;
    mes = Mes;
    anio = Anio;


    if (dia>=1 && (mes >=1 && mes<=12) && anio >=1 ){

        int dias[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (esBisiesto()) {
            dias[1]++;
        }
        if (dia > dias[mes - 1]) return false;

        else  return true;

    }

    else return false;

}

void Fecha::setDia(int d){
    dia=d;
}

void Fecha::setMes(int m){
    mes=m;
}

void Fecha::setAnio(int a){
    anio=a;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

//Alan
void Fecha::CargarActual(){
    time_t now = time(0); // Captura fecha y hora actual
    tm* localTime = localtime(&now); // Creamos el puntero localTime y lo referenciamos al objeto time
    // Accedemos a los atributos de la estructura tm
    dia = localTime->tm_mday;
    mes = localTime->tm_mon + 1; // Sumamos 1 porque los meses están indexados desde 0
    anio = localTime->tm_year + 1900; // Sumamos 1900 para obtener el año actual
}

//Alan
bool Fecha::ValidarFecha(int dia, int mes, int anio ){
 // Obtener la fecha actual
    auto fechaActual = std::chrono::system_clock::now();
    auto time_t_fechaActual = std::chrono::system_clock::to_time_t(fechaActual);
    tm* tm_fechaActual = std::localtime(&time_t_fechaActual);

    // Crear una estructura tm para la fecha ingresada por el usuario
    tm tm_fechaIngresada = {0};
    tm_fechaIngresada.tm_year = anio - 1900; // Años desde 1900
    tm_fechaIngresada.tm_mon = mes - 1;     // Meses desde enero (0-11)
    tm_fechaIngresada.tm_mday = dia + 1;        // Día del mes

    // Convertir ambas fechas a time_t
    auto time_t_fechaIngresada = std::mktime(&tm_fechaIngresada);
    auto time_t_actual = std::mktime(tm_fechaActual);

    // Comparar las fechas
    return time_t_fechaIngresada >= time_t_actual;
}

void Fecha::Cargar(){
    bool FechaValida = false;
    bool diasMaximos = false;
    do
    {
        cout<<"El formato de fecha es DD/MM/YYYY"<<endl;

        cout<<"Ingrese dia: ";
        dia = IngresoNumero();
        cout<<"Ingrese mes: ";
        mes = IngresoNumero();
        cout<<"Ingrese anio: ";
        anio = IngresoNumero();


        FechaValida = ValidarFecha(dia,mes,anio);///Valida la fecha ingresada sea igual o mayor a la actual.
        diasMaximos = this->MaximosDias(dia, mes, anio);///fer: el metodo valida que la fecha este dentro de los dias maximos del mes que se ingrese.

        if(!FechaValida)
        {
            cout << "La fecha ingresada es menor que la fecha actual, intente nuevamente" <<endl;
            system("pause");
            system("cls");
        }
        if(!diasMaximos){///fer: pregunta si la fecha ingresada

            std::cout<<"Fecha Ingresada Incorrecta, ingrese nuevamente una fecha valida"<<std::endl;
            system("pause");
            system("cls");
        }
    }
    while((!FechaValida) || (!diasMaximos));

    cout << "La fecha se ingreso correctamente." <<endl;
    system("pause");
    system("cls");
}

void Fecha::Mostrar(){
    cout<<dia<<":"<<mes<<":"<<anio<<endl;
}

bool Fecha::esBisiesto(){

return ((anio % 4 == 0 && anio % 100 !=0) || anio % 400 ==0);

}
