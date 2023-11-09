#pragma once

#include <vector>

#include "Terno.hpp"

class TernoDezena : public Terno {

    private:
        const static float ganho_ = GANHO_TERNO_DEZENA; //Ganho de 300 para uma classe TernoDezena
    public:

        //CONSTRUTORES E DESTRUTORES
        TernoDezena(std::string nome_do_jogador, float valor, std::vector<Grupos> apostas, bool cabeca = false); //Construtor de TernoDezena
        ~TernoDezena(); //Destrutor de TernoDezena

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(); //Verificação da vitória com atualização da variavel ganhou
};