#include <iostream>
#include "Grafica.h"

using namespace std;

int main() {
    Grafica grafica;
    grafica.AgregarNodo("hola");
    grafica.AgregarNodo("bye");
    grafica.AgregarNodo("buenas");
    grafica.AgregarArista("hola", "bye");
    grafica.AgregarNodo("adios");
    grafica.AgregarArista("adios", "hola");
    grafica.AgregarArista("hola","buenas");
    grafica.EliminarNodo("hola");
    grafica.ImprimirNodos();
    cout << grafica.ObtenerGrado("hola") << endl;
    return 0;
}
