#pragma once

#include <vector>

#include "Duque.hpp"

class DuqueGrupo : public Duque {

    private:
        const static float ganho_ = GANHO_DUQUE_GRUPO; //Ganho de 18.5 para uma classe DuqueDezena
    public:
        //CONSTRUTORES E DESTRUTORES
        DuqueGrupo(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false); //Construtor de DuqueGrupo
        ~DuqueGrupo(); //Destrutor de DuqueGrupo

        //GETTERS

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        void verificar_vitoria(std::vector<int> resultado); //Verificação da vitória com atualização da variavel ganhou
};