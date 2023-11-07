#pragma once

#include <string>

#include "Carteira.hpp"

class Jogador{
    private:
        std::string apelido_;
        Carteira carteira_;
    public:
        void recebe_dinheiro(float valor);
        void retira_dinheiro(float valor);
        std::string apelido();
        Carteira carteira();
};