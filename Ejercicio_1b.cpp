#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
Ejercicio 1: 
Una empresa registra en un vector de veinte posiciones las ventas totales que realizo en cada día hábil del mes:
a) Realizar una rutina que calcule el promedio de todas las ventas.
b) Realizar una rutina que obtenga la venta máxima y el día en que fue realizada. Suponer varios máximos.
c) Realizar una rutina que obtenga los días en que fueron realizadas las ventas de menor y de mayor valor.
*/

float promedioVentas(float ventas[]){
    float promedio = 0;
    for (int i = 0; i < 20; i++)
    {
        promedio += ventas[i];
    }
    
    return promedio / 20;
}

void ventaMaximaYDias(float ventas[]){
    float max = 0;

    for (int i = 0; i < 20; i++){
        if (max < ventas[i]){
            max = ventas[i];
        }    
    }
    
    cout << "El valor de la venta maxima es: " << max << " y fue realizada el dia: ";

    for (int i = 0; i < 20; i++){
        if(max == ventas[i])
            cout << i << " ";
    }
}

void diaVentaMinYMax(int &diaMinimo, int &diaMaximo, float ventas[]){
    float ventaMin, ventaMax = 0;

    for (int i = 0; i < 20; i++){
        if(ventaMin > ventas[i]){
            ventaMin = ventas[i];
            diaMinimo = i;
        }

        if (ventaMax < ventas[i]){
            ventaMax = ventas[i];
            diaMaximo = i;
        }
    }
}

int main(){
    int diaMin, diaMax = 0;

    float ventasDiarias[20] = {11.1, 21.1, 31.1, 41.1, 51.1,
                            12.1, 22.1, 32.1, 42.1, 52.1,
                            13.1, 23.1, 33.1, 43.1, 53.1,
                            14.1, 24.1, 34.1, 44.1, 54.1
                        };
    
    /* Punto a)*/
    cout << "El promedio de las ventas del mes es: " << promedioVentas(ventasDiarias);
    cout << "\n" << "\n";

    /* Punto b)*/
    ventaMaximaYDias(ventasDiarias);
    cout << "\n" << "\n";

    /* Punto c)*/
    diaVentaMinYMax(diaMin, diaMax, ventasDiarias);
    cout << "El dia que se produjo la venta de menor valor es: " << diaMin << "\n";
    cout << "El dia que se produjo la venta de mayor valor es: " << diaMax << "\n";

    return EXIT_SUCCESS;
}