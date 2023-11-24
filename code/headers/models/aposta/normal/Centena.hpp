#pragma once

#include <vector>

#include "Normal.hpp"

class Centena : public Normal {

    private:

     const static float ganho_ = GANHO_CENTENA;

    public:
        /*Construtor*/
        Centena(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<int> apostas);
        /*Destrutor*/
        ~Centena();

        void verificar_vitoria(std::vector<int> resultado); /*Verificação da vitória com atualização da variavel ganho*/
};