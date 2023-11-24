#include "Duque.hpp"

Duque::Duque(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Aposta(nome_do_jogador, valor, cabeca){


    if(apostas[0] == apostas[1]){
        throw ValorDasApostasIgual{};
    }

    if((apostas[0] < 0) || (apostas[1] < 0)){
        throw ValorDaApostaNegativo{};
    }

    if((apostas[0] > 99) || (apostas[1] > 99)){
        throw ValorDaApostaMuitoAlto{};
    }

    apostas_ = apostas;

}

Duque::~Duque() {}

std::vector<int> Duque::apostas() {

    return apostas_;

}