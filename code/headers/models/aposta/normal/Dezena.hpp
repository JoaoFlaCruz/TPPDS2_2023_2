#pragma once

#include <vector>

#include "Normal.hpp"

class Dezena : public Normal {

    private:

    public:
        /*Construtor*/
        Dezena(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<int> apostas);
        /*Destrutor*/
        ~Dezena();

        void verificar_vitoria(std::vector<int> resultado); /*Verificação da vitória com atualização da variavel ganho*/
};