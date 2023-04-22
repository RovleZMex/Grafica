#include <iostream>
#include "Grafica.h"

using namespace std;

int main() {
    try {
        Grafica g;
        // Agregar nodos
        g.AgregarNodo("A");
        g.AgregarNodo("B");
        g.AgregarNodo("C");
        g.AgregarNodo("D");

        // Agregar aristas
        g.AgregarArista("A", "B");
        g.AgregarArista("B", "C");
        g.AgregarArista("C", "D");
        g.AgregarArista("D", "A");

        // Imprimir nodos y aristas
        g.Imprimir();
        std::cout << "N\243mero de nodos: " << g.ObtenerNumNodos() << std::endl;
        std::cout << "N\243mero de aristas: " << g.ObtenerAristas() << std::endl;

        // Obtener grado de un nodo
        std::cout << "Grado de C: " << g.ObtenerGrado("C") << std::endl;

        // Buscar nodo y arista
        std::cout << "El nodo A existe? " << g.BuscarNodo("A") << std::endl;
        std::cout << "La arista A-B existe? " << g.BuscarArista("A", "B") << std::endl;

        // Eliminar arista y nodo
        g.EliminarArista("A", "B");
        g.EliminarNodo("D");

        // Imprimir nodos y aristas actualizados
        g.Imprimir();
        std::cout << "N\243mero de aristas: " << g.ObtenerAristas() << std::endl;

        // Vaciar la gráfica
        g.Vaciar();

        // Comprobar si la gráfica está vacía
        std::cout << "N\243mero de nodos: " << g.ObtenerNumNodos() << std::endl;
        std::cout << "La gr\240fica est\240 vac\241a? " << g.EstaVacia() << std::endl;

        return 0;
    } catch (exception &exc) {
        cerr << exc.what() << endl;
    }
}
