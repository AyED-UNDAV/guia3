#include <iostream>

using namespace std;

/*
Ejercicio 3
Un estacionamiento posee N cocheras en donde cada vehículo estacionado se identifica por
sus tres dígitos.
Realizar una función que encuentre la cochera en que se encuentra un vehículo. Si el
vehículo no se encuentra debe retornar -1.
*/

const int TOPE = 20;

int encuentraVehiculo(int vector[], int valor){
    int encontrado = -1;
    for (int i = 0; i < TOPE && -1 == encontrado; i++)
    {
        if(vector[i] == valor){
            encontrado = i;
        }
    }

    return encontrado;
}

int main(){
    int valores[20] = {11, 21, 31, 41, 51,
        12, 22, 32, 42, 52,
        13, 23, 33, 43, 53,
        14, 24, 34, 44, 54
    };

    int val = 533;

    cout << "El vehiculo con patente " << val;

    if(encuentraVehiculo(valores, val) != -1)
        cout << " se encuentra en la posicion " << encuentraVehiculo(valores, val);
    else
        cout << " no se encuentra en el estacionamiento";

    return EXIT_SUCCESS;
}