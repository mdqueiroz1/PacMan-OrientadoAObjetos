#include "Display.cpp"
#include "Map.cpp"


int main(){

    if(!al_init()) {
        printf("Erro ao iniciar o Allegro!\n");
    }
    al_init_image_addon();
    
    Display d;
    d.iniciaDisplay();
    Map m;
    m.montarMapa();
    /*
    ALLEGRO_BITMAP *background;
    int backgroundL = 228, backgroundA = 248;
    background = al_load_bitmap("sprites/mapa.png");
    if(!background){
        printf("Erro ao criar background\n");
        return -1;
    }
    al_draw_bitmap(background, backgroundL ,backgroundA,0);
    al_flip_display();
   
    al_destroy_bitmap(background);
    */
    al_rest(10);
    return 0;
}
