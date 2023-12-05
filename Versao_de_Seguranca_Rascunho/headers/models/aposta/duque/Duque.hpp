#pragma once

#include <array>
#include "../Aposta.hpp"

class Duque : public Aposta {

    protected:
        std::vector<int> apostas_; //Guarda as apostas do Duque
    public:

        //CONSTRUTORES E DESTRUTORES
        Duque(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas); //Construtor de Duque

        ~Duque(); //Destrutor de Duque

        //GETTERS
        std::vector<int> apostas(); //Getter para o atributo apostas

};
