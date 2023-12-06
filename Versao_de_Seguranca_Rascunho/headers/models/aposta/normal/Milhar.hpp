#pragma once

#include <vector>

#include "Normal.hpp"

class Milhar : public Normal {

    private:

    public:

        /*Construtor*/
        Milhar(float valor, std::string nome_do_jogador, bool cabeca, std::array<int, 1> apostas);
        /*Destrutor*/
        ~Milhar();


        void verificar_vitoria(std::array<int, 5> resultado); //Verificação da vitória com atualização da variavel ganhou
        bool operator==(Aposta outra) override;
};
