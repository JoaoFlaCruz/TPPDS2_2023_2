#include "TernoDezena.hpp"

TernoDezena::TernoDezena(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Terno(nome_do_jogador,valor, apostas, cabeca){}

TernoDezena::~TernoDezena(){}

void TernoDezena::verificar_vitoria(std::vector<int> resultado){

    int aposta_a = apostas_[0];
    bool verificador_a = false;
    int aposta_b = apostas_[1];
    bool verificador_b = false;
    int aposta_c = apostas_[2];
    bool verificador_c = false;

    for(int i = 0; i < 5; i++) {
        if( (resultado[i]%100) == aposta_a) {
            verificador_a = true;
        }
        if( (resultado[i]%100) == aposta_b) {
            verificador_b = true;
        }
        if( (resultado[i]%100) == aposta_c) {
            verificador_c = true;
        }
    }

    if( verificador_a && verificador_b && verificador_c) {
        ganhou_ = true;
    } else {
        ganhou_ = false;
    }

}