#pragma once

#include "Aposta.hpp"
#include "Grupo.hpp"

class Dezena : public Aposta {
    private:

    public:
        Dezena(int valor, std::string nome_do_jogador, bool cabeca) : Normal(valor, nome_do_jogador, cabeca) {
            
        }
        ~Dezena();

};