#pragma once

#include <vector>

#include "Duque.hpp"

class DuqueDezena : public Duque {

    private:
        const static int ganho_ = GANHO_DUQUE_DEZENA; //Ganho de 300 para uma classe DuqueDezena
    public:

        //CONSTRUTORES E DESTRUTORES
        DuqueDezena(std::string nome_do_jogador, float valor, std::vector<Grupos> apostas, bool cabeca = false); //Construtor de DuqueDezena
        ~DuqueDezena(); //Destrutor de DuqueDezena

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(); //Verificação da vitória com atualização da variavel ganhou
};