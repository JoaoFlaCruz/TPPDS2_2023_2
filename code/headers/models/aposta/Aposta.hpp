#pragma once

#include <string>

#define GANHO_NULO 0
#define GANHO_GRUPO 18
#define GANHO_DEZENA 60
#define GANHO_CENTENA 600
#define GANHO_MILHAR 4000
#define GANHO_DUQUE_GRUPO 18.5
#define GANHO_DUQUE_DEZENA 300
#define GANHO_TERNO_GRUPO 130
#define GANHO_TERNO_DEZENA 3000

class Aposta{

    private:
        const static int ganho_ = GANHO_NULO; //Ganho nulo para uma classe Aposta abstrata
        bool ganhou_ = false; //Verifica se a aposta é ganhadora
        float valor_; //Valor apostado pelo jogador
        bool cabeca_; //Verificação se a aposta é na cabeça
        std::string nome_do_jogador_; //Nome do jogador que apostou
    public:
        // CONSTRUTORES E DESTRUTORES
        Aposta(std::string nome_do_jogador, float valor, bool cabeca = false); //Construtor
        ~Aposta(); //Destrutor

        //GETTERS
        int ganho(); //Getter para o atributo ganho
        float valor(); //Getter para o atributo valor
        bool cabeca(); //Getter para o atributo cabeça
        std::string nome_do_jogador(); //Getter para o atributo nome_do_jogador
        bool ganhou(); //Getter para o atributo ganhou

        //MÉTODOS CONCRETOS
        float calcular_ganho(); //Calculo do dinheiro ganhado com base no valor, no ganho e na cabeça

        //MÉTODOS ABSTRATOS
        virtual void verificar_vitoria(); //Verificação da vitória com atualização da variavel ganhou

};