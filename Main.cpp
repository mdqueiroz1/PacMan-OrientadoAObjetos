#include "Display.cpp"
#include "Map.cpp"

using namespace std;

int main(){

    try{
        if( !al_init() ||
            !al_init_image_addon()||
            !al_install_keyboard()||
            !al_init_font_addon()||
            !al_init_ttf_addon())
            throw NULL;
    }
    catch(const std::invalid_argument& e){
        std::cerr << "Erro ao iniciar Allegro " << e.what() << '\n';
    }
    
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
                            {1,2,2,2,1,1,2,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,1,1,2,2,2,1},//
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
                al_draw_bitmap_region(personagem.getPacmanSprite(), 0, personagem.getDirecaoPacman(), personagem.getPacmanBordaX(), personagem.getPacmanBordaY(),
                    personagem.getPosicaoPacmanX(), personagem.getPosicaoPacmanY(),0);
                string str = "Pontuacao: " + std::to_string(personagem.getPontuacaoPacman());
                const char *pontuacaoStr = str.c_str();
                al_draw_text(mapa.getPontuacaoTexto(), al_map_rgb(255,0,0), 1, 1, ALLEGRO_ALIGN_LEFT, pontuacaoStr);
                al_flip_display();
                mapa.movimentaPacman(personagem,mapa);
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
                    personagem.setBufferPacman(DIR);
                    mapa.movimentaPacman(personagem,mapa);
                    
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
                    personagem.setBufferPacman(ESQ);
                    mapa.movimentaPacman(personagem,mapa);
                    
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_UP){
                    personagem.setBufferPacman(CIM);
                    mapa.movimentaPacman(personagem,mapa);
                    
                }
                if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
                    personagem.setBufferPacman(BAI);
                    mapa.movimentaPacman(personagem,mapa);
                    
                }
                
            }
        }
    }
    al_destroy_event_queue(event_queue);
    return 0;
}
