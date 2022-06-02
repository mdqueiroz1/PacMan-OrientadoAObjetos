#ifndef MOEDA_H 
#define MOEDA_H

#include "Biblioteca.h"

const int TAM_MOEDA_L = 22;
const int TAM_MOEDA_A = 22;

class Moeda{
    private:
        int moeda_borda_x, moeda_borda_y;
        bool coletado;
    protected:
        ALLEGRO_BITMAP *moeda;
    public:
        Moeda();
        ~Moeda();
        void coletaMoeda();
        bool getColetado();
        void setColetado(bool foiColetado);
        int getMoedaBordaX();
        int getMoedaBordaY();
};

#endif