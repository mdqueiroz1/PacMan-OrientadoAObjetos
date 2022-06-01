#include <stdio.h>
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

using namespace std;

const int TAM_PAREDE_L = 22;
const int TAM_PAREDE_A = 22;

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

void Parede::inicializaParedes(){
    parede = al_load_bitmap("sprites/parede.png");
    vazio = al_load_bitmap("sprites/vazio.png");
    if(!parede || !vazio){printf("Erro ao criar sprite do mapa!\n");}
    parede_borda_x = 22;
    parede_borda_y = 22;
}

Parede::Parede(){
    inicializaParedes();
}

Parede::~Parede(){
    printf("Paredes destruidas!\n");
}

int Parede::getParedeBordaX(){
    return parede_borda_x;
}
int Parede::getParedeBordaY(){
    return parede_borda_y;
}
