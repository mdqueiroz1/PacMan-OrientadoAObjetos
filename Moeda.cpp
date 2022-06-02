#include "Moeda.h"

Moeda::Moeda(){
    moeda = al_load_bitmap("sprites/moeda.png");
    if(!moeda) printf("Erro ao criar sprite da moeda\n");
    moeda_borda_x = 22;
    moeda_borda_y = 22;
}

Moeda::~Moeda(){
    al_destroy_bitmap(moeda);
}

void Moeda::coletaMoeda(){
    if (!getColetado()){
        setColetado(true);
    }
}

bool Moeda::getColetado(){
    return coletado;
}
void Moeda::setColetado(bool _coletado){
    coletado = _coletado;
}

int Moeda::getMoedaBordaX(){
    return moeda_borda_x;
}

int Moeda::getMoedaBordaY(){
    return moeda_borda_y;
}

