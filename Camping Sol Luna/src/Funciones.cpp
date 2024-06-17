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

void CargarCadenas(char *vec, int tam) {
    string input;
    bool firstAttempt = true;

    while (true) {
        getline(cin, input);

        // Permitir la primera entrada vac�a
        if (firstAttempt) {
            firstAttempt = false;
            if (input.empty()) {
                continue; // Pedir de nuevo si la primera entrada esta vac�a
            }
        }

        // Verificar si la entrada esta vac�a
        if (input.empty()) {
            cerr <<  "linea vacia. Intentelo de nuevo." <<endl;
            continue;
        }

        // Verificar cada car�cter de la entrada
        bool valid = true;
        for (char c : input) {
            if (!isalpha(c)) {
                cerr << "La cadena contiene caracteres no validos. Intentelo de nuevo." <<endl;
                valid = false;
                break;
            }
        }

        if (valid) {
            // Copiar la cadena v�lida a la variable proporcionada
            strncpy(vec, input.c_str(), tam - 1);
            vec[tam - 1] = '\0'; // Asegurar el car�cter nulo al final
            break;
        }
    }
}
