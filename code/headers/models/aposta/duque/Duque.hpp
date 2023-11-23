#pragma once

#include <vector>

#include "Aposta.hpp"

class Duque : public Aposta {

    private:
        std::vector<int> apostas_; //Guarda as apostas do Duque
    public:

        //CONSTRUTORES E DESTRUTORES
        Duque(std::string nome_do_jogador, float valor, std::vector<int> apostas, bool cabeca = false); //Construtor de Duque
        ~Duque(); //Destrutor de Duque

        //GETTERS
        std::vector<int> apostas(); //Getter para o atributo apostas

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        virtual void verificar_vitoria(std::vector<int> resultado); //Verificação da vitória com atualização da variavel ganhou
};