#include <iostream>

using namespace std;

/*
Ejercicio 1: 
Dado un arreglo de 20 elementos enteros:
a) Realizar una rutina que calcule el promedio de todos sus valores.
b) Realizar una rutina que obtenga el máximo de todos sus valores.
Suponer único máximo.
c) Realizar una rutina que obtenga las posiciones donde están ubicados
el máximo y el mínimo valor.
d) Realizar una rutina que y muestre por pantalla el valor máximo del
arreglo y en qué posiciones se encuentra
*/

float promedioValores(int val[]){
    float promedio = 0;
    for (int i = 0; i < 20; i++)
        promedio += val[i];
    
    return promedio / 20;
}

int maximoValor(int val[]){
    int max = 0;

    for (int i = 0; i < 20; i++){
        if (max < val[i]){
            max = val[i];
        }    
    }

    return max;
}

void posicionMinYMax(int &posMinimo, int &posMaximo, int val[]){
    int valMin, valMax = 0;

    for (int i = 0; i < 20; i++){
        if(valMin > val[i]){
            valMin = val[i];
            posMinimo = i;
        }

        if (valMax < val[i]){
            valMax = val[i];
            posMaximo = i;
        }
    }
}

void valorMaximoYPosiciones(int val[]){
    int max = maximoValor(val);
    
    cout << "El valor maximo es: " << max << " y se encuentra en la posicion: ";

    for (int i = 0; i < 20; i++){
        if(max == val[i])
            cout << i << " ";
    }
}

int main(){
    int posMin, posMax = 0;

    int valores[20] = {11, 21, 31, 41, 51,
                            12, 22, 32, 42, 52,
                            13, 23, 33, 43, 53,
                            14, 24, 34, 44, 54
                        };
    
    /* Punto a)*/
    cout << "El promedio de todos los valores es: " << promedioValores(valores);
    cout << "\n" << "\n";
    
    /* Punto b)*/
    cout << "El valor maximo es: " << maximoValor(valores);
    cout << "\n" << "\n";

    /* Punto c)*/
    posicionMinYMax(posMin, posMax, valores);
    cout << "La posicion en que se encuentra el valor minimo es: " << posMin << "\n";
    cout << "La posicion en que se encuentra el valor maximo es: " << posMax << "\n";
    cout << "\n" << "\n";

    /* Punto d)*/
    valorMaximoYPosiciones(valores);
    cout << "\n" << "\n";

    return EXIT_SUCCESS;
}