#pragma once

#include <vector>

#include "Normal.hpp"

class Centena : public Normal {

    private:

     const float ganho_ = GANHO_CENTENA;

    public:
        /*Construtor*/
        Centena(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas);

        /*Destrutor*/
        ~Centena();

        void verificar_vitoria(std::array<int, 5> resultado); /*Verificação da vitória com atualização da variavel ganho*/
        bool operator==(Aposta outra) override;
};
