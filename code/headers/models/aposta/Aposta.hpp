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
        float valor_;
        bool cabeca_;
        std::string nome_do_jogador_;
    public:
        Aposta(std::string nome_do_jogador, float valor, bool cabeca = false);
        ~Aposta();
        int ganho();
        float valor();
        bool cabeca();
        std::string nome_do_jogador();
        float calcular_ganho();
        virtual bool verificar_vitoria();

};