#include "models/aposta/duque/DuqueDezena.hpp"

DuqueDezena::DuqueDezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas)
    : Duque(nome_do_jogador,valor, cabeca, apostas){}

DuqueDezena::~DuqueDezena(){}

void DuqueDezena::verificar_vitoria(std::array<int, 5> resultado){

    int primeira_aposta = apostas_[0];
    bool verificador_primeira_aposta = false;
    int segunda_aposta = apostas_[1];
    bool verificador_segunda_aposta = false;

    for(int i = 0; i < 5; i++) {
        if( (resultado[i]%100) == primeira_aposta) {
            verificador_primeira_aposta = true;
        }
        if( (resultado[i]%100) == segunda_aposta) {
            verificador_segunda_aposta = true;
        }
    }

    if(verificador_primeira_aposta && verificador_segunda_aposta) {
        ganhou_ = true;
    } else {
        ganhou_ = false;
    }

}
bool DuqueDezena::operator==(Aposta outra) {
    if (this->nome_do_jogador_ == outra.nome_do_jogador()
        && this->valor_ == outra.valor() && this->cabeca_ == outra.cabeca()
        && this->ganhou() == outra.ganhou() && this->apostas_ == outra.apostas()) {
        return 1;
    }

    return false;
}
