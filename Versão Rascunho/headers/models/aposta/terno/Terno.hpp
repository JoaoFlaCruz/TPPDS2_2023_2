#pragma once

#include <array>

#include "../Aposta.hpp"

class Terno : public Aposta {

    protected:
        std::vector<int> apostas_; //Guarda as apostas do Terno
    public:

        //CONSTRUTORES E DESTRUTORES
        Terno(std::string nome_do_jogador, float valor, bool cabeca, std::array<int,3> apostas); //Construtor de Terno

        ~Terno(); //Destrutor de Terno

        //GETTERS
        std::vector<int> apostas(); //Getter para o atributo apostas

};
