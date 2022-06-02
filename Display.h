#ifndef DISPLAY_H 
#define DISPLAY_H

#include "Biblioteca.h"

const int TELA_H = 1280;
const int TELA_V = 720;

class Display{
private:
    ALLEGRO_DISPLAY *display = NULL;
public:
    Display();
    ~Display();
    void iniciaDisplay();
    ALLEGRO_DISPLAY* getDisplay();
};

#endif