#pragma once

#include <vector>

#include "Aposta.hpp"
#include "Grupos.hpp"

class Normal : public Aposta {

    private:
        std::vector<Grupos> apostas_[1]; /*Armazena apostas normais*/
    public:

        /*Construtor*/
        Normal(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<Grupos> apostas); 
        /*Destrutor*/
        ~Normal();


        std::vector<Grupos> apostas(); /*Getter de aposta*/ 


        void verificar_vitoria(); /*Verificação da vitória com atualização da variavel ganho*/ 
};
