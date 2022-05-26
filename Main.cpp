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

    al_rest(10);
    return 0;
}
