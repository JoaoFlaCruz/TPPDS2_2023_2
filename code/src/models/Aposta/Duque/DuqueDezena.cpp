#include "DuqueDezena.hpp"

DuqueDezena::DuqueDezena(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Duque(nome_do_jogador,valor, apostas, cabeca){}

DuqueDezena::~DuqueDezena(){}

void DuqueDezena::verificar_vitoria(std::vector<int> resultado){

    int aposta_a = apostas_[0];
    bool verificador_a = false;
    int aposta_b = apostas_[1];
    bool verificador_b = false;

    for(int i = 0; i < 5; i++) {
        if( (resultado[i]%100) == aposta_a) {
            verificador_a = true;
        }
        if( (resultado[i]%100) == aposta_b) {
            verificador_b = true;
        }
    }

    if( verificador_a && verificador_b) {
        ganhou_ = true;
    } else {
        ganhou_ = false;
    }

}