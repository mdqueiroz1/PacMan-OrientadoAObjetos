#include "Map.h"

Map::Map(){}

Map::Map(int mapa[TAM_MAPA_L][TAM_MAPA_A]){

    for (int i = 0; i < TAM_MAPA_L; i++){
        for (int j = 0; j < TAM_MAPA_A; j++){
            this->mapa[i][j] = mapa[i][j]; 
        }
    }

}

Map::~Map(){
    printf("Mapa destruido com sucesso!\n");
}

int Map::getValorMapa(int posicaoX, int posicaoY){
    return this->mapa[posicaoX][posicaoY];
}

void Map::setValorMapa(int posicaoX, int posicaoY, int valor){
    this->mapa[posicaoX][posicaoY] = valor;
}

void Map::montarMapa(Map& mapaObj){

    int posicaoImagemA = 0,
        posicaoImagemL = 0;   

    for (int i = 0; i < TAM_MAPA_L; i++){
        for (int j = 0; j < TAM_MAPA_A; j++){
            switch (mapaObj.mapa[i][j]){
                case 1:{
                    al_draw_bitmap_region(parede, 0, 0, getParedeBordaX(), getParedeBordaY(), posicaoImagemL+(j*22),posicaoImagemA+(i*22),0);
                    break;
                }
                case 2:{
                    al_draw_bitmap_region(moeda, 0, 0, getMoedaBordaX(), getMoedaBordaY(), posicaoImagemL+(j*22),posicaoImagemA+(i*22), 0);
                    break;
                }
                case 3:{
                    al_draw_bitmap_region(vazio, 0, 0, getParedeBordaX(), getParedeBordaY(), posicaoImagemL+(j*22),posicaoImagemA+(i*22),0);
                    break;
                }

            }
        }  
    }
    al_flip_display(); 
    
}

void Map::movimentaPacman(PacMan& personagem,Map& mapa, int movimento){

    switch (movimento){
        case DIR:{
            if (personagem.getPosicaoPacmanX()+22 <= TAM_MAPA_PIXEL_L 
                && movimentoValido(personagem, mapa)){
                personagem.setPosicaoPacmanX(personagem.getPosicaoPacmanX()+2);
                atualizaMapa(personagem,mapa);
                printf("Direita\n");
            }
            break;
        }
        
        case ESQ:{
            if(personagem.getPosicaoPacmanX() >= 0 
                && movimentoValido(personagem, mapa)){
                personagem.setPosicaoPacmanX(personagem.getPosicaoPacmanX()-2);
                atualizaMapa(personagem,mapa);
                printf("Esquerda\n");
            }
            break;
        }
        
        case CIM:{
            if(personagem.getPosicaoPacmanY() >= 0 
                && movimentoValido(personagem, mapa)){
                personagem.setPosicaoPacmanY(personagem.getPosicaoPacmanY()-2);
                atualizaMapa(personagem,mapa);
                printf("Cima\n");
            }
            break;
        }
            
        
        case BAI:{
            if(personagem.getPosicaoPacmanY()+22 < TAM_MAPA_PIXEL_A 
                && movimentoValido(personagem, mapa)){
                personagem.setPosicaoPacmanY(personagem.getPosicaoPacmanY()+2);
                atualizaMapa(personagem,mapa);
                printf("Baixo\n");
            }
            break;                    
        }
            
        default:{
            printf("Direcao invalida\n");
            break;
        }
    }

    printf("Mapa: X:%d Y:%d Imagem:X:%d Y:%d\n", personagem.getPosicaoXMapaPacman(), personagem.getPosicaoYMapaPacman(), personagem.getPosicaoPacmanX(),personagem.getPosicaoPacmanY());
}

bool Map::movimentoValido(PacMan& personagem, Map& map){

    bool valido = false;

    switch (personagem.getDirecaoPacman()){
        case DIR:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1);
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1));
            if(getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1) != PAREDE){
                valido = true;
                printf("direita\n");
            }
            break;
        case CIM:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman()-1,personagem.getPosicaoYMapaPacman());
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman()-1,personagem.getPosicaoYMapaPacman()));
            if(getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1) != PAREDE){
                valido = true;
                printf("cima\n");   
            }
            break;
        case ESQ:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1);
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1));
            if(getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1) != PAREDE){
                valido = true;         
                printf("esquerda\n");
            }
            break;
        case BAI:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman()+1,personagem.getPosicaoYMapaPacman());
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman()+1,personagem.getPosicaoYMapaPacman()));
            if(getValorMapa(personagem.getPosicaoXMapaPacman()+1,personagem.getPosicaoYMapaPacman()) != PAREDE){
                valido = true;           
                printf("baixo\n"); 
            }
            break;
    }

    return valido;
}

void Map::atualizaMapa(PacMan& personagem,Map& mapaObj){
    int localX = personagem.getPosicaoPacmanX()/TAM_PACMAN_L, 
        localY = personagem.getPosicaoPacmanY()/TAM_PACMAN_A;

    if(localX != personagem.getPosicaoXMapaPacman())
        personagem.setPosicaoXMapaPacman(localX);
    if(localY != personagem.getPosicaoYMapaPacman())
        personagem.setPosicaoYMapaPacman(localY);

}