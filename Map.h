#ifndef MAP_H
#define MAP_H

#include "Biblioteca.h"
#include "Moeda.cpp"
#include "Parede.cpp"
#include "PacMan.cpp"

//Definição dos tamanhos do mapa
const int TAM_MAPA_PIXEL_L = 616;
const int TAM_MAPA_PIXEL_A = 704;
const int TAM_MAPA_L = 32;
const int TAM_MAPA_A = 28;

//Objetos do mapa
const int PAREDE = 1;
const int MOEDA = 2;
const int VAZIO = 3;
const int PACMAN = 4;

class Map : public Moeda, public Parede, public PacMan{
    private:
        int mapa[32][28];
        ALLEGRO_FONT *pontuacaoTexto;
    public:
        Map();
        Map(int[32][28]);
        ~Map();
        int getValorMapa(int, int);
        void setValorMapa(int, int, int);
        void montarMapa(Map&);
        void atualizaMapa(PacMan&,Map&);
        void movimentaPacman(PacMan&,Map&);
        bool movimentoValido(PacMan&, Map&);
        ALLEGRO_FONT* getPontuacaoTexto();
};

#endif