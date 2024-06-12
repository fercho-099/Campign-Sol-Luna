#include <iostream>
#include <limits>
#include <string>
#include <sstream>
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

int Prueba() {
    std::string entrada;
    int numero;
    char caracter;

    std::istringstream stream(entrada); // Crea un flujo de entrada desde la cadena
    if (stream >> numero >> caracter) { // Intenta extraer un número y un carácter
        // Verifica si el carácter es una letra
        if (std::isalpha(caracter)) {
            std::cout << "Entrada invalida. Por favor ingrese solo numeros." << std::endl;
        } else {
            std::cout << "Numero ingresado: " << numero << std::endl;
            std::cout << "Caracter ingresado: " << caracter << std::endl;
        }
    } else {
        std::cout << "Entrada invalida. Por favor ingrese un numero seguido de un caracter." << std::endl;
    }

    return 0;
}


