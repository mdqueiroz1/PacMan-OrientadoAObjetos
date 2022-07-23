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

    if (personagem.getBufferPacman() != personagem.getDirecaoPacman()){
        if (movimentoValido(personagem, mapa, personagem.getBufferPacman())){
            switch (personagem.getBufferPacman()){
                case DIR:
                    personagem.setDirecaoPacman(DIR);
                    break;
                case ESQ:
                    personagem.setDirecaoPacman(ESQ);
                    break;
                case CIM:
                    personagem.setDirecaoPacman(CIM);
                    break;
                case BAI:
                    personagem.setDirecaoPacman(BAI);
                    break;
           }
        }
        
    }
    
    bool ehMovimentoValido = movimentoValido(personagem, mapa, personagem.getDirecaoPacman());

    switch (personagem.getDirecaoPacman()){
        case DIR:{
            if (personagem.getPosicaoPacmanX()+22 <= TAM_MAPA_PIXEL_L 
                && ehMovimentoValido){
                personagem.setPosicaoPacmanX(personagem.getPosicaoPacmanX()+2);
                atualizaMapa(personagem,mapa);
            }
            break;
        }
        
        case ESQ:{
            if(personagem.getPosicaoPacmanX() >= 0 
                && ehMovimentoValido){
                personagem.setPosicaoPacmanX(personagem.getPosicaoPacmanX()-2);
                atualizaMapa(personagem,mapa);
            }
            break;
        }
        
        case CIM:{
            if(personagem.getPosicaoPacmanY() >= 0 
                && ehMovimentoValido){
                personagem.setPosicaoPacmanY(personagem.getPosicaoPacmanY()-2);
                atualizaMapa(personagem,mapa);
            }
            break;
        }
            
        case BAI:{
            if(personagem.getPosicaoPacmanY()+22 < TAM_MAPA_PIXEL_A 
                && ehMovimentoValido){
                personagem.setPosicaoPacmanY(personagem.getPosicaoPacmanY()+2);
                atualizaMapa(personagem,mapa);
            }
            break;                    
        }
    }
}

bool Map::movimentoValido(PacMan& personagem, Map& map, int movimento){

    bool valido = false;

    switch (movimento){
        case BAI:
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()+1) != PAREDE){
                valido = true;
            }
            break;
        case ESQ:
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman()-1,personagem.getPosicaoYMapaPacman()) != PAREDE){
                valido = true;
            }
            break;
        case CIM:
            if(map.getValorMapa(personagem.getPosicaoXMapaPacman(),personagem.getPosicaoYMapaPacman()-1) != PAREDE){
                valido = true;         
            }
            break;
        case DIR:
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

    }

}