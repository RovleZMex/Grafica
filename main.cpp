#include <iostream>
#include "Grafica.h"

using namespace std;

int main() {
    try{
        Grafica grafica;
        grafica.AgregarNodo("hola");
        grafica.AgregarNodo("bye");
        grafica.AgregarNodo("buenas");
        grafica.AgregarArista("hola", "bye");
        grafica.AgregarNodo("adios");
        grafica.AgregarArista("adios", "hola");
        grafica.AgregarArista("hola","buenas");
        grafica.EliminarArista("hola","bye");
        grafica.EliminarNodo("hola");
        grafica.ImprimirNodos();

        return 0;
    }catch(exception &exc){
        cerr << exc.what() << endl;
    }
}
