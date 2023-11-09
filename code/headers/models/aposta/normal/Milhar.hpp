#pragma once

#include <vector>

#include "Normal.hpp"

class Milhar : public Normal {
    
    private:

    public:

        /*Construtor*/
        Milhar(float valor, std::string nome_do_jogador, bool cabeca = false, std::vector<Grupos> apostas); 
        /*Destrutor*/
        ~Milhar();


        void verificar_vitoria(); //Verificação da vitória com atualização da variavel ganhou
};