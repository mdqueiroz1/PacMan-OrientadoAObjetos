#ifndef MAP_H
#define MAP_H

#include "Biblioteca.h"
#include "Moeda.cpp"
#include "Parede.cpp"

const int TAM_MAPA_L = 653;
const int TAM_MAPA_A = 720;

class Map : Moeda, Parede{
    private:
  
    public:
        Map();
        ~Map();
        void montarMapa();
};

#endif