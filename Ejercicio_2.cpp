#include <iostream>

using namespace std;

/*
Ejercicio 2:
Escribir una función que reciba un arreglo de n elementos de tipo entero y un
valor entero y devuelva la cantidad de veces que se repite ese valor en el
arreglo
*/

const int TOPE = 20;

int cantRepeticiones(int vector[], int valor){
    int repe = 0;
    for (int i = 0; i < TOPE; i++)
    {
        if(vector[i] == valor){
            repe++;
        }
    }

    return repe;
}

int main(){
    int valores[20] = {11, 21, 31, 41, 53,
        12, 22, 32, 42, 52,
        13, 23, 33, 43, 53,
        14, 24, 34, 44, 54
    };

    int val = 53;

    cout << "Cantidad de veces que se repite " << val << ": " << cantRepeticiones(valores, val);

    return EXIT_SUCCESS;
}