#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
Ejercicio 6
a) Realizar una rutina que reciba dos arreglos de N y M números enteros respectivamente y
devuelva un arreglo resultante con la unión de ambos arreglos sin repetir valores.
b) Analizar el ejercicio a) pero considerando ambos arreglos ordenados previamente.
¿Modificaría la estrategia de solución? ¿Si es así, se obtiene un algoritmo más eficiente?
*/
const int LONGITUD_M = 5;
const int LONGITUD_N = 10;
const int LONGITUD_TOTAL = LONGITUD_M+LONGITUD_N;

// ASUMO QUE LOS ARREGLOS ORIGINALES NO TIENEN NUMEROS REPETIDOS Y LOS VALORES SON TODOS POSITIVOS

int arreSinOrdenM[LONGITUD_M] = {7,9,18,1,4};
int arreSinOrdenN[LONGITUD_N] = {7,5,9,8,4,6,3,1,2};

int arreConOrdenM[LONGITUD_M] = {1,5,6,7,9};
int arreConOrdenN[LONGITUD_N] = {1,2,3,4,5,6,7,8,9};

int arreResultante[LONGITUD_TOTAL] = {0,0,0,0,0,
                                     0,0,0,0,0,
                                     0,0,0,0,0};

void unirArreglosDesordenados(){

    for (int i = 0; i < LONGITUD_M; i++){
        arreResultante[i] = arreSinOrdenM[i];
    }

    int posNueva = 0;

    for (int posN = 0; posN < LONGITUD_N; posN++){
        bool repetido = false;
        for (int posResultante = 0; 
            posResultante < LONGITUD_TOTAL && arreResultante[posResultante] != 0 && !repetido; 
            posResultante++){
            if (arreSinOrdenN[posN] == arreResultante[posResultante]){
                repetido = true;
            }
        }
        
        if (!repetido){
            arreResultante[LONGITUD_M + posNueva] = arreSinOrdenN[posN];
            posNueva++;

        }
    }    
}

void unirArreglosOrdenados(){

    for (int i = 0; i < LONGITUD_TOTAL; i++)
    {
        arreResultante[i] = 0;
    }
    

    for (int i = 0; i < LONGITUD_M; i++){
        arreResultante[i] = arreConOrdenM[i];
    }

    int posNueva = 0;
    int posInicial = 0;

    for (int posN = 0; posN < LONGITUD_N; posN++){
        bool repetido = false;
        for (int posResultante = posInicial; 
            posResultante < LONGITUD_TOTAL && arreResultante[posResultante] != 0 && !repetido; 
            posResultante++){
            if (arreConOrdenN[posN] == arreResultante[posResultante]){
                repetido = true;
            }
        }
        
        if (!repetido){
            arreResultante[LONGITUD_M + posNueva] = arreConOrdenN[posN];
            posNueva++;

            if(arreConOrdenN[posN] > arreResultante[posNueva]){
                posInicial = posNueva;
            }

        }
    }    
}

void mostrarArregloResultante(){
    cout << "Valores de la union de los dos arreglos: ";
    for (int i = 0; i < LONGITUD_TOTAL && arreResultante[i] != 0; i++){
        cout << arreResultante[i] << " ";   
    }
    cout << "\n\n";
}

int main(){
    cout << "--------- ARREGLOS desORDENADOS -------------\n";
    unirArreglosDesordenados();
    mostrarArregloResultante();

    cout << "--------- ARREGLOS ORDENADOS -------------\n";
    unirArreglosOrdenados();
    mostrarArregloResultante();
    return EXIT_SUCCESS;
}