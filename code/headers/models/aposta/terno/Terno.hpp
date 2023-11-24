#pragma once

#include <vector>

#include "Aposta.hpp"

class Terno : public Aposta {

    protected:
        std::vector<int> apostas_[3]; //Guarda as apostas do Terno
    public:

        //CONSTRUTORES E DESTRUTORES
        Terno(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false); //Construtor de Terno
        ~Terno(); //Destrutor de Terno

        //GETTERS
        std::vector<int> apostas(); //Getter para o atributo apostas

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        virtual void verificar_vitoria(std::vector<int> resultado); //Verificação da vitória com atualização da variavel ganhou
};