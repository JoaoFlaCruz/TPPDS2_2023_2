#pragma once

#include <vector>

#include "Normal.hpp"

class Centena : public Normal {

    private:

     const static float ganho_ = GANHO_CENTENA;
     
    public:
        /*Construtor*/
        Centena(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<Grupos> apostas); 
        /*Destrutor*/
        ~Centena();

        void verificar_vitoria(); /*Verificação da vitória com atualização da variavel ganho*/ 
};