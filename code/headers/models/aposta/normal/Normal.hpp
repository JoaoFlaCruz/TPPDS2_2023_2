/**
 * @file Normal.hpp
 * @brief Definição da classe Normal, derivada da classe Aposta.
 * @version 1.0
 * @date 2023-12-05
 */

#pragma once

#include <vector>
#include "../Aposta.hpp"

/**
 * @brief Classe que representa uma aposta do tipo Normal.
 */
class Normal : public Aposta {
protected:
    std::vector<int> apostas_; ///< Armazena as apostas normais.

public:
    /**
     * @brief Construtor da classe Normal.
     * @param nome_do_jogador Nome do jogador que fez a aposta.
     * @param valor Valor da aposta.
     * @param cabeca Indica se a aposta é na cabeça.
     * @param apostas Array contendo as apostas normais.
     */
    Normal(std::string nome_do_jogador, float valor, bool cabeca, std::array<int, 1> apostas);

    /**
     * @brief Destrutor da classe Normal.
     */
    ~Normal();

    /**
     * @brief Getter para o atributo apostas.
     * @return Vetor contendo as apostas normais.
     */
    std::vector<int> apostas();
};
