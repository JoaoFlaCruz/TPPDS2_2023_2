#pragma once

#include <vector>

#include "Aposta.hpp"
#include "Grupos.hpp"

class Duque : public Aposta {

    private:
        std::vector<Grupos> apostas_[2]; //Guarda as apostas do Duque
    public:

        //CONSTRUTORES E DESTRUTORES
        Duque(std::string nome_do_jogador, float valor, std::vector<Grupos> apostas, bool cabeca = false); //Construtor de Duque
        ~Duque(); //Destrutor de Duque

        //GETTERS
        std::vector<Grupos> apostas(); //Getter para o atributo apostas

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        virtual void verificar_vitoria(); //Verificação da vitória com atualização da variavel ganhou
};