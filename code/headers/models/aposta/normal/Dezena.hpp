#pragma once

#include <vector>

#include "Normal.hpp"

class Dezena : public Normal {

    private:

    public:
        /*Construtor*/
        Dezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 1> apostas);

        /*Destrutor*/
        ~Dezena();

        void verificar_vitoria(std::array<int, 5> resultado); /*Verificação da vitória com atualização da variavel ganho*/
        bool operator==(Aposta outra) override;
};
