//
// Created by Santy on 19/04/2023.
//

#ifndef GRAFICA_GRAFICA_H
#define GRAFICA_GRAFICA_H

#include <iostream>

struct Grafica {
public:
    Grafica();

    ~Grafica();

    Grafica &operator=(const Grafica &otra);

    Grafica(const Grafica &otra);

private:
    struct Nodo {
        unsigned grado;
        Nodo *siguiente;

        struct Arista {
            Nodo *adyacente;
            Arista *sigArista;

            explicit Arista(Nodo *ady, Arista *sigA = nullptr) : adyacente(ady), sigArista(sigA) {};
        } *pArista;

        explicit Nodo(int gr = 0, Nodo *sigN = nullptr, Arista *pA = nullptr) : grado(gr), siguiente(sigN),
                                                                                pArista(pA) {};
    } *pNodo, *uNodo;
};

#endif //GRAFICA_GRAFICA_H
