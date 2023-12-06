#pragma once

#include <vector>

#include "Terno.hpp"

class TernoGrupo : public Terno {

    private:
        const float ganho_ = GANHO_TERNO_GRUPO; //Ganho de 18.5 para uma classe TernoDezena
    public:
        //CONSTRUTORES E DESTRUTORES
        TernoGrupo(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 3> apostas); //Construtor de TernoGrupo
        ~TernoGrupo(); //Destrutor de TernoGrupo

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(std::array<int, 5> resultado); //Verificação da vitória com atualização da variavel ganhou
        bool operator==(Aposta outra) override;
};
