#include "Map.h"

Map::Map(){
    pontuacaoTexto = al_load_font("Roboto-Thin.ttf",12,0);
}

Map::Map(int mapa[TAM_MAPA_L][TAM_MAPA_A]){

    for (int i = 0; i < TAM_MAPA_L; i++){
        for (int j = 0; j < TAM_MAPA_A; j++){
            this->mapa[i][j] = mapa[i][j]; 
        }
    }

    pontuacaoTexto = al_load_font("Roboto-Bold.ttf",13,0);

}

Map::~Map(){
    printf("Mapa destruido com sucesso!\n");
}

ALLEGRO_FONT* Map::getPontuacaoTexto(){
    return pontuacaoTexto;
}

int Map::getValorMapa(int posicaoX, int posicaoY){
    return this->mapa[posicaoY][posicaoX];
}

void Map::setValorMapa(int posicaoX, int posicaoY, int valor){
    this->mapa[posicaoY][posicaoX] = valor;
}

void Map::montarMapa(Map& mapaObj){

    int posicaoImagemA = 0,
        posicaoImagemL = 0;   

    for (int i = 0; i < TAM_MAPA_L; i++){
        for (int j = 0; j < TAM_MAPA_A; j++){
            switch (mapaObj.mapa[i][j]){
                case PAREDE:{
                    al_draw_bitmap_region(parede, 0, 0, getParedeBordaX(), getParedeBordaY(), posicaoImagemL+(j*22),posicaoImagemA+(i*22),0);
                    break;
                }
                case MOEDA:{
                    al_draw_bitmap_region(moeda, 0, 0, getMoedaBordaX(), getMoedaBordaY(), posicaoImagemL+(j*22),posicaoImagemA+(i*22), 0);
                    break;
                }
                case VAZIO:{
                    al_draw_bitmap_region(vazio, 0, 0, getParedeBordaX(), getParedeBordaY(), posicaoImagemL+(j*22),posicaoImagemA+(i*22),0);
                    break;
                }

            }
        }  
    }
    al_flip_display(); 
    
}

void Map::movimentaPacman(PacMan& personagem, Map& mapa){

    switch (personagem.getDirecaoPacman()){
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

    printf("Mapa: X:%d Y:%d Imagem:X:%d Y:%d ", personagem.getPosicaoXMapaPacman(), personagem.getPosicaoYMapaPacman(), personagem.getPosicaoPacmanX(),personagem.getPosicaoPacmanY());
    printf("Item: %d\n",mapa.getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()));
}

bool Map::movimentoValido(PacMan& personagem, Map& map){

    bool valido = false;

    switch (personagem.getDirecaoPacman()){
        case BAI:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1);
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1));
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1) != PAREDE){
                valido = true;
            }
            break;
        case ESQ:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman()-1,personagem.getPosicaoYMapaPacman());
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman()-1,personagem.getPosicaoYMapaPacman()));
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman()-1,personagem.getPosicaoYMapaPacman()) != PAREDE){
                valido = true;
            }
            break;
        case CIM:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1);
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1));
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1) != PAREDE){
                valido = true;         
            }
            break;
        case DIR:
            printf("X%d Y%d:",personagem.getPosicaoXMapaPacman()+1,personagem.getPosicaoYMapaPacman());
            printf("%d\n",getValorMapa(personagem.getPosicaoXMapaPacman()+1,personagem.getPosicaoYMapaPacman()));
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman()+1,personagem.getPosicaoYMapaPacman()) != PAREDE){
                valido = true;           
            }
            break;
    }

    return valido;
}

void Map::atualizaMapa(PacMan& personagem,Map& mapaObj){
    int localX, localY;
    if(personagem.getDirecaoPacman() == DIR || personagem.getDirecaoPacman() == BAI){
        localX = personagem.getPosicaoPacmanX()/TAM_PACMAN_L;
        localY = personagem.getPosicaoPacmanY()/TAM_PACMAN_A;
    }else{
        localX = (personagem.getPosicaoPacmanX()+22)/TAM_PACMAN_L; 
        localY = (personagem.getPosicaoPacmanY()+22)/TAM_PACMAN_A;
    }

    if(localX != personagem.getPosicaoXMapaPacman() || 
        localY != personagem.getPosicaoYMapaPacman()){
        
        if(mapaObj.getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1) == MOEDA){
            personagem.setPontuacaoPacman(personagem.getPontuacaoPacman()+1);
        }

        personagem.setPosicaoXMapaPacman(localX);
        personagem.setPosicaoYMapaPacman(localY);
        mapaObj.setValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman(),VAZIO);     

        for (int i = 0; i < 28; i++){
            for (int j = 0; j < 32; j++){
                printf("%d,",mapaObj.getValorMapa(i,j));
            }
            printf("\n");
        }

    }

}