#pragma once

#include "Aposta.hpp"
#include "Grupo.hpp"

class Centena : public Aposta {
    private:

    public:
        Centena(int valor, std::string nome_do_jogador, bool cabeca) : Normal(valor, nome_do_jogador, cabeca) {

        }
        ~Centena();

};