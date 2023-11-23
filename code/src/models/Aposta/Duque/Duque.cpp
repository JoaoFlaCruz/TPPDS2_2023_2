#include "Duque.hpp"

Duque::Duque(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false)
    : Aposta(nome_do_jogador, valor, cabeca){

    apostas_ = apostas;

}

Duque::~Duque() {}

        //GETTERS
std::vector<int> Duque::apostas() {

    return apostas_;

}