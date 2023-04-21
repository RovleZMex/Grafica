#include <iostream>
#include "Grafica.h"

using namespace std;

int main() {
    try{
        Grafica grafica;
        grafica.AgregarNodo("hola");
        grafica.AgregarNodo("zombie");
        grafica.AgregarNodo("bye");
        grafica.AgregarNodo("buenas");
        grafica.AgregarArista("hola", "bye");
        grafica.AgregarNodo("adios");
        grafica.AgregarArista("adios", "hola");
        grafica.AgregarArista("hola","buenas");
        grafica.EliminarArista("hola","bye");
        grafica.AgregarArista("zombie", "bye");
        grafica.ImprimirNodos();

        return 0;
    }catch(exception &exc){
        cerr << exc.what() << endl;
    }
}
