/**
 * @file Aposta.hpp
 * @brief Definição da classe abstrata Aposta.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <string>
#include <vector>
#include <array>

#define GANHO_NULO 0
#define GANHO_GRUPO 18
#define GANHO_DEZENA 60
#define GANHO_CENTENA 600
#define GANHO_MILHAR 4000
#define GANHO_DUQUE_GRUPO 18.5
#define GANHO_DUQUE_DEZENA 300
#define GANHO_TERNO_GRUPO 130
#define GANHO_TERNO_DEZENA 3000

/**
 * @brief Enumeração dos Grupos para apostas específicas.
 */
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

/**
 * @brief Estrutura para representar um erro de valor de aposta negativo.
 */
struct ValorDaApostaNegativo {
    float valor;
};

/**
 * @brief Estrutura para representar um erro de número de aposta negativo.
 */
struct NumeroDaApostaNegativo {
    int numeros;
};

/**
 * @brief Estrutura para representar um erro de número de aposta muito alto.
 */
struct NumeroDaApostaMuitoAlto {
    int numeros;
};

/**
 * @brief Estrutura para representar um erro de números iguais em apostas distintas.
 */
struct NumerosDasApostasIguais {
    int numero1;
    int numero2;
};

/**
 * @brief Classe abstrata que representa uma aposta.
 */
class Aposta {
protected:
    std::string nome_do_jogador_; ///< Nome do jogador que apostou.
    float valor_; ///< Valor apostado pelo jogador.
    const float ganho_ = GANHO_NULO; ///< Ganho nulo para uma classe Aposta abstrata.
    bool ganhou_ = false; ///< Verifica se a aposta é ganhadora.
    bool cabeca_; ///< Verificação se a aposta é na cabeça.
    std::vector<int> apostas_; ///< Vetor contendo as apostas.

public:
    /**
     * @brief Construtor da classe Aposta.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     */
    Aposta(std::string nome_do_jogador, float valor, bool cabeca);

    /**
     * @brief Destrutor da classe Aposta.
     */
    ~Aposta();

    /**
     * @brief Getter para o atributo ganho.
     * @return O valor do ganho associado à aposta.
     */
    float ganho();

    /**
     * @brief Getter para o atributo valor.
     * @return O valor da aposta.
     */
    float valor();

    /**
     * @brief Getter para o atributo cabeça.
     * @return True se a aposta for na cabeça, false caso contrário.
     */
    bool cabeca();

    /**
     * @brief Getter para o atributo nome_do_jogador.
     * @return O nome do jogador que fez a aposta.
     */
    std::string nome_do_jogador();

    /**
     * @brief Getter para o atributo ganhou.
     * @return True se a aposta for ganhadora, false caso contrário.
     */
    bool ganhou();

    /**
     * @brief Getter para o atributo apostas.
     * @return O vetor contendo as apostas.
     */
    std::vector<int> apostas();

    /**
     * @brief Método concreto para calcular o ganho com base no valor, no ganho e na cabeça.
     * @return O valor do ganho calculado.
     */
    float calcular_ganho();

    /**
     * @brief Método abstrato para verificar a vitória com base no resultado e atualizar a variável "ganhou".
     * @param resultado Array contendo o resultado do jogo.
     */
    virtual void verificar_vitoria(std::array<int, 5> resultado);

    /**
     * @brief Método abstrato para verificar se uma aposta é igual a outra.
     * @param outra A outra aposta a ser comparada.
     * @return True se as apostas forem iguais, false caso contrário.
     */
    virtual bool operator==(Aposta outra);
};
