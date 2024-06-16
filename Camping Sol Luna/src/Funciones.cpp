#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>
using namespace std;

#include "Funciones.h"

///Alan
///Valida que el ingreso sea un numero y que sea dntro de los rngos posibles
long long int IngresoNumero()
{
    long long int numeros;
    while (!(cin >> numeros)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout <<"Ingrese un caracter valido: ";

    }

    return numeros;
}

