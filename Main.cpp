#include "Display.cpp"
#include "Map.cpp"

using namespace std;

int main(){

    if(!al_init()) {
        printf("Erro ao iniciar o Allegro!\n");
    }
    al_init_image_addon();
    al_install_keyboard();


    Display d;
    d.iniciaDisplay();
    Map m;
    m.montarMapa();

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    if(!event_queue) {
        printf("Erro ao iniciar a queue!\n");
        return -1;
    }
    const float FPS = 60;
    ALLEGRO_TIMER *timer = NULL;
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    al_register_event_source(event_queue, al_get_display_event_source(d.getDisplay()));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    bool fecharJogo = false;

    while ( !fecharJogo ){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_TIMER) {
            
        }else 
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                break;
            }else
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    break;
                }
                
            }
    }
    al_destroy_event_queue(event_queue);
    return 0;
}
