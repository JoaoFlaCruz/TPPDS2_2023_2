#pragma once

#include <vector>

#include "Aposta.hpp"
#include "Grupos.hpp"

class Terno : public Aposta {

    private:
        std::vector<Grupos> apostas_[3]; //Guarda as apostas do Terno
    public:

        //CONSTRUTORES E DESTRUTORES
        Terno(std::string nome_do_jogador, float valor, std::vector<Grupos> apostas, bool cabeca = false); //Construtor de Terno
        ~Terno(); //Destrutor de Terno

        //GETTERS
        std::vector<Grupos> apostas(); //Getter para o atributo apostas

        //MÉTODOS CONCRETOS

        //MÉTODOS ABSTRATOS
        virtual void verificar_vitoria(); //Verificação da vitória com atualização da variavel ganhou
};