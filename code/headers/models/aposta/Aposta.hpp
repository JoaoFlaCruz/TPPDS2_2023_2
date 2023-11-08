#pragma once

#include "Jogador.hpp"

#define GANHO_GRUPO 18
#define GANHO_DEZENA 60
#define GANHO_CENTENA 600
#define GANHO_MILHAR 4000
#define GANHO_DUQUE_GRUPO 18.5
#define GANHO_DUQUE_DEZENA 300
#define GANHO_TERNO_GRUPO 130
#define GANHO_TERNO_DEZENA 3000

class Aposta{

    private:
        int valor_;
        int ganho_;
        bool cabeca_;
        std::string nome_do_jogador_;
    public:
        Aposta();
};