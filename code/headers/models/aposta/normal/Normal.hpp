#pragma once

#include <vector>

#include "Aposta.hpp"
#include "Grupo.hpp"

class Normal : public Aposta {

    protected:
        std::vector<Grupos> apostas_[1]; /*Armazena apostas normais*/
    public:

        /*Construtor*/
        Normal(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<int> apostas);
        /*Destrutor*/
        ~Normal();


        std::vector<Grupos> apostas(); /*Getter de aposta*/


        void verificar_vitoria(std::vector<int> resultado); /*Verificação da vitória com atualização da variavel ganho*/
};
