#ifndef PACMAN_H
#define PACMAN_H

#include "Biblioteca.h"

//Tamanho do sprite
const int TAM_PACMAN_L = 22;
const int TAM_PACMAN_A = 22;

//Posicao inicial
const int POSICAO_INICIO_PACMAN_X = 308;
const int POSICAO_INICIO_PACMAN_Y = 528;
//DIREÇÕES DO PERSONAGEM
const int DIR = 0;
const int ESQ = 22;
const int CIM = 66;
const int BAI = 44;

class PacMan{
    private:
        int posicao_pacman_x,
            posicao_pacman_y,
            posicao_mapa_pacman_x,
            posicao_mapa_pacman_y,
            borda_pacman_x, 
            borda_pacman_y,
            direcao,
            pontuacao;

    protected:
        ALLEGRO_BITMAP *pacmanSprite;
    public:
        PacMan();
        ~PacMan();
        int getPosicaoPacmanX();
        int getPosicaoPacmanY();
        void setPosicaoPacmanX(int);
        void setPosicaoPacmanY(int);
        void setPacmanBordaX(int);
        int getPacmanBordaX();
        void setPacmanBordaY(int);
        int getPacmanBordaY();
        int getDirecaoPacman();
        void setDirecaoPacman(int);
        void setPosicaoXMapaPacman(int);
        int getPosicaoXMapaPacman();
        void setPosicaoYMapaPacman(int);
        int getPosicaoYMapaPacman();
        ALLEGRO_BITMAP* getPacmanSprite();
        int getPontuacaoPacman();
        void setPontuacaoPacman(int);
};

#endif

