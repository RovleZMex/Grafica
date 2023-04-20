//
// Created by Santy on 19/04/2023.
//

#include "Grafica.h"

Grafica::Grafica() {
    pNodo = nullptr;
    uNodo = nullptr;
}

Grafica::~Grafica() {

}

Grafica &Grafica::operator=(const Grafica &otra) {
    return *this;
}

Grafica::Grafica(const Grafica &otra) {
    *this = otra;
}
