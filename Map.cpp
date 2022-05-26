#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
using namespace std;

const int TAM_MAPA_L = 662;
const int TAM_MAPA_A = 720;

class Map{
private:
    ALLEGRO_BITMAP *mapa;
public:
    Map(/* args */);
    ~Map();

    void montarMapa(){
        
        int posicaoImagemA = ((1280-TAM_MAPA_L)/2),
            posicaoImagemL = 0;
        
        mapa = al_load_bitmap("sprites/mapa.png");
        if(!mapa) printf("Erro ao criar background\n");
        
        al_draw_bitmap_region(mapa, 0, 0, TAM_MAPA_L, TAM_MAPA_A, posicaoImagemA, posicaoImagemL, 0);
        al_flip_display();
    }

};

Map::Map(){}

Map::~Map(){
    printf("Mapa destruido com sucesso!\n");
}
