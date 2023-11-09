#pragma once

#include "Aposta.hpp"
#include "Grupo.hpp"

class Normal : public Aposta {
    private:

    public:
        Normal(int valor, std::string nome_do_jogador, bool cabeca) : Aposta(valor, nome_do_jogador, cabeca) {
            
        }
        ~Normal();

};
