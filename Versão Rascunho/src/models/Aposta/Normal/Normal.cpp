#include "../../headers/models/aposta/normal/Normal.hpp"

Normal::Normal(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 1> apostas) : Aposta(nome_do_jogador, valor, cabeca) {
    if ( apostas[0] < 0 ) {
        throw NumeroDaApostaNegativo{ apostas[0] };
    }

    if ((apostas[0] > 99)) {
        throw NumeroDaApostaMuitoAlto{ apostas[0] };
    }

    for (int i = 0; i < 1; i++) {
        this->apostas_.push_back(apostas[i]);
    }
}

Normal::~Normal() {}

std::vector<int> Normal::apostas() {
    return apostas_;

}
