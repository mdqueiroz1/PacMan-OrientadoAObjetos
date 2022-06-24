#include "Display.cpp"
#include "Map.cpp"

using namespace std;

int main(){

    if(!al_init()) {
        printf("Erro ao iniciar o Allegro!\n");
    }
    al_init_image_addon();
    al_install_keyboard();

    PacMan personagem;
    Display d;
    d.iniciaDisplay();

    int mapaModelo[32][28] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//
                        {1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//
                        {1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//
                        {1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//
                        {1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//
                        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},//
                        {1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},//
                        {1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},//
                        {1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},//
                        {1,1,1,1,1,1,2,1,1,1,1,1,3,1,1,3,1,1,1,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,1,1,1,3,1,1,3,1,1,1,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,3,3,3,1,1,3,3,3,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,3,3,3,1,1,3,3,3,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,3,3,3,3,3,3,3,3,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,1,1,1,3,3,1,1,1,3,1,1,2,1,1,1,1,1,1},//
                        {3,3,3,3,3,3,2,1,1,3,1,3,3,3,3,3,3,1,3,1,1,2,3,3,3,3,3,3},//
                        {1,1,1,1,1,1,2,1,1,3,1,3,3,3,3,3,3,1,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,1,1,1,1,1,1,1,1,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,3,3,3,3,3,3,3,3,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,1,1,1,1,1,1,1,1,3,1,1,2,1,1,1,1,1,1},//
                        {1,1,1,1,1,1,2,1,1,3,1,1,1,1,1,1,1,1,3,1,1,2,1,1,1,1,1,1},//
                        {1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},//
                        {1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//
                        {1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},//
                        {1,2,2,2,1,1,2,2,2,2,2,2,2,3,4,2,2,2,2,2,2,2,1,1,2,2,2,1},//
                        {1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},//
                        {1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},//
                        {1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},//
                        {1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},//
                        {1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},//
                        {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},//
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

    Map mapa(mapaModelo);
    mapa.montarMapa(mapa);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    if(!event_queue) {
        printf("Erro ao iniciar a queue!\n");
        return -1;
    }
    const float FPS = 60;
    ALLEGRO_TIMER *timer = NULL;
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        printf("falha ao criar o timer!\n");
        return -1;
    }
    al_register_event_source(event_queue, al_get_display_event_source(d.getDisplay()));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    
    bool fecharJogo = false;
    int tempo, miliseg = 50;
    int sprite = 0, fator = 1;

    while ( !fecharJogo ){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        tempo = al_get_timer_count(timer);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            if(tempo == (FPS*miliseg)/1000) {//Quando tempo == FPS equivale a 1 segundo, assim a cada x milisegundos ele muda a sprite
                al_set_timer_count(timer, 0);//Volta ao tempo 0
                sprite = sprite + fator; //0 1 2 3 2 1 0     
                if(sprite == 0) fator = 1;
                if(sprite == 3) fator = -1;
                mapa.montarMapa(mapa);
                al_draw_bitmap_region(personagem.getPacmanSprite(), personagem.getDirecaoPacman()*sprite, personagem.getDirecaoPacman(), personagem.getPacmanBordaX(), personagem.getPacmanBordaY(),
                    personagem.getPosicaoPacmanX(), personagem.getPosicaoPacmanY(),0);
                al_flip_display();
                //mapa.movimentaPacman(personagem,mapa,personagem.getDirecaoPacman());
            } 
        }else{
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                break;
            }else
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    break;
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
                    personagem.setDirecaoPacman(DIR);
                    mapa.movimentaPacman(personagem,mapa, DIR);
                    
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                    personagem.setDirecaoPacman(ESQ);
                    mapa.movimentaPacman(personagem,mapa, ESQ);
                    
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_UP){
                    personagem.setDirecaoPacman(CIM);
                    mapa.movimentaPacman(personagem,mapa, CIM);
                    
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
                    personagem.setDirecaoPacman(BAI);
                    mapa.movimentaPacman(personagem,mapa, BAI);
                    
                }
                
            }
        }
    }
    al_destroy_event_queue(event_queue);
    return 0;
}
