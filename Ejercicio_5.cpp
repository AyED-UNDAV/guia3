#include <iostream>

using namespace std;

/*
Dado un curso de N estudiantes, por cada estudiante se posse un registro que contiene el número de legajo,
el nombre y si el estudiante es extranjero.
a) realizar una función que retorne el nombre del estudiante relacionado. Si no
encuentra al estudiante por su legajo debe retornar un mensaje indicando que no lo
encontró.
b) se necesita un arreglo con estudiantes extranjeros, pensar la mejor manera de
hacerlo
*/
struct Estudiante {
    int legajo;
    char nombre[50];
    bool esEstudianteExtranjero;
};    

Estudiante curso[10] = {
                                {1, "est_1", false},
                                {2, "est_2", false},
                                {3, "est_3", false},
                                {4, "est_4", false},
                                {5, "est_5", false},
                                {6, "est_6", false},
                                {7, "est_7", false},
                                {8, "est_8", false},
                                {9, "est_9", false},
                                {10, "est_10", false},
                            };

string buscarNombre(Estudiante curso[], int legajoBuscado){

    string nombreEncontrado = "Ese nombre no se encuentra";
    for (int i = 0; i < 10 && nombreEncontrado == "Ese nombre no se encuentra"; i++)
    {
        if(legajoBuscado ==  curso[i].legajo){
            nombreEncontrado = curso[i].nombre;
        }
    }
    return nombreEncontrado;
}

int main(){
    int legajo = 5;
    cout << "El legajo " << legajo << " corresponde al nombre: " << buscarNombre(curso, legajo);
    return EXIT_SUCCESS;
}