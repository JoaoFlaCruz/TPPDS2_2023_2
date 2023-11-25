#include "Grupo.hpp"
//Testar
Grupo::Grupo(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Normal(nome_do_jogador,valor, apostas, cabeca){}

Grupo::~Grupo(){}

void Grupo::verificar_vitoria(std::vector<int> resultado){

    int primeira_aposta = apostas_[0];
    bool se_aposta_foi_sorteada = false;
    
    for(int i = 0; i < 5; i++) {
        if( primeira_aposta == (int)(resultado[i]%100 / 4 + 1)) {
            se_aposta_foi_sorteada = true;
        }
    }

    if( se_aposta_foi_sorteada ) {
        ganhou_ = true;
    } else {
        ganhou_ = false;
    }

}