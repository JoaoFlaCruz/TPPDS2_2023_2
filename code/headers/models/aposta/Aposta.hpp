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

enum Grupos {

    AVESTRUZ = 1,
    AGUIA = 2,
    BURRO = 3,
    BORBOLETA = 4,
    CACHORRO = 5,
    CABRA = 6,
    CARNEIRO = 7,
    CAMELO = 8,
    COBRA = 9,
    COELHO = 10,
    CAVALO = 11,
    ELEFANTE = 12,
    GALO = 13,
    GATO = 14,
    JACARE = 15,
    LEAO = 16,
    MACACAO = 17,
    PORCO = 18,
    PAVAO = 19,
    PERU = 20,
    TOURO = 21,
    TIGRE = 22,
    URSO = 23,
    VEADO = 24,
    VACA = 25

};

struct ValorDaApostaNegativo {};
struct ValorDaApostaMuitoAlto {};
struct ValorDasApostasIgual {};

class Aposta{

    protected:
        const float ganho_ = GANHO_NULO; //Ganho nulo para uma classe Aposta abstrata
        bool ganhou_ = false; //Verifica se a aposta é ganhadora
        float valor_; //Valor apostado pelo jogador
        bool cabeca_; //Verificação se a aposta é na cabeça
        std::string nome_do_jogador_; //Nome do jogador que apostou
    public:
        // CONSTRUTORES E DESTRUTORES
        Aposta(std::string nome_do_jogador, float valor, bool cabeca = false); //Construtor
        ~Aposta(); //Destrutor

        //GETTERS
        float ganho(); //Getter para o atributo ganho
        float valor(); //Getter para o atributo valor
        bool cabeca(); //Getter para o atributo cabeça
        std::string nome_do_jogador(); //Getter para o atributo nome_do_jogador
        bool ganhou(); //Getter para o atributo ganhou

        //MÉTODOS CONCRETOS
        float calcular_ganho(); //Calculo do dinheiro ganhado com base no valor, no ganho e na cabeça

        //MÉTODOS ABSTRATOS
        virtual void verificar_vitoria(std::vector<int> resultado); //Verificação da vitória com atualização da variavel ganhou

};

