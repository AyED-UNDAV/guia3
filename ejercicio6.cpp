#include <iostream>
using namespace std;

const int MAX = 200;

bool estaEnUnion(int arr[], int cantidadElementosUnion, int valor)
{
    bool estaElemento = false;
    for (int i = 0; i < cantidadElementosUnion && !estaElemento; i++)
    {
        if (arr[i] == valor)
            estaElemento = true;
    }
    return estaElemento;
}

void mezclarConResultado(int origen[], int tamVector, int unionResultante[], int &tamResultado)
{
    for (int idx = 0; idx < tamVector; idx++)
    {
        if (!estaEnUnion(unionResultante, tamResultado, origen[idx]))
        {
            unionResultante[tamResultado] = origen[idx];
            tamResultado++;
        }
    }
}

// Función principal que une dos vectores sin repetir
void unirVectores(int vec1[], int n, int vec2[], int m, int unionResultante[], int &tamResultado)
{
    tamResultado = 0;
    mezclarConResultado(vec1, n, unionResultante, tamResultado);
    mezclarConResultado(vec2, m, unionResultante, tamResultado);
}

int main()
{
    int tamVec1 = 6;
    int v1[] = {1, 2, 3, 4, 5, 8};
    int tamVec2 = 5;
    int v2[] = {3, 4, 5, 6, 7};

    int unionVec[tamVec1 + tamVec2];
    int tamUnionVec;

    unirVectores(v1, tamVec1, v2, tamVec2, unionVec, tamUnionVec);

    cout << "Vector unido sin repetidos: ";
    for (int i = 0; i < tamUnionVec; i++)
    {
        cout << unionVec[i] << " ";
    }
    cout << endl;

    return 0;
}
