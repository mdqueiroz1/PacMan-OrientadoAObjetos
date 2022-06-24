#include "PacMan.h"

PacMan::PacMan(){
    pacmanSprite = al_load_bitmap("sprites/pacman.png");
    if(!pacmanSprite) printf("Nao foi possivel criar o pacman!\n");
    borda_pacman_x = TAM_PACMAN_A;
    borda_pacman_y = TAM_PACMAN_L;
    posicao_mapa_pacman_x = POSICAO_INICIO_PACMAN_X/TAM_PACMAN_L;
    posicao_mapa_pacman_y = POSICAO_INICIO_PACMAN_Y/TAM_PACMAN_A;
    posicao_pacman_x = POSICAO_INICIO_PACMAN_X;
    posicao_pacman_y = POSICAO_INICIO_PACMAN_Y;
    direcao = DIR;
}

PacMan::~PacMan(){
    al_destroy_bitmap(pacmanSprite);
    printf("Pacman destruido com sucesso!\n");
}

int PacMan::getPacmanBordaX(){
    return borda_pacman_x;
}

void PacMan::setPacmanBordaX(int borda){
    borda_pacman_x = borda;
}

int PacMan::getPacmanBordaY(){
    return borda_pacman_y;
}

void PacMan::setPacmanBordaY(int borda){
    borda_pacman_y = borda;
}

int PacMan::getDirecaoPacman(){
    return direcao;
}

void PacMan::setDirecaoPacman(int direcao){
    switch (direcao){
        case DIR:{
            this->direcao = DIR;
            break;
        }
        
        case ESQ:{
            this->direcao = ESQ;
            break;
        }
        
        case CIM:{
            this->direcao = CIM;
            break;
        }
            
        
        case BAI:{
            this->direcao = BAI;
            break;                    
        }
            
        default:{
            printf("Direcao invalida\n");
            break;
        }
    }
}

int PacMan::getPosicaoPacmanX(){
    return posicao_pacman_x;
}

void PacMan::setPosicaoPacmanX(int posicao){
    this->posicao_pacman_x = posicao;
}

void PacMan::setPosicaoPacmanY(int posicao){
    this->posicao_pacman_y = posicao;
}

int PacMan::getPosicaoPacmanY(){
    return posicao_pacman_y;
}

ALLEGRO_BITMAP* PacMan::getPacmanSprite(){
    return pacmanSprite;
}

void PacMan::setPosicaoXMapaPacman(int posicao){
     posicao_mapa_pacman_x = posicao;
}

int PacMan::getPosicaoXMapaPacman(){
    return posicao_mapa_pacman_x;
}

void PacMan::setPosicaoYMapaPacman(int posicao){
     posicao_mapa_pacman_y = posicao;
}

int PacMan::getPosicaoYMapaPacman(){
    return posicao_mapa_pacman_y;
}

int PacMan::getPontuacaoPacman(){
    return pontuacao;
}

void PacMan::setPontuacaoPacman(int pontuacao){
    this->pontuacao = pontuacao;
}