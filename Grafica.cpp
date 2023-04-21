//
// Created by Santy on 19/04/2023.
//

#include "Grafica.h"

#include <utility>

Grafica::Grafica() {
    pNodo = nullptr;
    uNodo = nullptr;
    numNodos = 0;
}

Grafica::~Grafica() {
    Vaciar();
}


Grafica &Grafica::operator=(const Grafica &otra) {
    if (this == &otra) {
        return *this;
    }

    Vaciar();

    if (otra.EstaVacia()) {
        return *this;
    }

    Nodo *aux = otra.pNodo;

    while (aux != nullptr) {
        AgregarNodo(aux->etiqueta);
        aux = aux->siguiente;
    }

    return *this;
}

Grafica::Grafica(const Grafica &otra) {
    numNodos = 0;
    pNodo = nullptr;
    uNodo = nullptr;
    *this = otra;
}

void Grafica::AgregarNodo(std::string etiqueta) {
    Nodo *nuevo = new Nodo(std::move(etiqueta));
    if (numNodos == 0) {
        pNodo = uNodo = nuevo;
    } else {
        uNodo->siguiente = nuevo;
        uNodo = nuevo;
    }
    ++numNodos;
}

void Grafica::EliminarNodo(const std::string &etiqueta) {
    // Buscar el nodo a eliminar
    Nodo *nodoAEliminar = BuscarNodo(etiqueta);

    if (nodoAEliminar == nullptr) {
        // El nodo no existe, no hay nada que eliminar
        return;
    }

    // Eliminar las aristas que conectan al nodo
    Nodo *nodoActual = pNodo;
    while (nodoActual != nullptr) {
        nodoActual->EliminarArista(nodoAEliminar);
        nodoActual = nodoActual->siguiente;
    }

    // Eliminar el nodo de la lista de nodos
    if (pNodo == nodoAEliminar) {
        pNodo = nodoAEliminar->siguiente;
    } else {
        Nodo *nodoAnterior = pNodo;
        while (nodoAnterior->siguiente != nodoAEliminar) {
            nodoAnterior = nodoAnterior->siguiente;
        }
        nodoAnterior->siguiente = nodoAEliminar->siguiente;
    }

    // Liberar la memoria del nodo eliminado
    delete nodoAEliminar;

    // Actualizar el contador de nodos
    --numNodos;
}

unsigned Grafica::ObtenerNumNodos() const {
    return numNodos;
}

void Grafica::ImprimirNodos() const {
    Nodo *aux = pNodo;
    while (aux != nullptr) {
        std::cout << aux->etiqueta;
        aux->ImprimirAristas();
        std::cout << std::endl;
        aux = aux->siguiente;
    }
}

void Grafica::AgregarArista(const std::string &inicio, const std::string &fin) {
    Nodo *NodoI = BuscarNodo(inicio);
    Nodo *NodoF = BuscarNodo(fin);
    if (NodoI != nullptr && NodoF != nullptr) {
        NodoI->AgregarArista(NodoF);
        NodoF->AgregarArista(NodoI);
        return;
    }
    std::cout << "Nodo no encontrado" << std::endl;
    throw NodoNoEncontrado();
}

Grafica::Nodo *Grafica::BuscarNodo(const std::string &etiqueta) const {
    Nodo *actual = pNodo;
    while (actual != nullptr) {
        if (actual->etiqueta == etiqueta) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}


void Grafica::Nodo::AgregarArista(Nodo *ady) {
    auto *nueva = new Arista(ady);
    if (grado == 0) {
        pArista = nueva;
    } else {
        Arista *actual = pArista;
        while (actual->sigArista != nullptr) {
            actual = actual->sigArista;
        }
        actual->sigArista = nueva;
    }
    ++grado;
}

void Grafica::Nodo::ImprimirAristas() const {
    Arista *actual = pArista;
    while (actual != nullptr) {
        std::cout << " <-> " << actual->adyacente->etiqueta;
        actual = actual->sigArista;
    }
}

void Grafica::Nodo::EliminarArista(Nodo *ady) {
    if (pArista == nullptr) {
        // No hay aristas que eliminar
        return;
    }

    if (pArista->adyacente == ady) {
        // La primera arista es la que se quiere eliminar
        Arista *temp = pArista;
        pArista = pArista->sigArista;
        delete temp;
        --grado;
        return;
    }

    Arista *aristaActual = pArista;
    // Checar si la siguiente arista es nula o si el adyacente de la siguiente es diferente
    // al nodo adyacente
    while (aristaActual->sigArista != nullptr && aristaActual->sigArista->adyacente != ady) {
        aristaActual = aristaActual->sigArista;
    }

    if (aristaActual->sigArista == nullptr) {
        // No se encontró la arista a eliminar
        return;
    }

    // Eliminar la arista encontrada
    Arista *temp = aristaActual->sigArista;
    aristaActual->sigArista = aristaActual->sigArista->sigArista;
    delete temp;
    --grado;
}


unsigned Grafica::ObtenerGrado(const std::string &etiqueta) {
    Nodo *nodo = BuscarNodo(etiqueta);
    if (nodo != nullptr) return nodo->grado;
    throw NodoNoEncontrado();
}

void Grafica::Vaciar() {
    Nodo *actual = pNodo;
    while (actual != nullptr) {
        EliminarNodo(actual->etiqueta);
        actual = actual->siguiente;
    }
}

void Grafica::EliminarArista(const std::string &inicio, const std::string &fin) {
    Nodo *inicial = BuscarNodo(inicio);
    Nodo *ady = BuscarNodo(fin);
    if (inicial != nullptr && ady != nullptr) {
        inicial->EliminarArista(ady);
        ady->EliminarArista(inicial);
        return;
    }
    throw NodoNoEncontrado();
}

bool Grafica::EstaVacia() const {
    return numNodos == 0;
}

