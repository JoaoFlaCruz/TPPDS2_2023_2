#pragma once

#include <vector>

#include "Terno.hpp"

class TernoGrupo : public Terno {

    private:
        const static float ganho_ = GANHO_TERNO_GRUPO; //Ganho de 18.5 para uma classe TernoDezena
    public:
        //CONSTRUTORES E DESTRUTORES
        TernoGrupo(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false); //Construtor de TernoGrupo
        ~TernoGrupo(); //Destrutor de TernoGrupo

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(std::vector<int> resultado); //Verificação da vitória com atualização da variavel ganhou
};