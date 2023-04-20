#include <iostream>
#include "Grafica.h"

using namespace std;

int main() {
    Grafica grafica;
    grafica.AgregarNodo("Hola");
    grafica.AgregarNodo("bye");
    grafica.AgregarNodo("buenas");
    grafica.AgregarArista("Hola", "bye");
    grafica.AgregarNodo("adios");
    grafica.AgregarArista("adios", "Hola");
    grafica.AgregarArista("Hola","buenas");
    grafica.ImprimirNodos();
    cout << grafica.ObtenerNumNodos() << endl;
    return 0;
}
