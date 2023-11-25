#pragma once

#include <vector>

#include "Duque.hpp"

class DuqueDezena : public Duque {

    private:
        const float ganho_ = GANHO_DUQUE_DEZENA; //Ganho de 300 para uma classe DuqueDezena
    public:

        //CONSTRUTORES E DESTRUTORES
        DuqueDezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 2> apostas); //Construtor de DuqueDezena
        ~DuqueDezena(); //Destrutor de DuqueDezena

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(std::array<int, 5> resultado); //Verificação da vitória com atualização da variavel ganhou
        bool operator==(Aposta outra) override;
};
