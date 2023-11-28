#include "models/aposta/terno/Terno.hpp"

Terno::Terno(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 3> apostas)
    : Aposta(nome_do_jogador, valor, cabeca){


    if( apostas[0] == apostas[1] ){
        throw NumerosDasApostasIguais{apostas[0], apostas[1]};
    }
    if (apostas[0] == apostas[2]) {
        throw NumerosDasApostasIguais{ apostas[0], apostas[2] };
    }
    if ( apostas[1] == apostas[2] ) {
        throw NumerosDasApostasIguais{ apostas[1], apostas[2] };
    }

    if(apostas[0] < 0){
        throw NumeroDaApostaNegativo{ apostas[0] };
    }
    if (apostas[1] < 0) {
        throw NumeroDaApostaNegativo{ apostas[1] };
    }
    if (apostas[2] < 0) {
        throw NumeroDaApostaNegativo{ apostas[2] };
    }


    if(apostas[0] > 99){
        throw NumeroDaApostaMuitoAlto{ apostas[0] };
    }
    if (apostas[1] > 99) {
        throw NumeroDaApostaMuitoAlto{ apostas[1] };
    }
    if (apostas[2] > 99) {
        throw NumeroDaApostaMuitoAlto{ apostas[2] };
    }

    for (int i = 0; i < 3; i++) {
        this->apostas_.push_back(apostas[i]);
    }


}

Terno::~Terno() {}

std::vector<int> Terno::apostas() {

    return apostas_;

}
