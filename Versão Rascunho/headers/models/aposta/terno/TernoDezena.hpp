#pragma once

#include <vector>

#include "Terno.hpp"

class TernoDezena : public Terno {

    private:
        const float ganho_ = GANHO_TERNO_DEZENA; //Ganho de 300 para uma classe TernoDezena
    public:

        //CONSTRUTORES E DESTRUTORES
        TernoDezena(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 3> apostas); //Construtor de TernoDezena
        ~TernoDezena(); //Destrutor de TernoDezena

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(std::array<int, 5> resultado); //Verificação da vitória com atualização da variavel ganhou
        bool operator==(Aposta outra) override;
};
