#pragma once

#include <vector>
//Corrigir tramanetos, endereçamento e testar
#include "../Aposta.hpp"
struct ValorDaApostaNegativo{
    int valor_negativo;
};
struct ValorDaApostaMuitoAlto{
    int valor_alto; 
};
class Normal : public Aposta {

    protected:
        std::vector<int> apostas_[1]; /*Armazena apostas normais*/
    public:

        /*Construtor*/
        Normal(float valor, std::string nome_do_jogador, bool cabeca = false);

        /*Destrutor*/
        ~Normal();

        std::vector<Grupos> apostas(); /*Getter de aposta*/

};
