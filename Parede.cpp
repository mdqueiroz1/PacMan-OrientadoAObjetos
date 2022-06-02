#include "Parede.h"

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
    al_destroy_bitmap(parede);
    al_destroy_bitmap(vazio);
    printf("Paredes destruidas!\n");
}

int Parede::getParedeBordaX(){
    return parede_borda_x;
}
int Parede::getParedeBordaY(){
    return parede_borda_y;
}
