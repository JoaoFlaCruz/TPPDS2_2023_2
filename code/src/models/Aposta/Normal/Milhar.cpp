#include "../../headers/models/aposta/normal/Milhar.hpp"

//Testar
Milhar::Milhar(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas)
    : Normal(nome_do_jogador, valor, cabeca, apostas){}

Milhar::~Milhar(){}

void Milhar::verificar_vitoria(std::array<int, 5> resultado) {

    int primeira_aposta = apostas_[0];
    bool se_aposta_foi_sorteada = false;

    for (int i = 0; i < 5; i++) {
        if (primeira_aposta == resultado[i]) {
            se_aposta_foi_sorteada = true;
        }
    }

    if (se_aposta_foi_sorteada) {
        ganhou_ = true;
    }
    else {
        ganhou_ = false;
    }
}

bool Milhar::operator==(Aposta outra) {
    if (this->nome_do_jogador_ == outra.nome_do_jogador()
        && this->valor_ == outra.valor() && this->cabeca_ == outra.cabeca()
        && this->ganhou() == outra.ganhou() && this->apostas_ == outra.apostas()) {
        return 1;
    }

    return false;
}
