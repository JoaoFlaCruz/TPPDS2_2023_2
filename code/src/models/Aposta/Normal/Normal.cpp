#include "Normal.hpp"

Normal::Normal(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Aposta(nome_do_jogador, valor, cabeca){

    if((apostas[0] < 0) ){
        throw ValorDaApostaNegativo{};
    }

    if((apostas[0] > 99) ){
        throw ValorDaApostaMuitoAlto{};
    }

    apostas_ = apostas;

}

Normal::~Normal() {}

std::vector<int> Normal::apostas() {

    return apostas_;

}
