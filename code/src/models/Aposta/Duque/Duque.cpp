#include "../../headers/models/aposta/duque/Duque.hpp"

Duque::Duque(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas)
    : Aposta(nome_do_jogador, valor, cabeca){


    if(apostas[0] == apostas[1]){
        throw NumerosDasApostasIguais{ apostas[0], apostas[1]};
    }

    if((apostas[0] < 0)){
        throw NumeroDaApostaNegativo{ apostas[0] };
    }
    if (apostas[1] < 0) {
        throw NumeroDaApostaNegativo{ apostas[1] };
    }

    if((apostas[0] > 99)){
        throw NumeroDaApostaMuitoAlto{ apostas[0] };
    }
    if ((apostas[1] > 99)) {
        throw NumeroDaApostaMuitoAlto{ apostas[1]};
    }

    for (int i = 0; i < 2; i++) {
        this->apostas_.push_back(apostas[i]);
    }

}

Duque::~Duque() {}

std::vector<int> Duque::apostas() {
    return apostas_;

}
