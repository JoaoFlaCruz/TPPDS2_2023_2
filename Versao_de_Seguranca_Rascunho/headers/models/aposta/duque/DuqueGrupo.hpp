#pragma once

#include <vector>

#include "Duque.hpp"

class DuqueGrupo : public Duque {

    private:
        const float ganho_ = GANHO_DUQUE_GRUPO; //Ganho de 18.5 para uma classe DuqueDezena
    public:
        //CONSTRUTORES E DESTRUTORES
        DuqueGrupo(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas); //Construtor de DuqueGrupo
        ~DuqueGrupo(); //Destrutor de DuqueGrupo

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(std::array<int, 5> resultado); //Verificação da vitória com atualização da variavel ganhou
        bool operator==(Aposta outra) override;
};
