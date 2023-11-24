#include "Terno.hpp"

Terno::Terno(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Aposta(nome_do_jogador, valor, cabeca){


    if((apostas[0] == apostas[1]) || (apostas[0] == apostas[2]) || (apostas[1] == apostas[2])){
        throw ValorDasApostasIgual{};
    }

    if((apostas[0] < 0) || (apostas[1] < 0) || (apostas[3] < 0)){
        throw ValorDaApostaNegativo{};
    }

    if((apostas[0] > 99) || (apostas[1] > 99) || (apostas[2] > 99)){
        throw ValorDaApostaMuitoAlto{};
    }

    apostas_ = apostas;

}

Terno::~Terno() {}

std::vector<int> Terno::apostas() {

    return apostas_;

}