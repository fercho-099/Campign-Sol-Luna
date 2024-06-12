#include <iostream>
#include <limits>
using namespace std;

#include "Funciones.h"

int IngresoNumero()
{
    int numeros;
    while (!(cin >> numeros)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un caracter valido: ";

    }

    return numeros;
}


