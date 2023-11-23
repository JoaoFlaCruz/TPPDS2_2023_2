#include "DuqueDezena.hpp"

DuqueDezena::DuqueDezena(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Duque(nome_do_jogador,valor, apostas, cabeca){}

DuqueDezena::~DuqueDezena(){}

void DuqueDezena::verificar_vitoria(std::vector<int> resultado){

    int aposta_a = apostas_[0];
    bool verificador_a = false;
    bool verificador_b = false;

    for(auto i = resultado.begin(); i < resultado.end(); i++) {



    }

}