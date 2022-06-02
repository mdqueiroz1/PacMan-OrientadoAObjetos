#include "Display.h"

Display::Display(){
}

Display::~Display(){
    al_destroy_display(display);
    printf("Display destruido com sucesso!\n");
}

void Display::iniciaDisplay(){
    display = al_create_display(TELA_H,TELA_V);
    if (!display){
        fprintf(stderr,"Erro ao criar o display!!\n");
    }
    al_clear_to_color(al_map_rgb(0,0,0)); 
}

ALLEGRO_DISPLAY* Display::getDisplay(){
    return display;
}