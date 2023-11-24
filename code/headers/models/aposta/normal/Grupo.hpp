#pragma once

#include <vector>

#include "Normal.hpp"

class Grupo : public Normal {

    private:

    public:
        /*Construtor*/
        Grupo(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<int> apostas);
        /*Destrutor*/
        ~Grupo();

        void verificar_vitoria(std::vector<int> resultado); /*Verificação da vitória com atualização da variavel ganho*/
};