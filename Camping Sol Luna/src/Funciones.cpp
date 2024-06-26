#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>
using namespace std;

#include "Funciones.h"

long long int IngresoNumero()
{
   long long int numero;
    while (true) {
        cin >> numero;

        // Verificar si la entrada fall�
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar hasta el siguiente newline
            cout << "Ingrese un caracter valido: ";
        } else {
            // Verificar si hay caracteres adicionales en el buffer
            char ch;
            if (cin.get(ch) && !isspace(ch)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingrese un caracter valido: ";
            } else {
                cin.unget(); // Devolver el car�cter v�lido al buffer
                break; // Entrada v�lida
            }
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
    return numero;
}

void CargarCadenas(char *vec, int tam) {
    string entrada;
    bool primerIntento = true;

    while (true) {
        getline(cin, entrada);

        // Permitir la primera entrada vac�a
        if (primerIntento) {
            primerIntento = false;
            if (entrada.empty()) {
                continue; // Pedir de nuevo si la primera entrada esta vac�a
            }
        }

        // Verificar si la entrada esta vac�a
        if (entrada.empty()) {
            cout <<  "linea vacia, vuelva a ingresar el dato:";
            continue;
        }

        // Verificar cada car�cter de la entrada
        bool valido = true;
        for (char c : entrada) {
            if (!isalpha(c)) {
                cout << "La informacion contiene caracteres no validos, vuelva a ingresar el dato: ";
                valido = false;
                break;
            }
        }

        if (valido) {
            // Copiar la cadena v�lida a la variable proporcionada
            strncpy(vec, entrada.c_str(), tam - 1);
            vec[tam - 1] = '\0'; // Asegurar el car�cter nulo al final
            break;
        }
    }
}
