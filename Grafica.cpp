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
    Nodo *actual = pNodo;
    while(actual != nullptr){
        EliminarNodo(actual->etiqueta);
        actual = actual->siguiente;
    }
}


Grafica &Grafica::operator=(const Grafica &otra) {
    if (this == &otra) {
        return *this;
    }
    return *this;
}

Grafica::Grafica(const Grafica &otra) {
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
    Nodo *nodoAEliminar = BuscarNodo(etiqueta);
    if (nodoAEliminar == nullptr) {
        return; // Si el nodo no existe, no se hace nada
    }

    // Eliminamos todas las aristas que conectan al nodo a eliminar
    Nodo *nodoActual = pNodo;
    while (nodoActual != nullptr) {
        Nodo::Arista *aristaActual = nodoActual->pArista;
        Nodo::Arista *aristaAnterior = nullptr;
        while (aristaActual != nullptr) {
            if (aristaActual->adyacente == nodoAEliminar) {
                if (aristaAnterior == nullptr) {
                    nodoActual->pArista = aristaActual->sigArista;
                } else {
                    aristaAnterior->sigArista = aristaActual->sigArista;
                }
                delete aristaActual;
                nodoActual->grado--;
                break;
            }
            aristaAnterior = aristaActual;
            aristaActual = aristaActual->sigArista;
        }
        nodoActual = nodoActual->siguiente;
    }

    // Eliminamos el nodo a eliminar
    if (nodoAEliminar == pNodo) {
        pNodo = nodoAEliminar->siguiente;
    } else {
        Nodo *nodoActual = pNodo;
        while (nodoActual->siguiente != nodoAEliminar) {
            nodoActual = nodoActual->siguiente;
        }
        nodoActual->siguiente = nodoAEliminar->siguiente;
    }
    if (nodoAEliminar == uNodo) {
        uNodo = nodoAEliminar->siguiente;
    }
    delete nodoAEliminar;
    numNodos--;
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
    throw "Nodo no encontrado"; //todo add exception
}

Grafica::Nodo *Grafica::BuscarNodo(const std::string &etiqueta) const {
    Nodo *actual = pNodo;
    do {
        if (actual->etiqueta == etiqueta) return actual;
        actual = actual->siguiente;
    } while (actual != nullptr);
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
    while(actual != nullptr){
        std::cout << " <-> " << actual->adyacente->etiqueta;
        actual = actual->sigArista;
    }
}

unsigned Grafica::ObtenerGrado(const std::string &etiqueta) {
    return BuscarNodo(etiqueta)->grado;
}

