#include "../../headers/models/aposta/normal/Grupo.hpp"
//Testar
Grupo::Grupo(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas)
    : Normal(nome_do_jogador, valor, cabeca, apostas) {}

Grupo::~Grupo(){}

void Grupo::verificar_vitoria(std::array<int, 5> resultado){

    int primeira_aposta = apostas_[0];
    bool se_aposta_foi_sorteada = false;

    for(int i = 0; i < 5; i++) {
        if( primeira_aposta == (int)(resultado[i]%100 / 4 + 1)) {
            se_aposta_foi_sorteada = true;
        }
        if(cabeca_) {
            break;
        }
    }

    if( se_aposta_foi_sorteada ) {
        ganhou_ = true;
    } else {
        ganhou_ = false;
    }
}
bool Grupo::operator==(Aposta outra) {
    if (this->nome_do_jogador_ == outra.nome_do_jogador()
        && this->valor_ == outra.valor() && this->cabeca_ == outra.cabeca()
        && this->ganhou() == outra.ganhou() && this->apostas_ == outra.apostas()) {
        return 1;
    }

    return false;
}
