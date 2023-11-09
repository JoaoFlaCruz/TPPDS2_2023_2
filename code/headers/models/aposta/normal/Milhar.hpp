#pragma once

#include "Aposta.hpp"
#include "Grupo.hpp"

class Milhar : public Aposta {
    private:

    public:
        Milhar(int valor, std::string nome_do_jogador, bool cabeca) : Normal(valor, nome_do_jogador, cabeca) {

        }
        ~Milhar();

};