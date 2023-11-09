#pragma once

#include "Aposta.hpp"
#include "Grupo.hpp"

class Grupo : public Aposta {
    private:

    public:
        Grupo(int valor, std::string nome_do_jogador, bool cabeca) : Normal(valor, nome_do_jogador, cabeca) {
            
        }
        ~Grupo();

};