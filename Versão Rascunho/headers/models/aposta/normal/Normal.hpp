#pragma once

#include <vector>
//Corrigir tramanetos, endereçamento e testar
#include "../Aposta.hpp"

class Normal : public Aposta {

    protected:
        std::vector<int> apostas_; /*Armazena apostas normais*/
    public:

        /*Construtor*/
        Normal(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 1> apostas);

        /*Destrutor*/
        ~Normal();

        std::vector<int> apostas(); /*Getter de aposta*/
};
