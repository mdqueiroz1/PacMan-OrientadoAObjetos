#ifndef PAREDE_H
#define PAREDE_H

const int TAM_PAREDE_L = 22;
const int TAM_PAREDE_A = 22;

#include "Biblioteca.h"

class Parede{
    private:
        int parede_borda_x, parede_borda_y;

    protected:
        ALLEGRO_BITMAP *parede;
        ALLEGRO_BITMAP *vazio;
    public:
        Parede();
        ~Parede();
        void inicializaParedes();
        int getParedeBordaX();
        int getParedeBordaY();
};

#endif