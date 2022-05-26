#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
using namespace std;

const int TELA_H = 1280;
const int TELA_V = 720;

class Display{
private:
    ALLEGRO_DISPLAY *display = NULL;
public:
    Display();
    ~Display();

    ALLEGRO_DISPLAY* getDisplay(){
        return display;
    }

    void iniciaDisplay(){
        display = al_create_display(TELA_H,TELA_V);
        if (!display){
            fprintf(stderr,"Erro ao criar o display!!\n");
        }
        al_clear_to_color(al_map_rgb(0,0,0));
        al_clear_to_color(al_map_rgb(0,0,0));
        
    };
};

Display::Display(){
}

Display::~Display(){
    printf("Display destruido com sucesso!\n");
}
