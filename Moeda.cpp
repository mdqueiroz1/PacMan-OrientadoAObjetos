#include <stdio.h>
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

using namespace std;

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

Moeda::Moeda(){
    moeda = al_load_bitmap("sprites/moeda.png");
    if(!moeda) printf("Erro ao criar sprite da moeda\n");
    moeda_borda_x = 22;
    moeda_borda_y = 22;
}

Moeda::~Moeda(){}

void Moeda::coletaMoeda(){
    if (!getColetado()){
        setColetado(true);
    }
}

bool Moeda::getColetado(){
    return coletado;
}
void Moeda::setColetado(bool _coletado){
    coletado = _coletado;
}

int Moeda::getMoedaBordaX(){
    return moeda_borda_x;
}

int Moeda::getMoedaBordaY(){
    return moeda_borda_y;
}

