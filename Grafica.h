//
// Created by Santy on 19/04/2023.
//

#ifndef GRAFICA_GRAFICA_H
#define GRAFICA_GRAFICA_H

#include <iostream>
#include <utility>

struct Grafica {
public:
    Grafica();

    ~Grafica();

    void AgregarNodo(std::string etiqueta);

    void EliminarNodo(const std::string &etiqueta);

    void AgregarArista(const std::string &inicio, const std::string &fin);

    unsigned ObtenerNumNodos() const;

    unsigned ObtenerGrado(const std::string &etiqueta);

    void ImprimirNodos() const;

    Grafica &operator=(const Grafica &otra);

    Grafica(const Grafica &otra);

private:
    unsigned numNodos;

    struct Nodo {
        unsigned grado;
        std::string etiqueta;
        Nodo *siguiente;

        struct Arista {
            Nodo *adyacente;
            Arista *sigArista;

            explicit Arista(Nodo *ady, Arista *sigA = nullptr) : adyacente(ady), sigArista(sigA) {};
        } *pArista;

        explicit Nodo(std::string et, int gr = 0, Nodo *sigN = nullptr, Arista *pA = nullptr) : grado(gr),
                                                                                                siguiente(sigN),
                                                                                                pArista(pA),
                                                                                                etiqueta(std::move(et))
                                                                                                {};

        void AgregarArista(Nodo *ady);

        void ImprimirAristas() const;

    } *pNodo, *uNodo;

    Nodo *BuscarNodo(const std::string &etiqueta) const;
};

#endif //GRAFICA_GRAFICA_H
