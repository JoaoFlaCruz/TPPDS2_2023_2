#pragma once

#include <vector>

#include "../Aposta.hpp"

class Normal : public Aposta {

    protected:
        std::vector<int> apostas_[1]; /*Armazena apostas normais*/
    public:

        /*Construtor*/
        Normal(float valor, std::string nome_do_jogador, bool cabeca = false);

        /*Destrutor*/
        ~Normal();

        std::vector<Grupos> apostas(); /*Getter de aposta*/

};
