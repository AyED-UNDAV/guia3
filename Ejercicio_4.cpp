#include <iostream>
#include <string.h>

using namespace std;

/*
Ejercicio 4
Realizar una función que reciba un arreglo de 16 elementos de tipo carácter y lo devuelva
invertido sobre el mismo arreglo sin utilizar un arreglo auxiliar. (El arreglo debe tener una
posición más para el carácter NULL – ‘\0’).
*/

const int TOPE = 17;

void invierteArreglo(char vector[]){
    char aux = ' ';
    int longitud = strlen(vector) - 1;

    for (int pos = 0; pos < (longitud + 1)/2; pos++)
    {
        aux = vector[pos];
        vector[pos] = vector[longitud - pos];
        vector[longitud - pos] = aux;
    }
    vector[longitud + 1]='\0';
    //cout << "\n\n" << vector << "\n\n";
}

int main(){
    char vectorCaracteres[TOPE] = "Holas que tales";

    cout << "El arreglo original es: " << vectorCaracteres << "\n";
    invierteArreglo(vectorCaracteres);
    cout << "El arreglo con el orden invertido es: " << vectorCaracteres;

    return EXIT_SUCCESS;
}