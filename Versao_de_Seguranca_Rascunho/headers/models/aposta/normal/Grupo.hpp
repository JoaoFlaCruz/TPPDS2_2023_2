#pragma once

#include <vector>

#include "Normal.hpp"

class Grupo : public Normal {

    private:

    public:
        /*Construtor*/
        Grupo(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas);

        /*Destrutor*/
        ~Grupo();

        void verificar_vitoria(std::array<int, 5> resultado); /*Verificação da vitória com atualização da variavel ganho*/
        bool operator==(Aposta outra) override;
};
